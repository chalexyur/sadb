#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "class.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  startup();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::startup(){
  QVector<officeComputer> ofpc;
  QVector<lectureComputer> lcpc;
  QVector<programmingComputer> prpc;
  QVector<graphicComputer> grpc;
  QVector<server> srvpc;
}

void MainWindow::on_menuNew_triggered()
{
  NewDialog* objNewDialog = new NewDialog();
  if(objNewDialog->exec()==QDialog::Accepted){
      objNewDialog->addPC();
      QTableWidgetItem *item_00 = new QTableWidgetItem();
      item_00->setText("as");
      ui->table->setItem(0,0,item_00);
    }
}

void MainWindow::on_menuExit_triggered()
{
  QCoreApplication::exit();
}
