#ifndef FACTORY_H
#define FACTORY_H

#include "class.h"
#include "room.h"

class AbstractFactory
{
public:
    virtual void createObject(baseComputer* classPtr, Rooms &room) = 0;
};

class Factory : public AbstractFactory
{
public:
    Factory();
    void createObject(baseComputer* classPtr, Rooms &room);
    void createObject(officeComputer* classPtr, Rooms &room);
    void createObject(lectureComputer* classPtr, Rooms &room);
    void createObject(programmingComputer* classPtr, Rooms &room);
    void createObject(graphicComputer* classPtr, Rooms &room);
    void createObject(server* classPtr, Rooms &room);
};

#endif // FACTORY_H
