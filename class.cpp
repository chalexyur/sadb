#include "class.h"
#include <QDebug>

baseComputer::baseComputer(int id, int cpu, int ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
}

void baseComputer::print(){
    qDebug() << id<<cpu<<ram;
}

officeComputer::officeComputer(int id,int cpu,int ram,QString display,QString printer)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
}

void officeComputer::print(){
    qDebug() << id<<cpu<<ram<<display<<printer;
    baseComputer::print();
}
