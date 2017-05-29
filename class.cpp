#include "class.h"
#include <QDebug>
#include <mainwindow.h>

baseComputer::baseComputer(int cpu, int ram){
    this->id =0;
    this->cpu=cpu;
    this->ram =ram;
}

officeComputer::officeComputer(int cpu,int ram,QString display,QString printer)
    :baseComputer(cpu, ram){
    this->id =1;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->printer=printer;
}

QString officeComputer::get_display(){
    return this->display;
}

QString officeComputer::get_printer(){
    return this->printer;
}

lectureComputer::lectureComputer(int cpu, int ram, QString display, QString projector)
    :baseComputer(cpu, ram){
    this->id =2;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->projector=projector;
}

QString lectureComputer::get_display(){
    return this->display;
}

QString lectureComputer::get_projector(){
    return this->projector;
}

programmingComputer::programmingComputer(int cpu,int ram,QString display)
    :baseComputer(cpu, ram){
    this->id =3;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
}

QString programmingComputer::get_display(){
    return this->display;
}

graphicComputer::graphicComputer(int cpu,int ram,QString display,QString gpu)
    :baseComputer(cpu, ram){
    this->id =4;
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
    this->gpu=gpu;
}

QString graphicComputer::get_display(){
    return this->display;
}

QString graphicComputer::get_gpu(){
    return this->gpu;
}

server::server(int cpu,int ram,QString ups)
    :baseComputer(cpu, ram){
    this->id =5;
    this->cpu=cpu;
    this->ram =ram;
    this->ups=ups;
}

QString server::get_ups(){
    return this->ups;
}
