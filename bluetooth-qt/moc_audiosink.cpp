/****************************************************************************
** Meta object code from reading C++ file 'audiosink.h'
**
** Created: Wed May 25 10:17:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "audiosink.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiosink.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrgBluezAudioSinkInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      40,   27,   27,   27, 0x05,
      55,   27,   27,   27, 0x05,
      73,   65,   27,   27, 0x05,
     111,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
     141,   27,  121,   27, 0x0a,
     151,   27,  121,   27, 0x0a,
     195,   27,  164,   27, 0x0a,
     235,   27,  211,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OrgBluezAudioSinkInterface[] = {
    "OrgBluezAudioSinkInterface\0\0Connected()\0"
    "Disconnected()\0Playing()\0in0,in1\0"
    "PropertyChanged(QString,QDBusVariant)\0"
    "Stopped()\0QDBusPendingReply<>\0Connect()\0"
    "Disconnect()\0QDBusPendingReply<QVariantMap>\0"
    "GetProperties()\0QDBusPendingReply<bool>\0"
    "IsConnected()\0"
};

const QMetaObject OrgBluezAudioSinkInterface::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_OrgBluezAudioSinkInterface,
      qt_meta_data_OrgBluezAudioSinkInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrgBluezAudioSinkInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrgBluezAudioSinkInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrgBluezAudioSinkInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrgBluezAudioSinkInterface))
        return static_cast<void*>(const_cast< OrgBluezAudioSinkInterface*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgBluezAudioSinkInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Connected(); break;
        case 1: Disconnected(); break;
        case 2: Playing(); break;
        case 3: PropertyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2]))); break;
        case 4: Stopped(); break;
        case 5: { QDBusPendingReply<> _r = Connect();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 6: { QDBusPendingReply<> _r = Disconnect();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 7: { QDBusPendingReply<QVariantMap> _r = GetProperties();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantMap>*>(_a[0]) = _r; }  break;
        case 8: { QDBusPendingReply<bool> _r = IsConnected();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void OrgBluezAudioSinkInterface::Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void OrgBluezAudioSinkInterface::Disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void OrgBluezAudioSinkInterface::Playing()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void OrgBluezAudioSinkInterface::PropertyChanged(const QString & _t1, const QDBusVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void OrgBluezAudioSinkInterface::Stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
