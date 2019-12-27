/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created: Sun Dec 19 23:54:01 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../glwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   10,    9,    9, 0x05,
     119,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,    9,    9,    9, 0x0a,
     159,    9,    9,    9, 0x0a,
     177,    9,    9,    9, 0x0a,
     196,    9,    9,    9, 0x0a,
     210,    9,    9,    9, 0x0a,
     221,    9,    9,    9, 0x0a,
     237,    9,    9,    9, 0x0a,
     252,    9,    9,    9, 0x0a,
     277,  275,    9,    9, 0x0a,
     304,    9,    9,    9, 0x0a,
     324,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0ar,ag,ab,dr,dg,db,sr,sg,sb,s\0"
    "ShowMaterialWidget(float,float,float,float,float,float,float,float,flo"
    "at,float)\0"
    "HideMaterialWidget(float*)\0LoadObject()\0"
    "setBBRender(bool)\0setWireframe(bool)\0"
    "ResetCamera()\0AutoZoom()\0OrthoView(bool)\0"
    "Toogle3D(bool)\0UpdateMaterial(float*)\0"
    ",\0LightUpdate(float*,float*)\0"
    "ToogleCulling(bool)\0ToogleZtest(bool)\0"
};

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget,
      qt_meta_data_GLWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ShowMaterialWidget((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10]))); break;
        case 1: HideMaterialWidget((*reinterpret_cast< float*(*)>(_a[1]))); break;
        case 2: LoadObject(); break;
        case 3: setBBRender((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: setWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: ResetCamera(); break;
        case 6: AutoZoom(); break;
        case 7: OrthoView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: Toogle3D((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: UpdateMaterial((*reinterpret_cast< float*(*)>(_a[1]))); break;
        case 10: LightUpdate((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< float*(*)>(_a[2]))); break;
        case 11: ToogleCulling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: ToogleZtest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::ShowMaterialWidget(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7, float _t8, float _t9, float _t10)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLWidget::HideMaterialWidget(float * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
