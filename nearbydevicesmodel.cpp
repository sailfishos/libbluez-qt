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

#include "nearbydevicesmodel.h"
#include "bluetoothbaseagent.h"

NearbyDevicesModel::NearbyDevicesModel(QObject *parent) :
	QAbstractListModel(parent), adapter(NULL), agent(NULL)
{
	manager = new OrgBluezManagerInterface(
			"org.bluez",
			"/", QDBusConnection::systemBus(), this);

	connect(manager,SIGNAL(AdapterAdded(QDBusObjectPath)),this,SLOT(adapterAdded(QDBusObjectPath)));
	connect(manager,SIGNAL(AdapterRemoved(QDBusObjectPath)),this,SLOT(adapterRemoved(QDBusObjectPath)));
	adapterAdded(QDBusObjectPath());

	QHash<int,QByteArray> roles;
	roles[NearbyDevicesModelRoles::name]="name";
	roles[NearbyDevicesModelRoles::address]="address";
	setRoleNames(roles);
}


int NearbyDevicesModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return devicepathlist.size();
}

QVariant NearbyDevicesModel::data(const QModelIndex &index, int role) const
{
	if (role == NearbyDevicesModelRoles::name)
	{
		QString rowData;
		if(index.row() < devicepathlist.size())
		{
			rowData = deviceAliasMap[devicepathlist[index.row()]];
		}
		return QVariant(rowData);
	}
	else if (role == NearbyDevicesModelRoles::address)
	{
		QString rowData;
		if(index.row() < devicepathlist.size())
		{
			rowData = devicepathlist[index.row()];
		}
		return QVariant(rowData);
	}
	return QVariant();
}

void NearbyDevicesModel::pair(QString hwaddy)
{

	qDebug()<<"attempting to pair with "<<hwaddy;
	if(!adapter) return;
	agent = new AsyncAgent("/temp/agent",this);

	adapter->CreatePairedDevice(hwaddy,
				   QDBusObjectPath("/temp/agent"),"");

	//qDebug()<<"new object created: "<<object.path();
}

void NearbyDevicesModel::discover(bool start)
{
	if(!adapter) return;

	if(start)
		adapter->StartDiscovery();
	else adapter->StopDiscovery();
}

void NearbyDevicesModel::removeAll(bool)
{
	for(int i=0;i<devicepathlist.size();i++)
	{
		devicepathlist.removeAt(i);
	}
}

void NearbyDevicesModel::replyRequestConfirmation(bool confirmed)
{
	if(agent) agent->replyRequestConfirmation(confirmed);
}

void NearbyDevicesModel::replyPasskey(uint passkey)
{
	if(agent) agent->replyPasskey(passkey);
}

void NearbyDevicesModel::replyRequestPidCode(QString pidCode)
{
	if(agent) agent->replyRequestPidCode(pidCode);
}

void NearbyDevicesModel::deviceCreated(QString hwaddy, QVariantMap properties)
{
	bool found = false;
	foreach(QString path, devicepathlist)
	{
		if(path == hwaddy)
		{
			found=true;
			break;
		}
	}

	if(!found)
	{
		beginInsertRows(QModelIndex(), devicepathlist.size()+1, devicepathlist.size()+1);
		devicepathlist.append(hwaddy);
		deviceAliasMap[hwaddy] = properties["Alias"].toString();
		emit nearbyDeviceFound(devicepathlist.indexOf(hwaddy));
		endInsertRows();
	}
}

void NearbyDevicesModel::deviceRemoved(QString hwaddy)
{
	int i=-1;
	if((i = devicepathlist.indexOf(hwaddy)) >=0)
	{
		beginRemoveRows(QModelIndex(),i,i);
		devicepathlist.removeAt(i);
		emit nearbyDeviceRemoved(i);
		endRemoveRows();
	}

}

void NearbyDevicesModel::adapterAdded(QDBusObjectPath path)
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
		SIGNAL(DeviceFound(QString, QVariantMap)),
		this,
		SLOT(deviceCreated(QString, QVariantMap)));
	connect(adapter,
		SIGNAL(DeviceDisappeared(QString)),
		this,
		SLOT(deviceRemoved(QString)));
}

void NearbyDevicesModel::adapterRemoved(QDBusObjectPath)
{
	QDBusObjectPath adapterpath = manager->DefaultAdapter();

	if(adapterpath.path() == "")
	{
		removeAll(true);
		if(adapter){ delete adapter; adapter = NULL; }
		return;
	}
}
