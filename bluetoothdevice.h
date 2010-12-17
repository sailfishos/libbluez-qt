#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

#include <QObject>
#include <QStringList>
#include <bluedevice.h>
/*
#include <audiosource.h>
#include <audiosink.h>
#include <headset.h>
*/
class BluetoothDevice : public QObject
{
    Q_OBJECT	
	Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged);
	Q_PROPERTY(QStringList profiles READ profiles)
	Q_PROPERTY(QString alias READ alias)
	Q_PROPERTY(QString name READ name)
	Q_PROPERTY(QString address READ address)
	Q_PROPERTY(QString icon READ icon)
	Q_PROPERTY(QString path READ path)

public:
	explicit BluetoothDevice(QDBusObjectPath path = QDBusObjectPath(), QObject *parent = 0);

signals:
	void connectedChanged();
	void propertyChanged(QString name, QVariant value);

public slots:
	void unpair();
	void connect(QString profile);
	void disconnect();

	QStringList profiles();
	bool isProfileSupported(QString profile);

	///properties:
	bool connected();
	QString alias();
	QString name();
	QString address();
	QString icon();
	QString path();

private slots:
	void propertyChanged(QString name,QDBusVariant value);

private:
	OrgBluezDeviceInterface *m_device;
};

#endif // BLUETOOTHDEVICE_H
