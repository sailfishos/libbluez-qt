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
	if(index.row() < 0) return QVariant(); ///this is retarded but it has to be done.

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
	return NULL;
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
		deviceCreated(item);
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
	BluetoothDevice* device = new BluetoothDevice(devicepath,this);

	connect(device,SIGNAL(propertyChanged(QString,QVariant)),this,SLOT(devicePropertyChanged(QString,QVariant)));

	beginInsertRows(QModelIndex(),m_devices.size()+1,m_devices.size()+1);
	m_devices.append(device);
	endInsertRows();
}

void BluetoothDevicesModel::deviceRemoved(QDBusObjectPath devicepath)
{
	for(int i=0; i<m_devices.size(); i++)
	{

		if(m_devices[i]->path() == devicepath.path())
		{
			beginRemoveRows(QModelIndex(), i, i);
			m_devices[i]->deleteLater();
			m_devices.removeAt(i);
			endRemoveRows();
		}
	}
}

void BluetoothDevicesModel::devicePropertyChanged(QString name, QVariant value)
{
	if(name == "Paired" && value.toBool() == true)
	{
		qDebug()<<"device property changed: "<<name<<" "<<value;
		BluetoothDevice* device = qobject_cast<BluetoothDevice*>(sender());
		emit devicePaired(device);
	}
}
