/****************************************************************************
** Meta object code from reading C++ file 'bluetoothbaseagent.h'
**
** Created: Wed May 25 10:17:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetoothbaseagent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothbaseagent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothBaseAgent[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   20,   19,   19, 0x0a,
      72,   19,   19,   19, 0x0a,
      88,   19,   19,   19, 0x0a,
      97,   19,   19,   19, 0x0a,
     143,  124,   19,   19, 0x0a,
     194,   19,   19,   19, 0x0a,
     215,  204,   19,   19, 0x0a,
     278,  271,  266,   19, 0x0a,
     327,  271,  319,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothBaseAgent[] = {
    "BluetoothBaseAgent\0\0device,\0"
    "authorize(OrgBluezDeviceInterface&,QString)\0"
    "registerAgent()\0cancel()\0"
    "confirmModeChange(QString)\0"
    "device,key,entered\0"
    "displayPasskey(OrgBluezDeviceInterface&,uint,uint)\0"
    "release()\0device,key\0"
    "requestConfirmation(OrgBluezDeviceInterface&,uint)\0"
    "uint\0device\0requestPasskey(OrgBluezDeviceInterface&)\0"
    "QString\0requestPidCode(OrgBluezDeviceInterface&)\0"
};

const QMetaObject BluetoothBaseAgent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BluetoothBaseAgent,
      qt_meta_data_BluetoothBaseAgent, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothBaseAgent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothBaseAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothBaseAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothBaseAgent))
        return static_cast<void*>(const_cast< BluetoothBaseAgent*>(this));
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(const_cast< BluetoothBaseAgent*>(this));
    return QObject::qt_metacast(_clname);
}

int BluetoothBaseAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: authorize((*reinterpret_cast< OrgBluezDeviceInterface(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: registerAgent(); break;
        case 2: cancel(); break;
        case 3: confirmModeChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: displayPasskey((*reinterpret_cast< OrgBluezDeviceInterface(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 5: release(); break;
        case 6: requestConfirmation((*reinterpret_cast< OrgBluezDeviceInterface(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 7: { uint _r = requestPasskey((*reinterpret_cast< OrgBluezDeviceInterface(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 8: { QString _r = requestPidCode((*reinterpret_cast< OrgBluezDeviceInterface(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
