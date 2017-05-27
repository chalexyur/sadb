#ifndef CLASS_H
#define CLASS_H

#include <QString>

class baseComputer
{

public:
    int id;
    int cpu;
    int ram;
    baseComputer(int id, int cpu, int ram);
    virtual void print();
};

class officeComputer:public baseComputer{
public:    
    QString display;
    QString printer;
    officeComputer(int id,int cpu,int ram,QString display,QString printer);/*{
        this->id=id;
        this->cpu=cpu;
        this->ram=ram;
        this->display=display;
        this->printer=printer;
    }*/
    void print();
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
