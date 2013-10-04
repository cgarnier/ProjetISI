/****************************************************************************
** Meta object code from reading C++ file 'my_scene.h'
**
** Created: Wed Oct 10 16:50:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "my_scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyScene[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    9,    8,    8, 0x05,
      44,   41,    8,    8, 0x05,
      78,   71,    8,    8, 0x05,
     106,  103,    8,    8, 0x05,
     132,  103,    8,    8, 0x05,
     155,  103,    8,    8, 0x05,
     186,  103,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     214,    9,    8,    8, 0x0a,
     240,   41,    8,    8, 0x0a,
     264,   71,    8,    8, 0x0a,
     286,  103,    8,    8, 0x0a,
     309,  103,    8,    8, 0x0a,
     329,  103,    8,    8, 0x0a,
     357,  103,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyScene[] = {
    "MyScene\0\0co\0sigCurrentObjectChanged(int)\0"
    "dm\0sigDisplayModeChanged(int)\0radius\0"
    "sigRadiusChanged(double)\0on\0"
    "sigWireframeChanged(bool)\0"
    "sigSmoothChanged(bool)\0"
    "sigDisplayNormalsChanged(bool)\0"
    "sigFlipNormalsChanged(bool)\0"
    "slotSetCurrentObject(int)\0"
    "slotSetDisplayMode(int)\0slotSetRadius(double)\0"
    "slotSetWireframe(bool)\0slotSetSmooth(bool)\0"
    "slotSetDisplayNormals(bool)\0"
    "slotSetFlipNormals(bool)\0"
};

const QMetaObject MyScene::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyScene,
      qt_meta_data_MyScene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyScene))
        return static_cast<void*>(const_cast< MyScene*>(this));
    return QObject::qt_metacast(_clname);
}

int MyScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigCurrentObjectChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: sigDisplayModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: sigRadiusChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: sigWireframeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: sigSmoothChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: sigDisplayNormalsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: sigFlipNormalsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: slotSetCurrentObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: slotSetDisplayMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: slotSetRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: slotSetWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: slotSetSmooth((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: slotSetDisplayNormals((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: slotSetFlipNormals((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyScene::sigCurrentObjectChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyScene::sigDisplayModeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyScene::sigRadiusChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyScene::sigWireframeChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyScene::sigSmoothChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyScene::sigDisplayNormalsChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyScene::sigFlipNormalsChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
