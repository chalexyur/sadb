#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

class AbstractFactory{
public:
    virtual void createObject(InterfaceClass* classPtr, Agregator &ag) = 0;
};

#endif // ABSTRACTFACTORY_H
