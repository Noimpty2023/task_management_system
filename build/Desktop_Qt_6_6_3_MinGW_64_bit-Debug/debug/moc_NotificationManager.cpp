/****************************************************************************
** Meta object code from reading C++ file 'NotificationManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../header/NotificationManager.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotificationManager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSNotificationManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSNotificationManagerENDCLASS = QtMocHelpers::stringData(
    "NotificationManager",
    "onMessageBoxClosed",
    "",
    "result",
    "Task*",
    "task",
    "Reminder*",
    "reminder"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNotificationManagerENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[20];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[6];
    char stringdata5[5];
    char stringdata6[10];
    char stringdata7[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNotificationManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNotificationManagerENDCLASS_t qt_meta_stringdata_CLASSNotificationManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "NotificationManager"
        QT_MOC_LITERAL(20, 18),  // "onMessageBoxClosed"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 6),  // "result"
        QT_MOC_LITERAL(47, 5),  // "Task*"
        QT_MOC_LITERAL(53, 4),  // "task"
        QT_MOC_LITERAL(58, 9),  // "Reminder*"
        QT_MOC_LITERAL(68, 8)   // "reminder"
    },
    "NotificationManager",
    "onMessageBoxClosed",
    "",
    "result",
    "Task*",
    "task",
    "Reminder*",
    "reminder"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNotificationManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject NotificationManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSNotificationManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNotificationManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNotificationManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NotificationManager, std::true_type>,
        // method 'onMessageBoxClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<Task *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Reminder *, std::false_type>
    >,
    nullptr
} };

void NotificationManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotificationManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onMessageBoxClosed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Task*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Reminder*>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *NotificationManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotificationManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNotificationManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NotificationManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
