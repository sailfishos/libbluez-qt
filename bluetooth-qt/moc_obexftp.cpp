/****************************************************************************
** Meta object code from reading C++ file 'obexftp.h'
**
** Created: Wed May 25 09:44:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "obex/obexftp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'obexftp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ObexFtp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,    9,    8,    8, 0x05,
      54,    8,    8,    8, 0x05,
      73,    8,    8,    8, 0x05,
      88,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,    8,    8,    8, 0x0a,
     110,    8,    8,    8, 0x0a,
     123,    8,    8,    8, 0x0a,
     153,  132,    8,    8, 0x0a,
     183,    8,    8,    8, 0x08,
     226,    8,    8,    8, 0x08,
     276,  271,    8,    8, 0x08,
     313,  302,    8,    8, 0x08,
     361,  344,    8,    8, 0x08,
     398,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ObexFtp[] = {
    "ObexFtp\0\0done,total\0"
    "transferProgress(quint64,quint64)\0"
    "transferComplete()\0error(QString)\0"
    "connected()\0connect()\0disconnect()\0"
    "cancel()\0localfile,remotefile\0"
    "transferFile(QString,QString)\0"
    "finishedTransfer(QDBusPendingCallWatcher*)\0"
    "finishedConnecting(QDBusPendingCallWatcher*)\0"
    "path\0Complete(QDBusObjectPath)\0"
    "path,error\0Error(QDBusObjectPath,QString)\0"
    "path,transferred\0Progress(QDBusObjectPath,qulonglong)\0"
    "Release()\0"
};

const QMetaObject ObexFtp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ObexFtp,
      qt_meta_data_ObexFtp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ObexFtp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ObexFtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ObexFtp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObexFtp))
        return static_cast<void*>(const_cast< ObexFtp*>(this));
    return QObject::qt_metacast(_clname);
}

int ObexFtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: transferProgress((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 1: transferComplete(); break;
        case 2: error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: connected(); break;
        case 4: connect(); break;
        case 5: disconnect(); break;
        case 6: cancel(); break;
        case 7: transferFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: finishedTransfer((*reinterpret_cast< QDBusPendingCallWatcher*(*)>(_a[1]))); break;
        case 9: finishedConnecting((*reinterpret_cast< QDBusPendingCallWatcher*(*)>(_a[1]))); break;
        case 10: Complete((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1]))); break;
        case 11: Error((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: Progress((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< qulonglong(*)>(_a[2]))); break;
        case 13: Release(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ObexFtp::transferProgress(quint64 _t1, quint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ObexFtp::transferComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ObexFtp::error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ObexFtp::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
