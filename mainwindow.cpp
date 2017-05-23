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
    if(objNewDialog->exec()==QDialog::Accepted){
        QTableWidgetItem *item_00 = new QTableWidgetItem();
        item_00->setText("as");
        ui->table->setItem(0,0,item_00);
    }
}

void MainWindow::on_menuExit_triggered()
{
    QCoreApplication::exit();
}
