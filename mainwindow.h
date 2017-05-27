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
    void startup();

private slots:
    void on_menuNew_triggered();

    void on_menuExit_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    NewDialog *objNewDialog;
};

#endif // MAINWINDOW_H
