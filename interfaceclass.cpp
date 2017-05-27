#include "interface.h"
#include <QDebug>
InterfaceClass::InterfaceClass(QString param){
    this->interfaceParam = param;
}

void InterfaceClass::print(){
    qDebug() << "Interface class";
    qDebug() << "param = " << interfaceParam;
}
