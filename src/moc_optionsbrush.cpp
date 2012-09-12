/****************************************************************************
** Meta object code from reading C++ file 'optionsbrush.h'
**
** Created: Wed Jul 25 13:31:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionsbrush.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsbrush.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_optionsBrush[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_optionsBrush[] = {
    "optionsBrush\0"
};

void optionsBrush::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData optionsBrush::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject optionsBrush::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_optionsBrush,
      qt_meta_data_optionsBrush, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &optionsBrush::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *optionsBrush::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *optionsBrush::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_optionsBrush))
        return static_cast<void*>(const_cast< optionsBrush*>(this));
    return QWidget::qt_metacast(_clname);
}

int optionsBrush::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
