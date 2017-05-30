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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updRooms(){
    ui->roomCB->clear();
    for(unsigned i=0; i<data.room.size(); i++){
        ui->roomCB->addItem(data.room.at(i).room);
    }
    if(ui->roomCB->currentIndex()>-1){
        ui->delRoomBtn->setEnabled(true);
        ui->addItemBtn->setEnabled(true);
    }else{
        ui->table->setRowCount(0);
        ui->delRoomBtn->setEnabled(false);
        ui->addItemBtn->setEnabled(false);
    }
    emit ui->roomCB->activated(ui->roomCB->currentIndex());
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


    if(ui->roomCB->currentIndex()>-1)
        ui->addItemBtn->setEnabled(true);
    else ui->addItemBtn->setEnabled(false);


    if(ui->roomCB->currentIndex()!=-1){
        ui->table->setRowCount(0);
        int size = data.room[index].pc.size();
        ui->table->setRowCount(size);
        for(int i = 0; i<size; i++){
            QTableWidgetItem *i_id = new QTableWidgetItem();
            i_id->setText(QString::number(data.room[index].pc[i]->id));
            ui->table->setItem(i,0, i_id);
            QTableWidgetItem *i_cpu = new QTableWidgetItem();
            i_cpu->setText(QString::number(data.room[index].pc[i]->cpu));
            ui->table->setItem(i,1, i_cpu);
            QTableWidgetItem *i_ram = new QTableWidgetItem();
            i_ram->setText(QString::number(data.room[index].pc[i]->ram));
            ui->table->setItem(i,2, i_ram);

            QTableWidgetItem *i_display = new QTableWidgetItem();
            i_display->setText(data.room[index].pc[i]->get_display());
            ui->table->setItem(i,3, i_display);
            QTableWidgetItem *i_printer = new QTableWidgetItem();
            i_printer->setText(data.room[index].pc[i]->get_printer());
            ui->table->setItem(i,4, i_printer);
            QTableWidgetItem *i_projector = new QTableWidgetItem();
            i_projector->setText(data.room[index].pc[i]->get_projector());
            ui->table->setItem(i,5, i_projector);
            QTableWidgetItem *i_ups = new QTableWidgetItem();
            i_ups->setText(data.room[index].pc[i]->get_ups());
            ui->table->setItem(i,6, i_ups);
            QTableWidgetItem *i_gpu = new QTableWidgetItem();
            i_gpu->setText(data.room[index].pc[i]->get_gpu());
            ui->table->setItem(i,7, i_gpu);


        }
    }else
        ui->table->setRowCount(0);

    if(ui->table->rowCount()>0){
        ui->delItemBtn->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
    } else{
        ui->delItemBtn->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
    }
}

void MainWindow::on_delRoomBtn_clicked()
{
    data.room.erase(data.room.begin()+ui->roomCB->currentIndex());
    updRooms();
}

void MainWindow::on_delItemBtn_clicked()
{
    int i = ui->roomCB->currentIndex();
    data.room[i].pc.erase(data.room[i].pc.begin()+ui->table->currentRow());
    emit ui->roomCB->activated(ui->roomCB->currentIndex());
}

void MainWindow::on_queryBtn_clicked()
{
    ui->resultList->clear();
    ui->cpuQueryLE->clear();
    ui->ramQueryLE->clear();
    ui->prjQueryLE->clear();
    QListWidgetItem *tmp_item = new QListWidgetItem;;
    for(unsigned i =0; i<data.room.size(); i++){
        for(unsigned j=0; j<data.room[i].pc.size(); j++){
            if(data.room[i].pc[j]->cpu < ui->cpuQueryLE->text().toInt()){
                tmp_item->setText(QString::number(data.room[i].pc[j]->id));
                ui->resultList->addItem(tmp_item);
            }else if(data.room[i].pc[j]->get_projector() == ui->prjQueryLE->text()){
                tmp_item->setText(QString::number(data.room[i].pc[j]->id));
                ui->resultList->addItem(tmp_item);
            }
            else if(data.room[i].pc[j]->ram > ui->ramQueryLE->text().toInt()){
                tmp_item->setText(QString::number(data.room[i].pc[j]->id));
                ui->resultList->addItem(tmp_item);
            }
        }
    }
}

void MainWindow::on_addItemBtn_clicked()
{
    Data *d_ptr=&data;
    Factory *f_ptr=&factory;
    NewDialog* objNewDialog = new NewDialog(this, d_ptr, f_ptr);
    if(objNewDialog->exec()==QDialog::Accepted){
        emit ui->roomCB->activated(ui->roomCB->currentIndex());
    }
}

void MainWindow::on_cpuQueryLE_textChanged(const QString &arg1)
{
    if(ui->cpuQueryLE->text().isEmpty())
        ui->queryBtn->setEnabled(false);
    else
        ui->queryBtn->setEnabled(true);
}

void MainWindow::on_prjQueryLE_textChanged(const QString &arg1)
{
    if(ui->prjQueryLE->text().isEmpty())
        ui->queryBtn->setEnabled(false);
    else
        ui->queryBtn->setEnabled(true);
}

void MainWindow::on_ramQueryLE_textChanged(const QString &arg1)
{
    if(ui->ramQueryLE->text().isEmpty())
        ui->queryBtn->setEnabled(false);
    else
        ui->queryBtn->setEnabled(true);
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked==1)
        ui->cpuQueryLE->setEnabled(true);
    else
        ui->cpuQueryLE->setEnabled(false);
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if(checked==1)
        ui->prjQueryLE->setEnabled(true);
    else
        ui->prjQueryLE->setEnabled(false);
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if(checked==1)
        ui->ramQueryLE->setEnabled(true);
    else
        ui->ramQueryLE->setEnabled(false);
}
