#include "bluetoothdevice.h"
#include "blueadapter.h"
#include "bluemanager.h"
#include "btprofiles.h"
#include "audiosink.h"
#include "audiosource.h"
#include "headset.h"

BluetoothDevice::BluetoothDevice(QDBusObjectPath path, QObject *parent) :
		QObject(parent),m_device(new OrgBluezDeviceInterface("org.bluez",path.path(),QDBusConnection::systemBus(),this))
{
	if(!m_device->isValid())
		return;
	QObject::connect(m_device,SIGNAL(PropertyChanged(QString,QDBusVariant)),
					 this,SLOT(propertyChanged(QString,QDBusVariant)));
}

void BluetoothDevice::unpair()
{
	OrgBluezManagerInterface manager(
			"org.bluez",
			"/", QDBusConnection::systemBus());

	QDBusObjectPath adapterpath = manager.DefaultAdapter();

	if(adapterpath.path().isEmpty()) return;

	OrgBluezAdapterInterface adapter(
			"org.bluez",
			adapterpath.path(),
			QDBusConnection::systemBus());

	adapter.RemoveDevice(QDBusObjectPath(m_device->path()));
}

void BluetoothDevice::connect(QString profile)
{
	if(profile == BluetoothProfiles::a2sink)
	{
		OrgBluezAudioSinkInterface sink("org.bluez",m_device->path(),
										QDBusConnection::systemBus());
		sink.Connect();
	}
	else if(profile == BluetoothProfiles::a2src)
	{
		OrgBluezAudioSourceInterface source("org.bluez",m_device->path(),
										QDBusConnection::systemBus());
		source.Connect();
	}
	else if(profile == BluetoothProfiles::hs)
	{
		OrgBluezHeadsetInterface headset("org.bluez",m_device->path(),
										QDBusConnection::systemBus());
		headset.Connect();
	}
	else if(profile == BluetoothProfiles::spp)
	{
		QDBusInterface interface("org.bluez",m_device->path(),"org.bluez.Serial",QDBusConnection::systemBus());
		interface.call(QDBus::AutoDetect, "Connect","spp");
	}
}

void BluetoothDevice::disconnect()
{
	m_device->Disconnect();
}

QStringList BluetoothDevice::profiles()
{
	QVariantMap props = m_device->GetProperties();

	QStringList uuidlist = props["UUIDs"].toStringList();

	return uuidlist;
}

bool BluetoothDevice::isProfileSupported(QString profile)
{
	QVariantMap props = m_device->GetProperties();

	QStringList uuidlist = props["UUIDs"].toStringList();

	return uuidlist.contains(profile.toLower());
}

bool BluetoothDevice::connected()
{
	QVariantMap props = m_device->GetProperties();
	return props["Connected"].toBool();
}

QString BluetoothDevice::connectedProfile()
{
	foreach(QString profile, profiles())
	{
		if(profile == BluetoothProfiles::a2sink)
		{
			OrgBluezAudioSinkInterface sink("org.bluez",m_device->path(),
											QDBusConnection::systemBus());
			if(sink.IsConnected())
				return BluetoothProfiles::a2sink;
		}
		else if(profile == BluetoothProfiles::a2src)
		{
			OrgBluezAudioSourceInterface source("org.bluez",m_device->path(),
											QDBusConnection::systemBus());
			QVariantMap props = source.GetProperties();

			if(props["State"].toString() == "connected")
			{
				return BluetoothProfiles::a2src;
			}

		}
		else if(profile == BluetoothProfiles::hs)
		{
			OrgBluezHeadsetInterface headset("org.bluez",m_device->path(),
											QDBusConnection::systemBus());
			if(headset.IsConnected())
			{
				return BluetoothProfiles::hs;
			}
		}
	}
}

QString BluetoothDevice::alias()
{
	QVariantMap props = m_device->GetProperties();
	return props["Alias"].toString();
}

QString BluetoothDevice::name()
{
	QVariantMap props = m_device->GetProperties();
	return props["Name"].toString();
}

QString BluetoothDevice::address()
{
	QVariantMap props = m_device->GetProperties();
	return props["Address"].toString();
}

QString BluetoothDevice::icon()
{
	QVariantMap props = m_device->GetProperties();
	return props["Icon"].toString();
}

QString BluetoothDevice::path()
{
	return m_device->path();
}

void BluetoothDevice::propertyChanged(QString name,QDBusVariant value)
{
	if(name == "Connected")
	{
		emit connetedChanged();
	}
}
