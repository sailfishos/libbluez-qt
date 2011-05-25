/****************************************************************************
** Meta object code from reading C++ file 'bluetoothdevice.h'
**
** Created: Wed May 25 10:17:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetoothdevice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothdevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothDevice[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
      10,  154, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   17,   16,   16, 0x05,
      52,   17,   16,   16, 0x05,
      80,   17,   16,   16, 0x05,
     119,  108,   16,   16, 0x05,
     159,  153,   16,   16, 0x05,
     194,  188,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     215,   16,   16,   16, 0x0a,
     224,   16,   16,   16, 0x0a,
     239,   16,   16,   16, 0x0a,
     265,   16,  257,   16, 0x0a,
     281,   16,   16,   16, 0x0a,
     296,   16,   16,   16, 0x0a,
     309,   16,   16,   16, 0x0a,
     332,   16,  327,   16, 0x0a,
     342,  188,   16,   16, 0x0a,
     371,   16,  359,   16, 0x0a,
     390,  382,  327,   16, 0x0a,
     418,   16,  327,   16, 0x0a,
     430,   16,  327,   16, 0x0a,
     447,   16,  327,   16, 0x0a,
     464,   16,  257,   16, 0x0a,
     472,   16,  257,   16, 0x0a,
     479,   16,  257,   16, 0x0a,
     489,   16,  257,   16, 0x0a,
     496,   16,  257,   16, 0x0a,
     503,  108,   16,   16, 0x08,
     541,  108,   16,   16, 0x08,
     586,  108,   16,   16, 0x08,

 // properties: name, type, flags
     631,  327, 0x01495001,
     641,  327, 0x01495001,
     656,  327, 0x01495001,
     671,  327, 0x01495103,
     679,  359, 0x0b495001,
     688,  257, 0x0a095001,
     694,  257, 0x0a095001,
     699,  257, 0x0a095001,
     707,  257, 0x0a095001,
     712,  257, 0x0a095001,

 // properties: notify_signal_id
       0,
       1,
       2,
       5,
       4,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothDevice[] = {
    "BluetoothDevice\0\0isConnected\0"
    "connectedChanged(bool)\0"
    "audioConnectedChanged(bool)\0"
    "inputConnectedChanged(bool)\0name,value\0"
    "propertyChanged(QString,QVariant)\0"
    "uuids\0profilesChanged(QStringList)\0"
    "trust\0trustedChanged(bool)\0unpair()\0"
    "connectAudio()\0connectAudioSrc()\0"
    "QString\0connectSerial()\0connectInput()\0"
    "disconnect()\0disconnectAudio()\0bool\0"
    "trusted()\0setTrusted(bool)\0QStringList\0"
    "profiles()\0profile\0isProfileSupported(QString)\0"
    "connected()\0audioConnected()\0"
    "inputConnected()\0alias()\0name()\0"
    "address()\0icon()\0path()\0"
    "propertyChanged(QString,QDBusVariant)\0"
    "audioPropertiesChanged(QString,QDBusVariant)\0"
    "inputPropertiesChanged(QString,QDBusVariant)\0"
    "connected\0audioConnected\0inputConnected\0"
    "trusted\0profiles\0alias\0name\0address\0"
    "icon\0path\0"
};

const QMetaObject BluetoothDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BluetoothDevice,
      qt_meta_data_BluetoothDevice, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothDevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothDevice))
        return static_cast<void*>(const_cast< BluetoothDevice*>(this));
    return QObject::qt_metacast(_clname);
}

int BluetoothDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: audioConnectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: inputConnectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: propertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 4: profilesChanged((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: trustedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: unpair(); break;
        case 7: connectAudio(); break;
        case 8: connectAudioSrc(); break;
        case 9: { QString _r = connectSerial();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: connectInput(); break;
        case 11: disconnect(); break;
        case 12: disconnectAudio(); break;
        case 13: { bool _r = trusted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: setTrusted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: { QStringList _r = profiles();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 16: { bool _r = isProfileSupported((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = connected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = audioConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { bool _r = inputConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: { QString _r = alias();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: { QString _r = name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 22: { QString _r = address();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: { QString _r = icon();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 24: { QString _r = path();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: propertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        case 26: audioPropertiesChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        case 27: inputPropertiesChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 28;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = connected(); break;
        case 1: *reinterpret_cast< bool*>(_v) = audioConnected(); break;
        case 2: *reinterpret_cast< bool*>(_v) = inputConnected(); break;
        case 3: *reinterpret_cast< bool*>(_v) = trusted(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = profiles(); break;
        case 5: *reinterpret_cast< QString*>(_v) = alias(); break;
        case 6: *reinterpret_cast< QString*>(_v) = name(); break;
        case 7: *reinterpret_cast< QString*>(_v) = address(); break;
        case 8: *reinterpret_cast< QString*>(_v) = icon(); break;
        case 9: *reinterpret_cast< QString*>(_v) = path(); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: setTrusted(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BluetoothDevice::connectedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothDevice::audioConnectedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BluetoothDevice::inputConnectedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BluetoothDevice::propertyChanged(QString _t1, QVariant _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BluetoothDevice::profilesChanged(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BluetoothDevice::trustedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
