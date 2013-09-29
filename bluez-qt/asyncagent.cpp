/*  -*- Mode: C++ -*-
 *
 * meego handset bluetooth
 * Copyright © 2010, Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 */

#include <QDBusPendingReply>

#include "asyncagent.h"

AsyncAgent::AsyncAgent(QString path, QObject *parent) :
		BluetoothBaseAgent(path,parent), m_connection(QDBusConnection::systemBus())
{

}

void AsyncAgent::authorize(OrgBluezDeviceInterface &device, QString uuid)
{
    qDebug() << Q_FUNC_INFO;

    QDBusPendingReply<QVariantMap> reply = device.GetProperties();
    reply.waitForFinished();
    QVariantMap props = reply.value();

    bool paired = props.value(QStringLiteral("Paired")).toBool();
    if (!paired) {
        QDBusMessage reply = message().createErrorReply("org.bluez.Error.Rejected", "Remote device is not paired");
        QDBusConnection::systemBus().send(reply);
        return;
    }

    bool trusted = props.value(QStringLiteral("Trusted")).toBool();
    if (!trusted) {
        setDelayedReply(true);
        pendingMessage = message();
        m_connection = connection();
        deviceToPair = new BluetoothDevice(QDBusObjectPath(device.path()), this);

        QMetaObject::invokeMethod(parent(),"requestAuthorization", Qt::QueuedConnection,
                                  Q_ARG(QString, props["Address"].toString()),
                                  Q_ARG(uint, props["Class"].toUInt()),
                                  Q_ARG(QString, props["Alias"].toString()),
                                  Q_ARG(QString, uuid));
    }
}

void AsyncAgent::requestConfirmation(OrgBluezDeviceInterface &device, uint key)
{
	qDebug() << Q_FUNC_INFO;
	setDelayedReply(true);
	pendingMessage = message();
	m_connection = connection();
    deviceToPair = new BluetoothDevice(QDBusObjectPath(device.path()),this);

    QDBusPendingReply<QVariantMap> reply = device.GetProperties();
    reply.waitForFinished();
    QVariantMap props = reply.value();

    QMetaObject::invokeMethod(parent(),"requestConfirmation", Qt::QueuedConnection,
                              Q_ARG(QString, props["Address"].toString()),
                              Q_ARG(uint, props["Class"].toUInt()),
                              Q_ARG(QString, props["Alias"].toString()),
                              Q_ARG(uint, key));
}

uint AsyncAgent::requestPasskey(OrgBluezDeviceInterface &device)
{
	qDebug() << Q_FUNC_INFO;
	setDelayedReply(true);
	pendingMessage = message();
	m_connection = connection();
	deviceToPair = new BluetoothDevice(QDBusObjectPath(device.path()),this);

    QDBusPendingReply<QVariantMap> reply = device.GetProperties();
    reply.waitForFinished();
    QVariantMap props = reply.value();

    QMetaObject::invokeMethod(parent(), "requestPasskey", Qt::QueuedConnection,
                              Q_ARG(QString, props["Address"].toString()),
                              Q_ARG(uint, props["Class"].toUInt()),
                              Q_ARG(QString, props["Alias"].toString()));

	return 0;
}

QString AsyncAgent::requestPidCode(OrgBluezDeviceInterface &device)
{
	qDebug() << Q_FUNC_INFO;
	setDelayedReply(true);
	pendingMessage = message();
	m_connection = connection();
    deviceToPair = new BluetoothDevice(QDBusObjectPath(device.path()),this);

    QDBusPendingReply<QVariantMap> reply = device.GetProperties();
    reply.waitForFinished();
    QVariantMap props = reply.value();

    QMetaObject::invokeMethod(parent(), "requestPidCode", Qt::QueuedConnection,
                              Q_ARG(QString, props["Address"].toString()),
                              Q_ARG(uint, props["Class"].toUInt()),
                              Q_ARG(QString, props["Alias"].toString()));

	return "";
}

void AsyncAgent::release()
{
	qDebug() << Q_FUNC_INFO;
	if (!QMetaObject::invokeMethod(parent(), "release", Qt::QueuedConnection))
		qDebug("sending relay signal failed!!!");
}


void AsyncAgent::replyRequestConfirmation(bool confirmed)
{
	if(!confirmed)
	{
		qDebug("rejecting");
		QDBusMessage reply = pendingMessage.createErrorReply("org.bluez.Error.Rejected", "The request was rejected");
		m_connection.send(reply);
	}
	else
	{
		qDebug("accepting");
		QDBusMessage reply = pendingMessage.createReply();
		m_connection.send(reply);
	}
}

void AsyncAgent::replyPasskey(uint passkey)
{
	QDBusMessage reply = pendingMessage.createReply(passkey);
	m_connection.send(reply);
}

void AsyncAgent::replyRequestPidCode(QString pidCode)
{
	QDBusMessage reply = pendingMessage.createReply(pidCode);
	m_connection.send(reply);
}

void AsyncAgent::replyRequestAuthorization(bool authorize)
{
    if (authorize) {
        QDBusMessage reply = pendingMessage.createReply();
        m_connection.send(reply);
    } else {
        QDBusMessage reply = pendingMessage.createErrorReply("org.bluez.Error.Rejected", "Device not authorized");
        m_connection.send(reply);
    }
}
