#include "newdialog.h"
#include "ui_newdialog.h"
#include "class.h"

#include "room.h"
#include "data.h"
#include "factory.h"
#include "mainwindow.h"

NewDialog::NewDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewDialog) {
    ui->setupUi(this);
}
NewDialog::NewDialog(QWidget *parent, Data *d_ptr, Factory *f_ptr) : QDialog(parent), ui(new Ui::NewDialog) {
    ui->setupUi(this);
    this->d_ptr=d_ptr;
    this->f_ptr=f_ptr;
    upd_room();
}

NewDialog::~NewDialog() { delete ui; }

void NewDialog::upd_room(){
    ui->roomCB->clear();
    for(unsigned i=0; i<d_ptr->room.size(); i++){
        ui->roomCB->addItem(d_ptr->room.at(i).room);
    }
}

void NewDialog::DisableAll() {   
    ui->lineEditCpu->clear();
    ui->lineEditRam->clear();
    ui->lineEditDisplay->clear();
    ui->lineEditPrinter->clear();
    ui->lineEditProjector->clear();
    ui->lineEditUps->clear();
    ui->lineEditGpu->clear();
    ui->label_5->setEnabled(false);
    ui->lineEditDisplay->setEnabled(false);
    ui->label_6->setEnabled(false);
    ui->lineEditPrinter->setEnabled(false);
    ui->label_7->setEnabled(false);
    ui->lineEditProjector->setEnabled(false);
    ui->label_8->setEnabled(false);
    ui->lineEditUps->setEnabled(false);
    ui->label_9->setEnabled(false);
    ui->lineEditGpu->setEnabled(false);
}

void NewDialog::on_buttonBox_accepted()
{
    int  cpu, ram;
    QString display, printer, projector, ups, gpu;

    cpu=ui->lineEditCpu->text().toInt();
    ram=ui->lineEditRam->text().toInt();
    display=ui->lineEditDisplay->text();
    printer=ui->lineEditPrinter->text();
    projector=ui->lineEditProjector->text();
    ups=ui->lineEditUps->text();
    gpu=ui->lineEditGpu->text();

    switch (ui->typeCB->currentIndex()) {

    case 0:{
        ptr = new officeComputer(cpu,ram,display,printer);
        break;
    }
    case 1:{
        ptr = new lectureComputer(cpu,ram,display,projector);
        break;
    }
    case 2:{
        ptr = new programmingComputer(cpu,ram,display);
        break;
    }
    case 3:{
        ptr = new graphicComputer(cpu,ram,display,gpu);
        break;
    }
    case 4:{
        ptr = new server(cpu,ram,ups);
        break;
    }
    default:
        break;
    }
    f_ptr->createObject(ptr, d_ptr->room.at(ui->roomCB->currentIndex()));
}

void NewDialog::on_typeCB_currentIndexChanged(int index)
{
    switch (index) {
    case 0: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        ui->label_6->setEnabled(true);
        ui->lineEditPrinter->setEnabled(true);
        break;
    }
    case 1: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        ui->label_7->setEnabled(true);
        ui->lineEditProjector->setEnabled(true);
        break;
    }
    case 2: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        break;
    }
    case 3: {
        DisableAll();
        ui->label_5->setEnabled(true);
        ui->lineEditDisplay->setEnabled(true);
        ui->label_9->setEnabled(true);
        ui->lineEditGpu->setEnabled(true);
        break;
    }
    case 4: {
        DisableAll();
        ui->label_8->setEnabled(true);
        ui->lineEditUps->setEnabled(true);
        break;
    }
    }

}
