#ifndef CLASS_H
#define CLASS_H

#include <QString>
class InterfaceClass
{
    QString interfaceParam;
public:
    InterfaceClass(QString param);
    virtual void print();

};

class InheritedClass : public  InterfaceClass{
    QString ownParam;
public:
    InheritedClass(QString param, QString ownParam);
    void print();
};

class baseComputer{
public:
    int id, cpu, ram;
};

class officeComputer:public baseComputer{
public:
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
