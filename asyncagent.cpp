#include "asyncagent.h"

AsyncAgent::AsyncAgent(QString path, QObject *parent) :
		BluetoothBaseAgent(path,parent), m_connection(QDBusConnection::systemBus())
{

}

void AsyncAgent::requestConfirmation(OrgBluezDeviceInterface &device, uint key)
{
	setDelayedReply(true);
	pendingMessage = message();
	m_connection = connection();

	QVariantMap props = device.GetProperties();

	QString alias = props["Alias"].toString();

	QMetaObject::invokeMethod(parent(),"requestConfirmation",
							  Qt::QueuedConnection, Q_ARG(QString, alias), Q_ARG(uint,key));

	return;
}

uint AsyncAgent::requestPasskey(OrgBluezDeviceInterface &device)
{
	qDebug("requestKey");
	setDelayedReply(true);
	pendingMessage = message();
	m_connection = connection();

	QVariantMap props = device.GetProperties();

	QString alias = props["Alias"].toString();

	QMetaObject::invokeMethod(parent(), "requestPasskey", Qt::QueuedConnection, Q_ARG(QString, alias));

	return 0;
}

QString AsyncAgent::requestPidCode(OrgBluezDeviceInterface &device)
{
	setDelayedReply(true);
	pendingMessage = message();
	m_connection = connection();

	QVariantMap props = device.GetProperties();

	QString alias = props["Alias"].toString();

	QMetaObject::invokeMethod(parent(), "requestPidCode", Qt::QueuedConnection, Q_ARG(QString, alias));

	return "";
}


void AsyncAgent::replyRequestConfirmation(bool confirmed)
{
	if(!confirmed)
	{
		reject();
	}
	else
	{
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
