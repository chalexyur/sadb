#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuNew_triggered()
{
    objNewDialog = new NewDialog(this);
    objNewDialog->show();
}

void MainWindow::on_menuExit_triggered()
{
    QCoreApplication::exit();
}
