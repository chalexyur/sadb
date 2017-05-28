#ifndef FACTORY_H
#define FACTORY_H

#include "class.h"
#include "room.h"

class AbstractFactory
{
public:
    virtual void createObject(baseComputer* classPtr, Rooms &ag) = 0;
};

class Factory : public AbstractFactory
{
public:
    Factory();
    void createObject(baseComputer* classPtr, Rooms &ag);
    void createObject(officeComputer* classPtr, Rooms &ag);
};

#endif // FACTORY_H
