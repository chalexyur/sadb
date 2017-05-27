#include "class.h"
#include <QDebug>
InheritedClass::InheritedClass(QString param, QString ownParam)
    :InterfaceClass(param){
    this->ownParam = ownParam;
}

void InheritedClass::print(){
    qDebug() << "InheritedClass";
    qDebug() << "ownParam " << ownParam;
    InterfaceClass::print();
}
