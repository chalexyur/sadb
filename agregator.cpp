#include "agregator.h"
#include <QDebug>

Agregator::Agregator(QString param)
{
    this->param = param;

}

void Agregator::print()
{
    qDebug() << "Agregator : ";
    qDebug() << "param is " << this->param;
    for (int i = 0; i < this->content.size(); ++i)
    {
        this->content.at(i)->print();
    }
}
