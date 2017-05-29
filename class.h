#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QTime>

class baseComputer
{

public:
    int id;
    int cpu;
    int ram;
    baseComputer(int cpu, int ram);
    virtual QString get_display()=0;
    virtual QString get_printer()=0;
    virtual QString get_projector()=0;
    virtual QString get_gpu()=0;
    virtual QString get_ups()=0;
};

class officeComputer:public baseComputer{
public:    
    QString display;
    QString printer;
    officeComputer(int cpu,int ram,QString display,QString printer);
    QString get_display();
    QString get_printer();
    QString get_projector(){return "";}
    QString get_gpu(){return "";}
    QString get_ups(){return "";}
};

class lectureComputer:public baseComputer{
public:
    QString display;
    QString projector;
    lectureComputer(int cpu,int ram,QString display,QString projector);
    QString get_display();
    QString get_printer(){return "";}
    QString get_projector();
    QString get_gpu(){return "";}
    QString get_ups(){return "";}
};

class programmingComputer:public baseComputer{
public:
    QString display;
    programmingComputer(int cpu,int ram,QString display);
    QString get_display();
    QString get_printer(){return "";}
    QString get_projector(){return "";}
    QString get_gpu(){return "";}
    QString get_ups(){return "";}
};

class graphicComputer:public baseComputer{
public:
    QString display;
    QString gpu;
    graphicComputer(int cpu,int ram,QString display,QString gpu);
    QString get_display();
    QString get_printer(){return "";}
    QString get_projector(){return "";}
    QString get_gpu();
    QString get_ups(){return "";}
};

class server:public baseComputer{
public:
    QString ups;
    server(int cpu,int ram,QString ups);
    QString get_display(){return "";}
    QString get_printer(){return "";}
    QString get_projector(){return "";}
    QString get_gpu(){return "";}
    QString get_ups();
};

#endif // CLASS_H
