#include "class.h"
#include <QDebug>
#include <mainwindow.h>
#include <QTime>


baseComputer::baseComputer(int cpu, int ram){
    QString str = QString::number(QTime::currentTime().msecsSinceStartOfDay());
    str.append("0");
    this->id = str.toInt();
    this->cpu=cpu;
    this->ram =ram;
}

officeComputer::officeComputer(int cpu,int ram,QString display,QString printer)
    :baseComputer(cpu, ram){
    QString str = QString::number(QTime::currentTime().msecsSinceStartOfDay());
    str.append("1");
    this->id = str.toInt();
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
    QString str = QString::number(QTime::currentTime().msecsSinceStartOfDay());
    str.append("2");
    this->id = str.toInt();
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
    QString str = QString::number(QTime::currentTime().msecsSinceStartOfDay());
    str.append("3");
    this->id = str.toInt();
    this->cpu=cpu;
    this->ram =ram;
    this->display=display;
}

QString programmingComputer::get_display(){
    return this->display;
}

graphicComputer::graphicComputer(int cpu,int ram,QString display,QString gpu)
    :baseComputer(cpu, ram){
    QString str = QString::number(QTime::currentTime().msecsSinceStartOfDay());
    str.append("4");
    this->id = str.toInt();
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
    QString str = QString::number(QTime::currentTime().msecsSinceStartOfDay());
    str.append("5");
    this->id = str.toInt();
    this->cpu=cpu;
    this->ram =ram;
    this->ups=ups;
}

QString server::get_ups(){
    return this->ups;
}
