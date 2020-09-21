/****************************************************************************
** Meta object code from reading C++ file 'ImageStisch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ImageStisch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageStisch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageStisch_t {
    QByteArrayData data[20];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageStisch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageStisch_t qt_meta_stringdata_ImageStisch = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageStisch"
QT_MOC_LITERAL(1, 12, 12), // "StatusSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "StitchFinishSignal"
QT_MOC_LITERAL(4, 45, 10), // "ImageData*"
QT_MOC_LITERAL(5, 56, 18), // "AlgorProcessSignal"
QT_MOC_LITERAL(6, 75, 1), // "a"
QT_MOC_LITERAL(7, 77, 10), // "StatusSlot"
QT_MOC_LITERAL(8, 88, 16), // "StitchFinishSlot"
QT_MOC_LITERAL(9, 105, 11), // "getAlgValue"
QT_MOC_LITERAL(10, 117, 13), // "StitcherParam"
QT_MOC_LITERAL(11, 131, 22), // "title_btn_menu_Clicked"
QT_MOC_LITERAL(12, 154, 21), // "title_btn_min_Clicked"
QT_MOC_LITERAL(13, 176, 21), // "title_btn_max_Clicked"
QT_MOC_LITERAL(14, 198, 23), // "title_btn_close_Clicked"
QT_MOC_LITERAL(15, 222, 19), // "btnReadFile_Clicked"
QT_MOC_LITERAL(16, 242, 15), // "btnSave_Clicked"
QT_MOC_LITERAL(17, 258, 16), // "btnSetup_Clicked"
QT_MOC_LITERAL(18, 275, 16), // "btnStart_running"
QT_MOC_LITERAL(19, 292, 14) // "slotRowClicked"

    },
    "ImageStisch\0StatusSignal\0\0StitchFinishSignal\0"
    "ImageData*\0AlgorProcessSignal\0a\0"
    "StatusSlot\0StitchFinishSlot\0getAlgValue\0"
    "StitcherParam\0title_btn_menu_Clicked\0"
    "title_btn_min_Clicked\0title_btn_max_Clicked\0"
    "title_btn_close_Clicked\0btnReadFile_Clicked\0"
    "btnSave_Clicked\0btnSetup_Clicked\0"
    "btnStart_running\0slotRowClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageStisch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   98,    2, 0x08 /* Private */,
       8,    1,  101,    2, 0x08 /* Private */,
       9,    1,  104,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void ImageStisch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageStisch *_t = static_cast<ImageStisch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StatusSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->StitchFinishSignal((*reinterpret_cast< ImageData*(*)>(_a[1]))); break;
        case 2: _t->AlgorProcessSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->StatusSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->StitchFinishSlot((*reinterpret_cast< ImageData*(*)>(_a[1]))); break;
        case 5: _t->getAlgValue((*reinterpret_cast< StitcherParam(*)>(_a[1]))); break;
        case 6: _t->title_btn_menu_Clicked(); break;
        case 7: _t->title_btn_min_Clicked(); break;
        case 8: _t->title_btn_max_Clicked(); break;
        case 9: _t->title_btn_close_Clicked(); break;
        case 10: _t->btnReadFile_Clicked(); break;
        case 11: _t->btnSave_Clicked(); break;
        case 12: _t->btnSetup_Clicked(); break;
        case 13: _t->btnStart_running(); break;
        case 14: _t->slotRowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageStisch::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageStisch::StatusSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageStisch::*_t)(ImageData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageStisch::StitchFinishSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ImageStisch::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageStisch::AlgorProcessSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ImageStisch::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageStisch.data,
      qt_meta_data_ImageStisch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageStisch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageStisch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageStisch.stringdata0))
        return static_cast<void*>(const_cast< ImageStisch*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImageStisch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ImageStisch::StatusSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageStisch::StitchFinishSignal(ImageData * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageStisch::AlgorProcessSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
