#ifndef FACTORY_H
#define FACTORY_H

#include "class.h"
#include "agregator.h"

class AbstractFactory
{
public:
    virtual void createObject(baseComputer* classPtr, Agregator &ag) = 0;
};

class Factory : public AbstractFactory
{
public:
    Factory();
    void createObject(baseComputer* classPtr, Agregator &ag);
    void createObject(officeComputer* classPtr, Agregator &ag);
};

#endif // FACTORY_H
