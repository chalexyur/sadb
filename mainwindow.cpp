#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "class.h"
#include "QTableWidget"
#include "QString"


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
    /*QVector<officeComputer> ofpc;
    QVector<lectureComputer> lcpc;
    QVector<programmingComputer> prpc;
    QVector<graphicComputer> grpc;
    QVector<server> srvpc;
    QVector<baseComputer> vecpc;
    officeComputer *newpc=new officeComputer;
    vecpc.push_back(newpc);
    baseComputer* mypc = new officeComputer;*/

    updRooms();
}


void MainWindow::updRooms(){
    ui->roomCB->clear();
    for(unsigned i=0; i<data.room.size(); i++){
        ui->roomCB->addItem(data.room.at(i).room);
    }

}

void MainWindow::on_menuNew_triggered()
{
    Data *d_ptr=&data;
    Factory *f_ptr=&factory;
    NewDialog* objNewDialog = new NewDialog(this, d_ptr, f_ptr);    
    if(objNewDialog->exec()==QDialog::Accepted){
       emit ui->roomCB->activated(ui->roomCB->currentIndex());
    }
}

void MainWindow::on_menuExit_triggered()
{
    QCoreApplication::exit();
}

void MainWindow::on_newRoomLE_textEdited()
{
    if(ui->newRoomLE->text().isEmpty())
        ui->addRoomBtn->setEnabled(false);
    else
        ui->addRoomBtn->setEnabled(true);
}

void MainWindow::on_addRoomBtn_clicked()
{
    data.room.push_back(Rooms(ui->newRoomLE->text()));
    ui->newRoomLE->clear();
    ui->addRoomBtn->setEnabled(false);
    updRooms();
}

void MainWindow::on_roomCB_activated(int index)
{
   // int index = ui->roomCB->currentIndex();
   // qDebug()<<data.room[index].content.size();
    ui->table->setRowCount(0);
    int size = data.room[index].content.size();
    ui->table->setRowCount(size);
    for(int i = 0; i<size; i++){
        QTableWidgetItem *i_id = new QTableWidgetItem();
        i_id->setText(QString::number(data.room[index].content[i]->id));
        ui->table->setItem(i,0, i_id);
        QTableWidgetItem *i_cpu = new QTableWidgetItem();
        i_cpu->setText(QString::number(data.room[index].content[i]->cpu));
        ui->table->setItem(i,1, i_cpu);
        QTableWidgetItem *i_ram = new QTableWidgetItem();
        i_ram->setText(QString::number(data.room[index].content[i]->ram));
        ui->table->setItem(i,2, i_ram);

        QTableWidgetItem *i_display = new QTableWidgetItem();
        baseComputer* c = data.room[index].content[i];
        officeComputer* ap = dynamic_cast<officeComputer*>(c);
        i_display->setText(ap->display);
        ui->table->setItem(i,3, i_display);

        /*QTableWidgetItem *i_cpu = new QTableWidgetItem();
    i_cpu->setText(QString::number(data.agregators[x].content[0]->cpu));
    ui->table->setItem(x,1, i_cpu);
    QTableWidgetItem *i_cpu = new QTableWidgetItem();
    i_cpu->setText(QString::number(data.agregators[x].content[0]->cpu));
    ui->table->setItem(x,1, i_cpu);
    QTableWidgetItem *i_cpu = new QTableWidgetItem();
    i_cpu->setText(QString::number(data.agregators[x].content[0]->cpu));
    ui->table->setItem(x,1, i_cpu);*/
    }


}

void MainWindow::on_delRoomBtn_clicked()
{
    data.room.erase(data.room.begin()+ui->roomCB->currentIndex());
    updRooms();
    emit ui->roomCB->activated(ui->roomCB->currentIndex());
}

void MainWindow::on_updTableBtn_clicked()
{


}
