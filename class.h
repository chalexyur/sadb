#ifndef CLASS_H
#define CLASS_H

#include <QString>

class baseComputer{
public:
    int id, cpu, ram;
};

class officeComputer:public baseComputer{
    QString ownParam;
public:
    officeComputer(int id,int cpu,int ram,QString display,QString printer){
        this->id=id;
        this->cpu=cpu;
        this->ram=ram;
        this->display=display;
        this->printer=printer;
    }
    QString display;
    QString printer;
};

class lectureComputer:public baseComputer{
public:
    QString display;
    QString projector;
};

class programmingComputer:public baseComputer{
public:
    QString display;
};

class graphicComputer:public baseComputer{
public:
    QString display;
    QString gpu;
};

class server:public baseComputer{
public:
    QString ups;
};

#endif // CLASS_H
