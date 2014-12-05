/****************************************************************************
** Meta object code from reading C++ file 'anatomyshow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anatomyshow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anatomyshow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnatomyShow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      46,   12,   12,   12, 0x0a,
      78,   12,   12,   12, 0x0a,
     113,   12,   12,   12, 0x0a,
     140,   12,   12,   12, 0x0a,
     161,   12,   12,   12, 0x0a,
     184,   12,   12,   12, 0x0a,
     205,   12,   12,   12, 0x0a,
     223,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AnatomyShow[] = {
    "AnatomyShow\0\0ToolbarProcessFromImageClicked()\0"
    "ToolbarProcessFromMeshClicked()\0"
    "ToolbarProcessFromAnatomyClicked()\0"
    "ImageSegmentationClicked()\0"
    "MeshProcessClicked()\0AnatomyDefineClicked()\0"
    "AnatomyShowClicked()\0ShowNextStep(int)\0"
    "ShowPrevStep()\0"
};

void AnatomyShow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AnatomyShow *_t = static_cast<AnatomyShow *>(_o);
        switch (_id) {
        case 0: _t->ToolbarProcessFromImageClicked(); break;
        case 1: _t->ToolbarProcessFromMeshClicked(); break;
        case 2: _t->ToolbarProcessFromAnatomyClicked(); break;
        case 3: _t->ImageSegmentationClicked(); break;
        case 4: _t->MeshProcessClicked(); break;
        case 5: _t->AnatomyDefineClicked(); break;
        case 6: _t->AnatomyShowClicked(); break;
        case 7: _t->ShowNextStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ShowPrevStep(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AnatomyShow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AnatomyShow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnatomyShow,
      qt_meta_data_AnatomyShow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnatomyShow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnatomyShow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnatomyShow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnatomyShow))
        return static_cast<void*>(const_cast< AnatomyShow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AnatomyShow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
