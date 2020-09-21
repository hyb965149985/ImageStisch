/****************************************************************************
** Meta object code from reading C++ file 'Graphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Graphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Graphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGraphicsPixmapItem_t {
    QByteArrayData data[4];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGraphicsPixmapItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGraphicsPixmapItem_t qt_meta_stringdata_MyGraphicsPixmapItem = {
    {
QT_MOC_LITERAL(0, 0, 20), // "MyGraphicsPixmapItem"
QT_MOC_LITERAL(1, 21, 10), // "mousePress"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5) // "index"

    },
    "MyGraphicsPixmapItem\0mousePress\0\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraphicsPixmapItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MyGraphicsPixmapItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGraphicsPixmapItem *_t = static_cast<MyGraphicsPixmapItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGraphicsPixmapItem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGraphicsPixmapItem::mousePress)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyGraphicsPixmapItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyGraphicsPixmapItem.data,
      qt_meta_data_MyGraphicsPixmapItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGraphicsPixmapItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsPixmapItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsPixmapItem.stringdata0))
        return static_cast<void*>(const_cast< MyGraphicsPixmapItem*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< MyGraphicsPixmapItem*>(this));
    return QObject::qt_metacast(_clname);
}

int MyGraphicsPixmapItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MyGraphicsPixmapItem::mousePress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GraphicsView_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsView_t qt_meta_stringdata_GraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GraphicsView"
QT_MOC_LITERAL(1, 13, 14), // "DrawRectSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "mousePositionSignal"
QT_MOC_LITERAL(4, 49, 15), // "PosChangeSignal"
QT_MOC_LITERAL(5, 65, 16), // "mouseClickSignal"
QT_MOC_LITERAL(6, 82, 19), // "mouseDblClickSignal"
QT_MOC_LITERAL(7, 102, 13), // "DrawOneSignal"
QT_MOC_LITERAL(8, 116, 10), // "UpdateSlot"
QT_MOC_LITERAL(9, 127, 5), // "value"
QT_MOC_LITERAL(10, 133, 17), // "mousePositionSlot"
QT_MOC_LITERAL(11, 151, 12) // "DrawRectSlot"

    },
    "GraphicsView\0DrawRectSignal\0\0"
    "mousePositionSignal\0PosChangeSignal\0"
    "mouseClickSignal\0mouseDblClickSignal\0"
    "DrawOneSignal\0UpdateSlot\0value\0"
    "mousePositionSlot\0DrawRectSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       3,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       7,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   77,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x0a /* Public */,
      11,    2,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QRect, QMetaType::QPen,    2,    2,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, QMetaType::QRect, QMetaType::QPen,    2,    2,

       0        // eod
};

void GraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsView *_t = static_cast<GraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DrawRectSignal((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< QPen(*)>(_a[2]))); break;
        case 1: _t->mousePositionSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->PosChangeSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->mouseClickSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->mouseDblClickSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 5: _t->DrawOneSignal(); break;
        case 6: _t->UpdateSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->mousePositionSlot((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 8: _t->DrawRectSlot((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< QPen(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicsView::*_t)(QRect , QPen );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::DrawRectSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::mousePositionSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::PosChangeSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::mouseClickSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::mouseDblClickSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::DrawOneSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject GraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GraphicsView.data,
      qt_meta_data_GraphicsView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsView.stringdata0))
        return static_cast<void*>(const_cast< GraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GraphicsView::DrawRectSignal(QRect _t1, QPen _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicsView::mousePositionSignal(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphicsView::PosChangeSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphicsView::mouseClickSignal(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphicsView::mouseDblClickSignal(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphicsView::DrawOneSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
