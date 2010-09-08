#ifndef BLUETOOTHBASEAGENT_H
#define BLUETOOTHBASEAGENT_H

#include <QObject>
#include <QDBusContext>
#include "bluedevice.h"

class BluetoothBaseAgent: public QObject, public QDBusContext
{
	Q_OBJECT
public:
	BluetoothBaseAgent(QString path="/pairing/agent", QObject *parent=0);
public slots:
	virtual void authorize(OrgBluezDeviceInterface &device, QString);
	virtual void cancel()
	{
		sendErrorReply("org.bluez.Error.Canceled","The request was canceled");
	}
	virtual void confirmModeChange(QString);
	virtual void displayPasskey(OrgBluezDeviceInterface &device, uint key);
	virtual void release();
	virtual void requestConfirmation(OrgBluezDeviceInterface &device, uint key);
	virtual uint requestPasskey(OrgBluezDeviceInterface &device);
	virtual QString requestPidCode(OrgBluezDeviceInterface &device);

	virtual void reject() { sendErrorReply("org.bluez.Error.Rejected", "The request was rejected"); }

	virtual void accept();
	virtual void doReject();
private:
	bool requestAccepted;
};

#endif // BLUETOOTHBASEAGENT_H
