/****************************************************************************
** Meta object code from reading C++ file 'CustomLabel.h'
**
** Created: Sat Oct 2 23:11:48 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "plugin/CustomLabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CustomLabel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      21,   12,   12,   12, 0x0a,
      30,   12,   12,   12, 0x0a,
      40,   12,   12,   12, 0x0a,
      51,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CustomLabel[] = {
    "CustomLabel\0\0clear()\0addRed()\0addBlue()\0"
    "addGreen()\0addYellow()\0"
};

const QMetaObject CustomLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_CustomLabel,
      qt_meta_data_CustomLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CustomLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CustomLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CustomLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CustomLabel))
        return static_cast<void*>(const_cast< CustomLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int CustomLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clear(); break;
        case 1: addRed(); break;
        case 2: addBlue(); break;
        case 3: addGreen(); break;
        case 4: addYellow(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
