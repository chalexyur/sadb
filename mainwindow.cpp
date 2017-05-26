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
  QVector<baseComputer> vecpc;
  //officeComputer *newpc=new officeComputer;
  //vecpc.push_back(newpc);
  baseComputer* mypc = new officeComputer;


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

void MainWindow::on_pushButton_clicked()
{
  switch (ui->comboBox->currentIndex()) {
    case 0:{
        officeComputer *newpc = new officeComputer;
        newpc->cpu=ui->lineEditCpu->text().toInt();
       newpc->ram= ui->lineEditRam->text().toInt();
       newpc->display= ui->lineEditDisplay->text();
       newpc->printer= ui->lineEditPrinter->text();
      break;
      }
    default:
      break;
    }
}
