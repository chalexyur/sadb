#ifndef AGREGATOR_H
#define AGREGATOR_H
#include "interfaceclass.h"
#include <vector>

class Agregator
{

public:
    QString param;
    std::vector<baseComputer*> content;
    Agregator(QString param);

    void print();
};
#endif // AGREGATOR_H
