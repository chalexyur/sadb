#include "agregator.h"
#include <QDebug>

Agregator::Agregator(int param)
{
    this->param = param;

}

void Agregator::print()
{
    qDebug() << "Agregator param is " << this->param;
    for (unsigned i = 0; i < this->content.size(); ++i)
    {
        this->content.at(i)->print();
    }
}
