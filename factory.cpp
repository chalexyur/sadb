#include "factory.h"

Factory::Factory()
{

}

void Factory::createObject(InterfaceClass* classPtr, Agregator &ag)
{
    // здесь может быть любого рода проверка
    ag.content.push_back(classPtr);
}

void Factory::createObject(InheritedClass* classPtr, Agregator &ag)
{
    // здесь может быть любого рода проверка
    createObject(dynamic_cast<InterfaceClass*>(classPtr), ag);
}
