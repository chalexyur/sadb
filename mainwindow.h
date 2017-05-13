#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "newdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_menuNew_triggered();

    void on_menuExit_triggered();

private:
    Ui::MainWindow *ui;
    NewDialog *objNewDialog;
};



class baseComputer{
public:
    int id, cpu, ram;
};

class officeComputer:public baseComputer{
public:
    int display_size;
    std::string printer;
};

class lecturComputer:public baseComputer{
public:
    int display_size;
    std::string projector;
};

class programmingComputer:public baseComputer{
public:
    int display_size;
};

class graphicComputer:public baseComputer{
public:
    int display_size;
    std::string gpu;
};

class server:public baseComputer{
public:
    std::string ups;
};

#endif // MAINWINDOW_H
