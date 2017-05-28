#include "class.h"
#include <QDebug>
#include <mainwindow.h>

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
    qDebug()<< "ofpc:" << id<<cpu<<ram<<display<<printer;
}

void officeComputer::print(){    
    qDebug()<< "ofpc:" << id<<cpu<<ram<<display<<printer;

    //baseComputer::print();
}

lectureComputer::lectureComputer(int id, int cpu, int ram, QString display, QString projector)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->projector=projector;
    qDebug()<< "lecpc:" << id<<cpu<<ram<<display<<projector;

}

programmingComputer::programmingComputer(int id,int cpu,int ram,QString display)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    qDebug()<< "progpc:" << id<<cpu<<ram<<display;
}
graphicComputer::graphicComputer(int id,int cpu,int ram,QString display,QString gpu)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->gpu=gpu;
    qDebug()<< "grpc:" << id<<cpu<<ram<<display<<gpu;
}
server::server(int id,int cpu,int ram,QString ups)
    :baseComputer(id, cpu, ram){
    this->id =id;
    this->cpu=cpu;
    this->ram =ram;
    this->ups=ups;
    qDebug()<< "server:" << id<<cpu<<ram<<ups;
}
