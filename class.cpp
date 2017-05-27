#include "class.h"
#include <QDebug>

baseComputer::baseComputer(int id, int cpu, int ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
}

void baseComputer::print(){
    qDebug() <<"bspc:"<< id<<cpu<<ram;
}

officeComputer::officeComputer(int id,int cpu,int ram,QString display,QString printer)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->printer=printer;
}

void officeComputer::print(){    
    qDebug()<< "ofpc:" << id<<cpu<<ram<<display<<printer;
    baseComputer::print();
}

lectureComputer::lectureComputer(int id, int cpu, int ram, QString display, QString projector)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->projector=projector;

}
