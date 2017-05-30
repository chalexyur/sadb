#include "factory.h"

Factory::Factory()
{

}

void Factory::createObject(baseComputer* classPtr, Rooms &room)
{
    room.pc.push_back(classPtr);
}

void Factory::createObject(officeComputer* classPtr, Rooms &room)
{
    createObject(dynamic_cast<baseComputer*>(classPtr), room);
}

void Factory::createObject(lectureComputer* classPtr, Rooms &room)
{
    createObject(dynamic_cast<lectureComputer*>(classPtr), room);
}

void Factory::createObject(programmingComputer* classPtr, Rooms &room)
{
    createObject(dynamic_cast<programmingComputer*>(classPtr), room);
}

void Factory::createObject(graphicComputer* classPtr, Rooms &room)
{
    createObject(dynamic_cast<graphicComputer*>(classPtr), room);
}

void Factory::createObject(server* classPtr, Rooms &room)
{
    createObject(dynamic_cast<server*>(classPtr), room);
}
