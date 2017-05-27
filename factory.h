#ifndef FACTORY_H
#define FACTORY_H
#include "class.h"
#include "agregator.h"

class AbstractFactory
{
public:
    virtual void createObject(InterfaceClass* classPtr, Agregator &ag) = 0;
};

class Factory : public AbstractFactory
{
public:
    Factory();
    void createObject(InterfaceClass* classPtr, Agregator &ag);
    void createObject(InheritedClass* classPtr, Agregator &ag);
};

#endif // FACTORY_H
