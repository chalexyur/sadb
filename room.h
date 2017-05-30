#ifndef AGREGATOR_H
#define AGREGATOR_H
#include "class.h"
#include <vector>

class Rooms
{

public:
    QString room;
    std::vector<baseComputer*> pc;
    Rooms(QString room);

    void print();
};
#endif // AGREGATOR_H
