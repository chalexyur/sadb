#ifndef AGREGATOR_H
#define AGREGATOR_H
#include "class.h"
#include <vector>


class Agregator
{

public:
    QString param;
    std::vector<InterfaceClass*> content;
    Agregator(QString param);

    void print();
};
#endif // AGREGATOR_H
