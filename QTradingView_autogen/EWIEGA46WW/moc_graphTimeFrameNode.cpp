/****************************************************************************
** Meta object code from reading C++ file 'graphTimeFrameNode.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphTimeFrameNode.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphTimeFrameNode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_graphTimeFrameNode_t {
    uint offsetsAndSizes[2];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_graphTimeFrameNode_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_graphTimeFrameNode_t qt_meta_stringdata_graphTimeFrameNode = {
    {
        QT_MOC_LITERAL(0, 18)   // "graphTimeFrameNode"
    },
    "graphTimeFrameNode"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_graphTimeFrameNode[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject graphTimeFrameNode::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsItemGroup::staticMetaObject>(),
    qt_meta_stringdata_graphTimeFrameNode.offsetsAndSizes,
    qt_meta_data_graphTimeFrameNode,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_graphTimeFrameNode_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<graphTimeFrameNode, std::true_type>
    >,
    nullptr
} };

void graphTimeFrameNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *graphTimeFrameNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graphTimeFrameNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_graphTimeFrameNode.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QObject"))
        return static_cast< QObject*>(this);
    return QGraphicsItemGroup::qt_metacast(_clname);
}

int graphTimeFrameNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsItemGroup::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
