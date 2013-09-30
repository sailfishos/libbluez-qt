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

#include "bluetoothdevice.h"
#include "asyncagent.h"

AsyncAgent::AsyncAgent(QString path, QObject *parent)
    : BluetoothBaseAgent(path, parent)
    , m_deviceToPair(0)
    , m_connection(QDBusConnection::systemBus())
    , m_pendingAction(InvalidAction)
    , m_confirmationRequestPasskey(0)
{
}

void AsyncAgent::authorize(OrgBluezDeviceInterface &device, QString uuid)
{
    qDebug() << Q_FUNC_INFO;
    m_pendingAction = AuthorizeAction;
    m_requestAuthorizeUuid = uuid;
    initializeDelayedReply(device);
}

void AsyncAgent::requestConfirmation(OrgBluezDeviceInterface &device, uint key)
{
    qDebug() << Q_FUNC_INFO;
    m_pendingAction = RequestConfirmationAction;
    m_confirmationRequestPasskey = key;
    initializeDelayedReply(device);
}

uint AsyncAgent::requestPasskey(OrgBluezDeviceInterface &device)
{
    qDebug() << Q_FUNC_INFO;
    m_pendingAction = RequestPasskeyAction;
    initializeDelayedReply(device);
    return 0;
}

QString AsyncAgent::requestPidCode(OrgBluezDeviceInterface &device)
{
    qDebug() << Q_FUNC_INFO;
    m_pendingAction = RequestPidCodeAction;
    initializeDelayedReply(device);
    return QString();
}

void AsyncAgent::release()
{
    qDebug() << Q_FUNC_INFO;
    if (!QMetaObject::invokeMethod(parent(), "release", Qt::QueuedConnection))
        qDebug("sending relay signal failed!!!");
}

void AsyncAgent::replyRequestConfirmation(bool confirmed)
{
    if (!confirmed) {
        qDebug("rejecting");
        QDBusMessage reply = m_pendingMessage.createErrorReply("org.bluez.Error.Rejected", "The request was rejected");
        m_connection.send(reply);
    } else {
        qDebug("accepting");
        QDBusMessage reply = m_pendingMessage.createReply();
        m_connection.send(reply);
    }
}

void AsyncAgent::replyPasskey(uint passkey)
{
    QDBusMessage reply = m_pendingMessage.createReply(passkey);
    m_connection.send(reply);
}

void AsyncAgent::replyRequestPidCode(QString pidCode)
{
    QDBusMessage reply = m_pendingMessage.createReply(pidCode);
    m_connection.send(reply);
}

void AsyncAgent::replyRequestAuthorization(bool authorize)
{
    if (authorize) {
        QDBusMessage reply = m_pendingMessage.createReply();
        m_connection.send(reply);
    } else {
        QDBusMessage reply = m_pendingMessage.createErrorReply("org.bluez.Error.Rejected", "Device not authorized");
        m_connection.send(reply);
    }
}

void AsyncAgent::getDevicePropertiesFinished(QDBusPendingCallWatcher *call)
{
    QDBusPendingReply<QVariantMap> reply = *call;
    QVariantMap deviceProperties = reply.value();
    switch (m_pendingAction) {
    case InvalidAction:
        qWarning() << Q_FUNC_INFO << "called with invalid action";
        break;
    case AuthorizeAction:
        notifyAuthorizeRequest(deviceProperties);
        break;
    case RequestConfirmationAction:
        notifyConfirmationRequest(deviceProperties);
        break;
    case RequestPasskeyAction:
        notifyPasskeyRequest(deviceProperties);
        break;
    case RequestPidCodeAction:
        notifyPidCodeRequest(deviceProperties);
        break;
    }
    m_pendingAction = InvalidAction;
    call->deleteLater();
}

void AsyncAgent::initializeDelayedReply(OrgBluezDeviceInterface &device)
{
    setDelayedReply(true);
    m_pendingMessage = message();
    m_connection = connection();
    m_deviceToPair = new BluetoothDevice(QDBusObjectPath(device.path()), this);

    QDBusPendingReply<QVariantMap> result = device.GetProperties();
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(result, this);
    connect(watcher, SIGNAL(finished(QDBusPendingCallWatcher*)),
                     SLOT(getDevicePropertiesFinished(QDBusPendingCallWatcher*)));
}

void AsyncAgent::notifyAuthorizeRequest(const QVariantMap &deviceProperties)
{
    if (sendErrorIfNoProperties(deviceProperties)) {
        return;
    }
    bool paired = deviceProperties["Paired"].toBool();
    if (!paired) {
        QDBusMessage reply = m_pendingMessage.createErrorReply("org.bluez.Error.Rejected", "Remote device is not paired");
        m_connection.send(reply);
        return;
    }
    bool trusted = deviceProperties["Trusted"].toBool();
    if (trusted) {
        QDBusMessage reply = m_pendingMessage.createReply();
        QDBusConnection::systemBus().send(reply);
    } else {
        QMetaObject::invokeMethod(parent(),
                                  "requestAuthorization",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, deviceProperties["Address"].toString()),
                                  Q_ARG(uint, deviceProperties["Class"].toUInt()),
                                  Q_ARG(QString, deviceProperties["Alias"].toString()),
                                  Q_ARG(QString, m_requestAuthorizeUuid));
    }
}

void AsyncAgent::notifyConfirmationRequest(const QVariantMap &deviceProperties)
{
    if (sendErrorIfNoProperties(deviceProperties)) {
        return;
    }
    QMetaObject::invokeMethod(parent(),
                              "requestConfirmation",
                              Qt::QueuedConnection,
                              Q_ARG(QString, deviceProperties["Address"].toString()),
                              Q_ARG(uint, deviceProperties["Class"].toUInt()),
                              Q_ARG(QString, deviceProperties["Alias"].toString()),
                              Q_ARG(uint, m_confirmationRequestPasskey));
}

void AsyncAgent::notifyPasskeyRequest(const QVariantMap &deviceProperties)
{
    if (sendErrorIfNoProperties(deviceProperties)) {
        return;
    }
    QMetaObject::invokeMethod(parent(),
                              "requestPasskey",
                              Qt::QueuedConnection,
                              Q_ARG(QString, deviceProperties["Address"].toString()),
                              Q_ARG(uint, deviceProperties["Class"].toUInt()),
                              Q_ARG(QString, deviceProperties["Alias"].toString()));
}

void AsyncAgent::notifyPidCodeRequest(const QVariantMap &deviceProperties)
{
    if (sendErrorIfNoProperties(deviceProperties)) {
        return;
    }
    QMetaObject::invokeMethod(parent(),
                              "requestPidCode",
                              Qt::QueuedConnection,
                              Q_ARG(QString, deviceProperties["Address"].toString()),
                              Q_ARG(uint, deviceProperties["Class"].toUInt()),
                              Q_ARG(QString, deviceProperties["Alias"].toString()));
}

bool AsyncAgent::sendErrorIfNoProperties(const QVariantMap &deviceProperties)
{
    if (deviceProperties.isEmpty()) {
        QDBusMessage reply = m_pendingMessage.createErrorReply("org.bluez.Error.Rejected", "Unable to read remote device information");
        m_connection.send(reply);
        return true;
    }
    return false;
}
