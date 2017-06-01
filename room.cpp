#include "room.h"
#include <QDebug>

Rooms::Rooms(QString room)
{
    this->room = room;
}

void Rooms::print()
{
    /*qDebug() << "Agregator param is " << this->room;
    for (unsigned i = 0; i < this->content.size(); ++i)
    {
        this->content.at(i)->print();
    }*/
}
