#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "newdialog.h"
#include "data.h"
#include "factory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void setData();

public:
    Data data;
    Factory factory;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startup();
    void DisableAll();

private slots:
    void on_menuNew_triggered();
    void on_comboBox_activated(int index);
    void on_menuExit_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    NewDialog *objNewDialog;
};

#endif // MAINWINDOW_H
