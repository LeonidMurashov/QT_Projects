/****************************************************************************
** Meta object code from reading C++ file 'unit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PE2/unit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Unit_t {
    QByteArrayData data[10];
    char stringdata[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Unit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Unit_t qt_meta_stringdata_Unit = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Unit"
QT_MOC_LITERAL(1, 5, 7), // "clicked"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 5), // "Unit*"
QT_MOC_LITERAL(4, 20, 1), // "a"
QT_MOC_LITERAL(5, 22, 10), // "clickeddel"
QT_MOC_LITERAL(6, 33, 11), // "clickedslot"
QT_MOC_LITERAL(7, 45, 14), // "clickeddelslot"
QT_MOC_LITERAL(8, 60, 10), // "numchanged"
QT_MOC_LITERAL(9, 71, 3) // "num"

    },
    "Unit\0clicked\0\0Unit*\0a\0clickeddel\0"
    "clickedslot\0clickeddelslot\0numchanged\0"
    "num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Unit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void Unit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Unit *_t = static_cast<Unit *>(_o);
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< Unit*(*)>(_a[1]))); break;
        case 1: _t->clickeddel((*reinterpret_cast< Unit*(*)>(_a[1]))); break;
        case 2: _t->clickedslot(); break;
        case 3: _t->clickeddelslot(); break;
        case 4: _t->numchanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Unit* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Unit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Unit::*_t)(Unit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Unit::clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (Unit::*_t)(Unit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Unit::clickeddel)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Unit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Unit.data,
      qt_meta_data_Unit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Unit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Unit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Unit.stringdata))
        return static_cast<void*>(const_cast< Unit*>(this));
    return QWidget::qt_metacast(_clname);
}

int Unit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Unit::clicked(Unit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Unit::clickeddel(Unit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
