/****************************************************************************
** Meta object code from reading C++ file 'colorlabel.h'
**
** Created: Thu Jul 19 15:48:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "colorlabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_colorLabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   11,   11,   11, 0x0a,
      48,   11,   11,   11, 0x0a,
      62,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_colorLabel[] = {
    "colorLabel\0\0,,\0clicked(int,int,int)\0"
    "setRed(int)\0setGreen(int)\0setBlue(int)\0"
};

void colorLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        colorLabel *_t = static_cast<colorLabel *>(_o);
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->setRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData colorLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject colorLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_colorLabel,
      qt_meta_data_colorLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &colorLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *colorLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *colorLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_colorLabel))
        return static_cast<void*>(const_cast< colorLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int colorLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void colorLabel::clicked(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
