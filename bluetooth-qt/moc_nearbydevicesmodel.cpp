/****************************************************************************
** Meta object code from reading C++ file 'nearbydevicesmodel.h'
**
** Created: Wed May 25 10:17:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "nearbydevicesmodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nearbydevicesmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NearbyItem[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      19,   11, 0x0a095001,
      24,   11, 0x0a095001,
      32,   11, 0x0a095001,
      42,   37, 0x01095001,

       0        // eod
};

static const char qt_meta_stringdata_NearbyItem[] = {
    "NearbyItem\0QString\0name\0address\0icon\0"
    "bool\0legacyPairing\0"
};

const QMetaObject NearbyItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NearbyItem,
      qt_meta_data_NearbyItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NearbyItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NearbyItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NearbyItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NearbyItem))
        return static_cast<void*>(const_cast< NearbyItem*>(this));
    return QObject::qt_metacast(_clname);
}

int NearbyItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = address(); break;
        case 2: *reinterpret_cast< QString*>(_v) = icon(); break;
        case 3: *reinterpret_cast< bool*>(_v) = legacyPairing(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
static const uint qt_meta_data_NearbyDevicesModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       1,  139, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   20,   19,   19, 0x05,
      73,   66,   19,   19, 0x05,
      97,   66,   19,   19, 0x05,
     121,   19,   19,   19, 0x05,
     137,  131,   19,   19, 0x05,
     160,  131,   19,   19, 0x05,
     196,  185,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     243,   19,  239,   19, 0x0a,
     275,  268,  239,   19, 0x0a,
     297,   19,  239,   19, 0x2a,
     328,  317,  308,   19, 0x0a,
     358,  131,  350,   19, 0x0a,
     373,  131,  350,   19, 0x0a,
     391,  384,   19,   19, 0x0a,
     411,  405,   19,   19, 0x0a,
     426,   19,   19,   19, 0x0a,
     452,  442,   19,   19, 0x0a,
     491,  483,   19,   19, 0x0a,
     518,  510,   19,   19, 0x0a,
     547,  185,   19,   19, 0x0a,
     584,   19,   19,   19, 0x08,
     614,   19,   19,   19, 0x08,
     664,  646,   19,   19, 0x08,
     699,  384,   19,   19, 0x08,
     726,  722,   19,   19, 0x08,

 // properties: name, type, flags
     794,  777, 0x00095009,

       0        // eod
};

static const char qt_meta_stringdata_NearbyDevicesModel[] = {
    "NearbyDevicesModel\0\0device,code\0"
    "requestConfirmation(QString,uint)\0"
    "device\0requestPasskey(QString)\0"
    "requestPidCode(QString)\0release()\0"
    "index\0nearbyDeviceFound(int)\0"
    "nearbyDeviceRemoved(int)\0name,value\0"
    "adapterPropertiesChanged(QString,QVariant)\0"
    "int\0columnCount(QModelIndex)\0parent\0"
    "rowCount(QModelIndex)\0rowCount()\0"
    "QVariant\0index,role\0data(QModelIndex,int)\0"
    "QString\0hwAddress(int)\0alias(int)\0"
    "hwaddy\0pair(QString)\0start\0discover(bool)\0"
    "removeAll(bool)\0confirmed\0"
    "replyRequestConfirmation(bool)\0passkey\0"
    "replyPasskey(uint)\0pidCode\0"
    "replyRequestPidCode(QString)\0"
    "setAdapterProperty(QString,QVariant)\0"
    "adapterAdded(QDBusObjectPath)\0"
    "adapterRemoved(QDBusObjectPath)\0"
    "hwaddy,properties\0deviceCreated(QString,QVariantMap)\0"
    "deviceRemoved(QString)\0n,v\0"
    "adapterPropertiesChangedSlot(QString,QDBusVariant)\0"
    "BluetoothDevice*\0pairingDevice\0"
};

const QMetaObject NearbyDevicesModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_NearbyDevicesModel,
      qt_meta_data_NearbyDevicesModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NearbyDevicesModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NearbyDevicesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NearbyDevicesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NearbyDevicesModel))
        return static_cast<void*>(const_cast< NearbyDevicesModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int NearbyDevicesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestConfirmation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: requestPasskey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: requestPidCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: release(); break;
        case 4: nearbyDeviceFound((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: nearbyDeviceRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: adapterPropertiesChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 7: { int _r = columnCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = rowCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { QVariant _r = data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 11: { QString _r = hwAddress((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = alias((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: pair((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: discover((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: removeAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: replyRequestConfirmation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: replyPasskey((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 18: replyRequestPidCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: setAdapterProperty((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 20: adapterAdded((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 21: adapterRemoved((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 22: deviceCreated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 23: deviceRemoved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: adapterPropertiesChangedSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 25;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< BluetoothDevice**>(_v) = pairingDevice(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NearbyDevicesModel::requestConfirmation(QString _t1, uint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NearbyDevicesModel::requestPasskey(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NearbyDevicesModel::requestPidCode(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NearbyDevicesModel::release()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void NearbyDevicesModel::nearbyDeviceFound(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NearbyDevicesModel::nearbyDeviceRemoved(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NearbyDevicesModel::adapterPropertiesChanged(QString _t1, QVariant _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
