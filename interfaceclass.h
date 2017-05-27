#ifndef INTERFACECLASS_H
#define INTERFACECLASS_H

#include <QString>
class InterfaceClass{
    QString interfaceParam;
public:
    InterfaceClass(QString param);
    virtual void print();

};

#endif // INTERFACECLASS_H
