/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created: Wed Jul 25 11:03:41 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "canvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_canvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x0a,
      39,    7,    7,    7, 0x0a,
      51,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_canvas[] = {
    "canvas\0\0,,\0updateSelected(int,int,int)\0"
    "effect(int)\0saveImage()\0"
};

void canvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        canvas *_t = static_cast<canvas *>(_o);
        switch (_id) {
        case 0: _t->updateSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->effect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->saveImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData canvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject canvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_canvas,
      qt_meta_data_canvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &canvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *canvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *canvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_canvas))
        return static_cast<void*>(const_cast< canvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int canvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
