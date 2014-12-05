/****************************************************************************
** Meta object code from reading C++ file 'anatomydefine.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../anatomydefine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anatomydefine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnatomyDefine[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   14,   14,   14, 0x0a,
      45,   14,   14,   14, 0x0a,
      55,   14,   14,   14, 0x0a,
      67,   14,   14,   14, 0x0a,
      79,   14,   14,   14, 0x0a,
      89,   14,   14,   14, 0x0a,
      99,   14,   14,   14, 0x0a,
     110,   14,   14,   14, 0x0a,
     121,   14,   14,   14, 0x0a,
     132,   14,   14,   14, 0x0a,
     143,   14,   14,   14, 0x0a,
     155,   14,   14,   14, 0x0a,
     167,   14,   14,   14, 0x0a,
     183,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AnatomyDefine[] = {
    "AnatomyDefine\0\0signalNextStep(int)\0"
    "SkinAdd()\0SkinSub()\0MuscleAdd()\0"
    "MuscleSub()\0BoneAdd()\0BoneSub()\0"
    "OrganAdd()\0OrganSub()\0NerveAdd()\0"
    "NerveSub()\0ArteryAdd()\0ArterySub()\0"
    "GenerateModel()\0GenerateDone()\0"
};

void AnatomyDefine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AnatomyDefine *_t = static_cast<AnatomyDefine *>(_o);
        switch (_id) {
        case 0: _t->signalNextStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SkinAdd(); break;
        case 2: _t->SkinSub(); break;
        case 3: _t->MuscleAdd(); break;
        case 4: _t->MuscleSub(); break;
        case 5: _t->BoneAdd(); break;
        case 6: _t->BoneSub(); break;
        case 7: _t->OrganAdd(); break;
        case 8: _t->OrganSub(); break;
        case 9: _t->NerveAdd(); break;
        case 10: _t->NerveSub(); break;
        case 11: _t->ArteryAdd(); break;
        case 12: _t->ArterySub(); break;
        case 13: _t->GenerateModel(); break;
        case 14: _t->GenerateDone(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AnatomyDefine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AnatomyDefine::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AnatomyDefine,
      qt_meta_data_AnatomyDefine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnatomyDefine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnatomyDefine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnatomyDefine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnatomyDefine))
        return static_cast<void*>(const_cast< AnatomyDefine*>(this));
    return QDialog::qt_metacast(_clname);
}

int AnatomyDefine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AnatomyDefine::signalNextStep(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
