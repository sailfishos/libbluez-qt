/****************************************************************************
** Meta object code from reading C++ file 'bluetoothdevicemodel.h'
**
** Created: Wed May 25 10:17:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetoothdevicemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothdevicemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothDevicesModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       5,  144, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   23,   22,   22, 0x05,
      60,   52,   22,   22, 0x05,
      99,   92,   22,   22, 0x05,
     143,  130,   22,   22, 0x05,
     184,  169,   22,   22, 0x05,
     217,  205,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     244,   22,  240,   22, 0x0a,
     276,  269,  240,   22, 0x0a,
     298,   22,  240,   22, 0x2a,
     329,  318,  309,   22, 0x0a,
     364,  359,  351,   22, 0x0a,
     408,   22,  384,   22, 0x0a,
     423,   22,  418,   22, 0x0a,
     457,  452,  435,   22, 0x0a,
     486,  473,   22,   22, 0x0a,
     504,   22,  418,   22, 0x0a,
     532,  514,   22,   22, 0x0a,
     555,   22,  418,   22, 0x0a,
     570,   22,  240,   22, 0x0a,
     592,   52,   22,   22, 0x0a,
     620,   22,   22,   22, 0x08,
     650,   22,   22,   22, 0x08,
     682,   22,   22,   22, 0x08,
     713,   22,   22,   22, 0x08,
     755,  744,   22,   22, 0x08,
     795,  744,   22,   22, 0x08,

 // properties: name, type, flags
      23,  418, 0x01495003,
     130,  418, 0x01495003,
     840,  240, 0x02495103,
     169,  418, 0x01495001,
     860,  418, 0x01495001,

 // properties: notify_signal_id
       0,
       3,
       1,
       4,
       5,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothDevicesModel[] = {
    "BluetoothDevicesModel\0\0powered\0"
    "poweredChanged(bool)\0timeout\0"
    "discoverableTimeoutChanged(int)\0device\0"
    "devicePaired(BluetoothDevice*)\0"
    "discoverable\0discoverableChanged(bool)\0"
    "adapterPresent\0adapterChanged(bool)\0"
    "isConnected\0connectedChanged(bool)\0"
    "int\0columnCount(QModelIndex)\0parent\0"
    "rowCount(QModelIndex)\0rowCount()\0"
    "QVariant\0index,role\0data(QModelIndex,int)\0"
    "QString\0name\0devicePath(QString)\0"
    "QList<BluetoothDevice*>\0devices()\0"
    "bool\0connected()\0BluetoothDevice*\0"
    "path\0device(QString)\0poweredValue\0"
    "makePowered(bool)\0powered()\0"
    "discoverableValue\0makeDiscoverable(bool)\0"
    "discoverable()\0discoverableTimeout()\0"
    "setDiscoverableTimeout(int)\0"
    "adapterAdded(QDBusObjectPath)\0"
    "adapterRemoved(QDBusObjectPath)\0"
    "deviceCreated(QDBusObjectPath)\0"
    "deviceRemoved(QDBusObjectPath)\0"
    "name,value\0devicePropertyChanged(QString,QVariant)\0"
    "adapterPropertyChanged(QString,QDBusVariant)\0"
    "discoverableTimeout\0connected\0"
};

const QMetaObject BluetoothDevicesModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_BluetoothDevicesModel,
      qt_meta_data_BluetoothDevicesModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothDevicesModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothDevicesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothDevicesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothDevicesModel))
        return static_cast<void*>(const_cast< BluetoothDevicesModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int BluetoothDevicesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: poweredChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: discoverableTimeoutChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: devicePaired((*reinterpret_cast< BluetoothDevice*(*)>(_a[1]))); break;
        case 3: discoverableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: adapterChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: connectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: { int _r = columnCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = rowCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { QVariant _r = data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 10: { QString _r = devicePath((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { QList<BluetoothDevice*> _r = devices();
            if (_a[0]) *reinterpret_cast< QList<BluetoothDevice*>*>(_a[0]) = _r; }  break;
        case 12: { bool _r = connected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { BluetoothDevice* _r = device((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< BluetoothDevice**>(_a[0]) = _r; }  break;
        case 14: makePowered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: { bool _r = powered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: makeDiscoverable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: { bool _r = discoverable();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { int _r = discoverableTimeout();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 19: setDiscoverableTimeout((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: adapterAdded((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 21: adapterRemoved((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 22: deviceCreated((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 23: deviceRemoved((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 24: devicePropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 25: adapterPropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 26;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = powered(); break;
        case 1: *reinterpret_cast< bool*>(_v) = discoverable(); break;
        case 2: *reinterpret_cast< int*>(_v) = discoverableTimeout(); break;
        case 3: *reinterpret_cast< bool*>(_v) = adapterPresent(); break;
        case 4: *reinterpret_cast< bool*>(_v) = connected(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: makePowered(*reinterpret_cast< bool*>(_v)); break;
        case 1: makeDiscoverable(*reinterpret_cast< bool*>(_v)); break;
        case 2: setDiscoverableTimeout(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BluetoothDevicesModel::poweredChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothDevicesModel::discoverableTimeoutChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BluetoothDevicesModel::devicePaired(BluetoothDevice * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BluetoothDevicesModel::discoverableChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BluetoothDevicesModel::adapterChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BluetoothDevicesModel::connectedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
