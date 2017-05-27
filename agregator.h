#ifndef AGREGATOR_H
#define AGREGATOR_H
#include "class.h"
#include <vector>

class Agregator
{

public:
    int param;
    std::vector<baseComputer*> content;
    Agregator(int param);

    void print();
};
#endif // AGREGATOR_H
