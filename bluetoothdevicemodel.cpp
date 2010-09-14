#include "bluetoothdevicemodel.h"

BluetoothDevicesModel::BluetoothDevicesModel(QObject *parent) :
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

int BluetoothDevicesModel::rowCount(const QModelIndex &) const
{
	return m_devices.size();
}

QVariant BluetoothDevicesModel::data(const QModelIndex &index, int role) const
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

QString BluetoothDevicesModel::devicePath(QString devicename)
{
	foreach(BluetoothDevice* device, m_devices)
	{
		if(device->name() == devicename)
			return device->path();
	}
	return "";
}

BluetoothDevice* BluetoothDevicesModel::device(QString path)
{
	foreach(BluetoothDevice* device, m_devices)
	{
		if(device->path() == path)
			return device;
	}
}

void BluetoothDevicesModel::adapterAdded(QDBusObjectPath path)
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
		SLOT(deviceRemoved(QDBusObjectPath)));

	connect(adapter,
		SIGNAL(DeviceCreated(QDBusObjectPath)),
		this,
		SLOT(deviceCreated(QDBusObjectPath)));

	QList<QDBusObjectPath> list = adapter->ListDevices();
	foreach(QDBusObjectPath item, list)
	{
		m_devices.append(new BluetoothDevice(item));
	}
}

void BluetoothDevicesModel::adapterRemoved(QDBusObjectPath)
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

void BluetoothDevicesModel::deviceCreated(QDBusObjectPath devicepath)
{

	beginInsertRows(QModelIndex(),m_devices.size()+1,m_devices.size()+1);
	m_devices.append(new BluetoothDevice(devicepath));
	endInsertRows();
}

void BluetoothDevicesModel::deviceRemoved(QDBusObjectPath devicepath)
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
