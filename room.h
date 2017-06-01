#ifndef ROOM_H
#define ROOM_H
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
#endif // ROOM_H
