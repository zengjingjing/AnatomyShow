/****************************************************************************
** Meta object code from reading C++ file 'imagesegmentation.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imagesegmentation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagesegmentation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageSegmentation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   18,   18,   18, 0x0a,
      57,   18,   18,   18, 0x0a,
      67,   18,   18,   18, 0x0a,
      87,   18,   18,   18, 0x0a,
     107,   98,   18,   18, 0x0a,
     134,   98,   18,   18, 0x0a,
     153,   98,   18,   18, 0x0a,
     178,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageSegmentation[] = {
    "ImageSegmentation\0\0signalNextStep(int)\0"
    "OpenSourceDICOM()\0OpenBMP()\0"
    "StartSegmentation()\0NextStep()\0position\0"
    "SliderShowSourceDICOM(int)\0"
    "SliderShowBMP(int)\0SliderShowDestDICOM(int)\0"
    "ImageProcessDone()\0"
};

void ImageSegmentation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageSegmentation *_t = static_cast<ImageSegmentation *>(_o);
        switch (_id) {
        case 0: _t->signalNextStep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OpenSourceDICOM(); break;
        case 2: _t->OpenBMP(); break;
        case 3: _t->StartSegmentation(); break;
        case 4: _t->NextStep(); break;
        case 5: _t->SliderShowSourceDICOM((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SliderShowBMP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SliderShowDestDICOM((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ImageProcessDone(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageSegmentation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageSegmentation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ImageSegmentation,
      qt_meta_data_ImageSegmentation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageSegmentation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageSegmentation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageSegmentation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageSegmentation))
        return static_cast<void*>(const_cast< ImageSegmentation*>(this));
    return QDialog::qt_metacast(_clname);
}

int ImageSegmentation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ImageSegmentation::signalNextStep(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
