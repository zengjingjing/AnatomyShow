/****************************************************************************
** Meta object code from reading C++ file 'meshprocess.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../meshprocess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meshprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MeshProcess[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      33,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   12,   12,   12, 0x0a,
      67,   12,   12,   12, 0x0a,
      86,   12,   12,   12, 0x0a,
      97,   12,   12,   12, 0x0a,
     108,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MeshProcess[] = {
    "MeshProcess\0\0signalNextStep(int)\0"
    "signalPrevStep()\0OpenSourceMesh()\0"
    "StartMeshProcess()\0SaveMesh()\0NextStep()\0"
    "PrevStep()\0"
};

void MeshProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MeshProcess *_t = static_cast<MeshProcess *>(_o);
        switch (_id) {
        case 0: _t->signalNextStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalPrevStep(); break;
        case 2: _t->OpenSourceMesh(); break;
        case 3: _t->StartMeshProcess(); break;
        case 4: _t->SaveMesh(); break;
        case 5: _t->NextStep(); break;
        case 6: _t->PrevStep(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MeshProcess::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MeshProcess::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MeshProcess,
      qt_meta_data_MeshProcess, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MeshProcess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MeshProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MeshProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MeshProcess))
        return static_cast<void*>(const_cast< MeshProcess*>(this));
    return QDialog::qt_metacast(_clname);
}

int MeshProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MeshProcess::signalNextStep(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeshProcess::signalPrevStep()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
