/****************************************************************************
** Meta object code from reading C++ file 'drawingitem.h'
**
** Created: Wed Jul 25 13:31:10 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drawingitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawingitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drawingItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      33,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_drawingItem[] = {
    "drawingItem\0\0toolTypeUpdate(int)\0"
    "setAnti(bool)\0"
};

void drawingItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        drawingItem *_t = static_cast<drawingItem *>(_o);
        switch (_id) {
        case 0: _t->toolTypeUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setAnti((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData drawingItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drawingItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_drawingItem,
      qt_meta_data_drawingItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drawingItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drawingItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drawingItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drawingItem))
        return static_cast<void*>(const_cast< drawingItem*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< drawingItem*>(this));
    return QObject::qt_metacast(_clname);
}

int drawingItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
