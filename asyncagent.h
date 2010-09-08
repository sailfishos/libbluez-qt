#ifndef ASYNCAGENT_H
#define ASYNCAGENT_H

#include "bluetoothbaseagent.h"

class AsyncAgent : public BluetoothBaseAgent
{
    Q_OBJECT
public:
	explicit AsyncAgent(QString path, QObject *parent = 0);

	void requestConfirmation(OrgBluezDeviceInterface &device, uint key);
	uint requestPasskey(OrgBluezDeviceInterface &device);
	QString requestPidCode(OrgBluezDeviceInterface &device);

signals:

public slots:
	void replyRequestConfirmation(bool confirmed);
	void replyPasskey(uint passkey);
	void replyRequestPidCode(QString pidCode);

private:
	QDBusMessage pendingMessage;
	QDBusConnection m_connection;

};

#endif // ASYNCAGENT_H
