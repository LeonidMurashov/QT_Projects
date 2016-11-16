/****************************************************************************
** Meta object code from reading C++ file 'ft232rl_class.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QT_projects/ft232rl_2/ft232rl_class.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ft232rl_class.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ft232rl_class_t {
    QByteArrayData data[8];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ft232rl_class_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ft232rl_class_t qt_meta_stringdata_ft232rl_class = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ft232rl_class"
QT_MOC_LITERAL(1, 14, 7), // "refresh"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "str"
QT_MOC_LITERAL(4, 27, 16), // "maininmainwindow"
QT_MOC_LITERAL(5, 44, 24), // "maininmainwindow_control"
QT_MOC_LITERAL(6, 69, 8), // "swich_of"
QT_MOC_LITERAL(7, 78, 12) // "TIME_changed"

    },
    "ft232rl_class\0refresh\0\0str\0maininmainwindow\0"
    "maininmainwindow_control\0swich_of\0"
    "TIME_changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ft232rl_class[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ft232rl_class::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ft232rl_class *_t = static_cast<ft232rl_class *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { QString _r = _t->maininmainwindow();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: _t->maininmainwindow_control(); break;
        case 3: _t->swich_of(); break;
        case 4: _t->TIME_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ft232rl_class::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ft232rl_class::refresh)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ft232rl_class::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ft232rl_class.data,
      qt_meta_data_ft232rl_class,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ft232rl_class::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ft232rl_class::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ft232rl_class.stringdata0))
        return static_cast<void*>(const_cast< ft232rl_class*>(this));
    return QObject::qt_metacast(_clname);
}

int ft232rl_class::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ft232rl_class::refresh(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
