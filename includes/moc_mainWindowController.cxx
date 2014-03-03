/****************************************************************************
** Meta object code from reading C++ file 'mainWindowController.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainWindowController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindowController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   53,   53,   53, 0x08,
      54,   53,   53,   53, 0x08,
      86,   53,   53,   53, 0x08,
     117,   53,   53,   53, 0x08,
     142,   53,   53,   53, 0x08,
     175,   53,   53,   53, 0x08,
     206,   53,   53,   53, 0x08,
     238,   53,   53,   53, 0x08,
     275,  309,   53,   53, 0x08,
     311,  309,   53,   53, 0x08,
     345,  309,   53,   53, 0x08,
     379,  309,   53,   53, 0x08,
     413,  309,   53,   53, 0x08,
     447,  309,   53,   53, 0x08,
     481,  309,   53,   53, 0x08,
     515,  309,   53,   53, 0x08,
     549,   53,   53,   53, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowController[] = {
    "MainWindowController\0"
    "on_createWindowButton_clicked()\0\0"
    "on_leapActivateButton_clicked()\0"
    "on_actionOpen_File_triggered()\0"
    "on_actionNew_triggered()\0"
    "on_actionOpen_Config_triggered()\0"
    "on_setKeystoneButton_clicked()\0"
    "on_saveKeystoneButton_clicked()\0"
    "on_windowIndexSpinBox_valueChanged()\0"
    "on_x1SpinBox_valueChanged(double)\0d\0"
    "on_y1SpinBox_valueChanged(double)\0"
    "on_x2SpinBox_valueChanged(double)\0"
    "on_y2SpinBox_valueChanged(double)\0"
    "on_x3SpinBox_valueChanged(double)\0"
    "on_y3SpinBox_valueChanged(double)\0"
    "on_x4SpinBox_valueChanged(double)\0"
    "on_y4SpinBox_valueChanged(double)\0"
    "keystoneSpinBoxCommon()\0"
};

void MainWindowController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindowController *_t = static_cast<MainWindowController *>(_o);
        switch (_id) {
        case 0: _t->on_createWindowButton_clicked(); break;
        case 1: _t->on_leapActivateButton_clicked(); break;
        case 2: _t->on_actionOpen_File_triggered(); break;
        case 3: _t->on_actionNew_triggered(); break;
        case 4: _t->on_actionOpen_Config_triggered(); break;
        case 5: _t->on_setKeystoneButton_clicked(); break;
        case 6: _t->on_saveKeystoneButton_clicked(); break;
        case 7: _t->on_windowIndexSpinBox_valueChanged(); break;
        case 8: _t->on_x1SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_y1SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_x2SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_y2SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_x3SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_y3SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_x4SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_y4SpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->keystoneSpinBoxCommon(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindowController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindowController::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowController,
      qt_meta_data_MainWindowController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindowController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindowController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindowController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowController))
        return static_cast<void*>(const_cast< MainWindowController*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
