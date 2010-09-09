#include "bluetoothdevicemodel.h"

BluetoothDeviceModel::BluetoothDeviceModel(QObject *parent) :
	QAbstractListModel(parent), adapter(NULL)
{
	manager = new OrgBluezManagerInterface(
			"org.bluez",
			"/", QDBusConnection::systemBus(), this);

	connect(manager,SIGNAL(AdapterAdded(QDBusObjectPath)),this,SLOT(adapterAdded(QDBusObjectPath)));
	connect(manager,SIGNAL(AdapterRemoved(QDBusObjectPath)),this,SLOT(adapterRemoved(QDBusObjectPath)));
	adapterAdded(QDBusObjectPath());

	QHash<int, QByteArray> roles;
	roles[name]="name";
	roles[address]="address";
	roles[path]="path";

	setRoleNames(roles);
}

int BluetoothDeviceModel::rowCount(const QModelIndex &parent) const
{
	return m_devices.size();
}

QVariant BluetoothDeviceModel::data(const QModelIndex &index, int role) const
{
	if(role == name)
	{
		QString rowData;
		if(index.row() < m_devices.size())
		{
			rowData = m_devices[index.row()]->name();
		}
		return QVariant(rowData);
	}
	else if(role == address)
	{
		QString rowData;
		if(index.row() < m_devices.size())
		{
			rowData = m_devices[index.row()]->address();
		}
		return QVariant(rowData);
	}
	else if(role == path)
	{
		QString rowData;
		if(index.row() < m_devices.size())
		{
			rowData = m_devices[index.row()]->path();
		}
		return QVariant(rowData);
	}
	return QVariant();
}

void BluetoothDeviceModel::adapterAdded(QDBusObjectPath path)
{
	if(adapter && adapter->path() == path.path()) return;

	QDBusObjectPath adapterpath = manager->DefaultAdapter();

	if(adapterpath.path() == "")
		return;

	adapter = new OrgBluezAdapterInterface(
			"org.bluez",
			adapterpath.path(),
			QDBusConnection::systemBus(), this);

	connect(adapter,
		SIGNAL(DeviceRemoved(QDBusObjectPath)),
		this,
		SIGNAL(deviceRemoved(QDBusObjectPath)));

	connect(adapter,
		SIGNAL(DeviceCreated(QDBusObjectPath)),
		this,
		SIGNAL(deviceCreated(QDBusObjectPath)));

	QList<QDBusObjectPath> list = adapter->ListDevices();
	foreach(QDBusObjectPath item, list)
	{
		m_devices.append(new BluetoothDevice(item));
	}
}

void BluetoothDeviceModel::adapterRemoved(QDBusObjectPath)
{
	QDBusObjectPath adapterpath = manager->DefaultAdapter();

	if(adapterpath.path() == "")
	{
		beginRemoveRows(QModelIndex(), 0, m_devices.size()-1);
		foreach(BluetoothDevice* device, m_devices)
		{
			delete device;
		}
		m_devices.clear();
		endRemoveRows();

		if(adapter) delete adapter;
		return;
	}
}

void BluetoothDeviceModel::deviceCreated(QDBusObjectPath devicepath)
{

	beginInsertRows(QModelIndex(),m_devices.size()+1,m_devices.size()+1);
	m_devices.append(new BluetoothDevice(devicepath));
	endInsertRows();
}

void BluetoothDeviceModel::deviceRemoved(QDBusObjectPath devicepath)
{
	for(int i=0; i<m_devices.size(); i++)
	{

		if(m_devices[i]->path() == devicepath.path())
		{
			beginRemoveRows(QModelIndex(), i, i);
			delete m_devices[i];
			m_devices.removeAt(i);
			endRemoveRows();
		}
	}
}
