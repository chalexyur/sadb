#include "factory.h"

Factory::Factory()
{

}

void Factory::createObject(baseComputer* classPtr, Rooms &ag)
{
    // здесь может быть любого рода проверка
    ag.content.push_back(classPtr);
}

void Factory::createObject(officeComputer* classPtr, Rooms &ag)
{
    // здесь может быть любого рода проверка
    createObject(dynamic_cast<baseComputer*>(classPtr), ag);
}
