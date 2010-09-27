#ifndef NEARBYDEVICESMODEL_H
#define NEARBYDEVICESMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QDBusObjectPath>

#include "bluemanager.h"
#include "blueadapter.h"
#include "asyncagent.h"

namespace NearbyDevicesModelRoles
{
	enum
	{
		name = Qt::UserRole + 1,
		address
	};
}

class NearbyDevicesModel : public QAbstractListModel
{
	Q_OBJECT

public:
	NearbyDevicesModel(QObject *parent = 0);

public slots:

	int columnCount(const QModelIndex &) const { return 1;}
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;

	QString hwAddress(int index) { return devicepathlist[index]; }
	QString alias(int index){ return deviceAliasMap[devicepathlist[index]]; }
	void pair(QString hwaddy);
	void discover(bool start);
	void removeAll(bool);

	void replyRequestConfirmation(bool confirmed);
	void replyPasskey(uint passkey);
	void replyRequestPidCode(QString pidCode);

	void setAdapterProperty(QString name, QVariant value);

private slots:
	void adapterAdded(QDBusObjectPath);
	void adapterRemoved(QDBusObjectPath);
	void deviceCreated(QString hwaddy, QVariantMap properties);
	void deviceRemoved(QString hwaddy);

	void adapterPropertiesChangedSlot(QString n,QDBusVariant v);

signals:
	void requestConfirmation(QString device, uint code);
	void requestPasskey(QString device);
	void requestPidCode(QString device);

	void nearbyDeviceFound(int index);
	void nearbyDeviceRemoved(int index);

	void adapterPropertiesChanged(QString name, QVariant value);

private:
	QList<QString> devicepathlist;
	QMap<QString,QString> deviceAliasMap;
	OrgBluezManagerInterface *manager;
	OrgBluezAdapterInterface *adapter;
	AsyncAgent* agent;
};

#endif // NEARBYDEVICESMODEL_H
