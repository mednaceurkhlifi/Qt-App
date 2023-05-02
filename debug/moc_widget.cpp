/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../2a3-2a3-smart-rdi-center-integration_3/2a3-2a3-smart-rdi-center-integration/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widget_t {
    QByteArrayData data[20];
    char stringdata0[360];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widget_t qt_meta_stringdata_widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "widget"
QT_MOC_LITERAL(1, 7, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "on_supprimer_clicked"
QT_MOC_LITERAL(4, 48, 19), // "on_modifier_clicked"
QT_MOC_LITERAL(5, 68, 27), // "on_table_materiel_activated"
QT_MOC_LITERAL(6, 96, 5), // "index"
QT_MOC_LITERAL(7, 102, 17), // "on_search_clicked"
QT_MOC_LITERAL(8, 120, 17), // "on_filter_clicked"
QT_MOC_LITERAL(9, 138, 14), // "on_pdf_clicked"
QT_MOC_LITERAL(10, 153, 22), // "on_mediaplayer_clicked"
QT_MOC_LITERAL(11, 176, 25), // "on_rechercher_textChanged"
QT_MOC_LITERAL(12, 202, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(13, 224, 4), // "arg1"
QT_MOC_LITERAL(14, 229, 21), // "on_statistics_clicked"
QT_MOC_LITERAL(15, 251, 12), // "update_label"
QT_MOC_LITERAL(16, 264, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(17, 288, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(18, 312, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(19, 336, 23) // "on_pushButton_6_clicked"

    },
    "widget\0on_ajouter_clicked\0\0"
    "on_supprimer_clicked\0on_modifier_clicked\0"
    "on_table_materiel_activated\0index\0"
    "on_search_clicked\0on_filter_clicked\0"
    "on_pdf_clicked\0on_mediaplayer_clicked\0"
    "on_rechercher_textChanged\0"
    "on_comboBox_activated\0arg1\0"
    "on_statistics_clicked\0update_label\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    1,   97,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    1,  105,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widget *_t = static_cast<widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouter_clicked(); break;
        case 1: _t->on_supprimer_clicked(); break;
        case 2: _t->on_modifier_clicked(); break;
        case 3: _t->on_table_materiel_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_search_clicked(); break;
        case 5: _t->on_filter_clicked(); break;
        case 6: _t->on_pdf_clicked(); break;
        case 7: _t->on_mediaplayer_clicked(); break;
        case 8: _t->on_rechercher_textChanged(); break;
        case 9: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_statistics_clicked(); break;
        case 11: _t->update_label(); break;
        case 12: _t->on_pushButton_3_clicked(); break;
        case 13: _t->on_pushButton_4_clicked(); break;
        case 14: _t->on_pushButton_5_clicked(); break;
        case 15: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_widget.data,
      qt_meta_data_widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
