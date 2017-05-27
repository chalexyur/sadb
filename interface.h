#ifndef INTERFACE_H
#define INTERFACE_H

#include <QString>
class InterfaceClass
{
    QString interfaceParam;
public:
    InterfaceClass(QString param);
    virtual void print();

};

#endif // INTERFACE_H
