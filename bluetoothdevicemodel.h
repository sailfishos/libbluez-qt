#ifndef BLUETOOTHDEVICEMODEL_H
#define BLUETOOTHDEVICEMODEL_H

#include <QAbstractListModel>
#include "bluemanager.h"
#include "blueadapter.h"
#include "bluetoothdevice.h"

class BluetoothDevicesModel : public QAbstractListModel
{
    Q_OBJECT
public:
	explicit BluetoothDevicesModel(QObject *parent = 0);

	enum Role
	{
		name = Qt::UserRole + 1,
		address,
		path
	};

public slots:

	int columnCount(const QModelIndex &) const { return 1; }
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;

	QString devicePath(QString name);

	QList<BluetoothDevice*> devices(){ return m_devices; }

	BluetoothDevice* device(QString path);

private slots:
	void adapterAdded(QDBusObjectPath);
	void adapterRemoved(QDBusObjectPath);
	void deviceCreated(QDBusObjectPath);
	void deviceRemoved(QDBusObjectPath);

	void devicePropertyChanged(QString name, QVariant value);

signals:
	void devicePaired(BluetoothDevice* device);

private:
	OrgBluezManagerInterface *manager;
	OrgBluezAdapterInterface *adapter;
	QList<BluetoothDevice*> m_devices;
};

#endif // BLUETOOTHDEVICEMODEL_H
