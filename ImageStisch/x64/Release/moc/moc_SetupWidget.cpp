/****************************************************************************
** Meta object code from reading C++ file 'SetupWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SetupWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SetupWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetupWidget_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetupWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetupWidget_t qt_meta_stringdata_SetupWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SetupWidget"
QT_MOC_LITERAL(1, 12, 12), // "sendAlgValue"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "StitcherParam"
QT_MOC_LITERAL(4, 40, 18), // "btnConfirm_Clicked"
QT_MOC_LITERAL(5, 59, 17) // "btnCancel_Clicked"

    },
    "SetupWidget\0sendAlgValue\0\0StitcherParam\0"
    "btnConfirm_Clicked\0btnCancel_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetupWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SetupWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetupWidget *_t = static_cast<SetupWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAlgValue((*reinterpret_cast< StitcherParam(*)>(_a[1]))); break;
        case 1: _t->btnConfirm_Clicked(); break;
        case 2: _t->btnCancel_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SetupWidget::*_t)(StitcherParam );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetupWidget::sendAlgValue)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SetupWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetupWidget.data,
      qt_meta_data_SetupWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetupWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetupWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetupWidget.stringdata0))
        return static_cast<void*>(const_cast< SetupWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetupWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SetupWidget::sendAlgValue(StitcherParam _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
