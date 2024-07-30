/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../widget/widget.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSwidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSwidgetENDCLASS = QtMocHelpers::stringData(
    "widget",
    "on_ButtonSend_clicked",
    "",
    "on_ButtonClear_clicked",
    "on_ButtonAdd_Channel_clicked",
    "on_ButtonAddAcc_clicked",
    "on_ButtonAddPaste_clicked",
    "on_ButtonDeleteChannel_clicked",
    "on_ButtonDeleteAcc_clicked",
    "on_ButtonDeletePaste_clicked",
    "on_addPaste_clicked",
    "on_messageText_textChanged",
    "on_addSybSplit_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSwidgetENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[7];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[29];
    char stringdata5[24];
    char stringdata6[26];
    char stringdata7[31];
    char stringdata8[27];
    char stringdata9[29];
    char stringdata10[20];
    char stringdata11[27];
    char stringdata12[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSwidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSwidgetENDCLASS_t qt_meta_stringdata_CLASSwidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "widget"
        QT_MOC_LITERAL(7, 21),  // "on_ButtonSend_clicked"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 22),  // "on_ButtonClear_clicked"
        QT_MOC_LITERAL(53, 28),  // "on_ButtonAdd_Channel_clicked"
        QT_MOC_LITERAL(82, 23),  // "on_ButtonAddAcc_clicked"
        QT_MOC_LITERAL(106, 25),  // "on_ButtonAddPaste_clicked"
        QT_MOC_LITERAL(132, 30),  // "on_ButtonDeleteChannel_clicked"
        QT_MOC_LITERAL(163, 26),  // "on_ButtonDeleteAcc_clicked"
        QT_MOC_LITERAL(190, 28),  // "on_ButtonDeletePaste_clicked"
        QT_MOC_LITERAL(219, 19),  // "on_addPaste_clicked"
        QT_MOC_LITERAL(239, 26),  // "on_messageText_textChanged"
        QT_MOC_LITERAL(266, 22)   // "on_addSybSplit_clicked"
    },
    "widget",
    "on_ButtonSend_clicked",
    "",
    "on_ButtonClear_clicked",
    "on_ButtonAdd_Channel_clicked",
    "on_ButtonAddAcc_clicked",
    "on_ButtonAddPaste_clicked",
    "on_ButtonDeleteChannel_clicked",
    "on_ButtonDeleteAcc_clicked",
    "on_ButtonDeletePaste_clicked",
    "on_addPaste_clicked",
    "on_messageText_textChanged",
    "on_addSybSplit_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSwidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSwidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSwidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSwidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<widget, std::true_type>,
        // method 'on_ButtonSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonClear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonAdd_Channel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonAddAcc_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonAddPaste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonDeleteChannel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonDeleteAcc_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonDeletePaste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addPaste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_messageText_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addSybSplit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ButtonSend_clicked(); break;
        case 1: _t->on_ButtonClear_clicked(); break;
        case 2: _t->on_ButtonAdd_Channel_clicked(); break;
        case 3: _t->on_ButtonAddAcc_clicked(); break;
        case 4: _t->on_ButtonAddPaste_clicked(); break;
        case 5: _t->on_ButtonDeleteChannel_clicked(); break;
        case 6: _t->on_ButtonDeleteAcc_clicked(); break;
        case 7: _t->on_ButtonDeletePaste_clicked(); break;
        case 8: _t->on_addPaste_clicked(); break;
        case 9: _t->on_messageText_textChanged(); break;
        case 10: _t->on_addSybSplit_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSwidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
