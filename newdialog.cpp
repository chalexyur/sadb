#include "newdialog.h"
#include "ui_newdialog.h"
#include "class.h"

NewDialog::NewDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewDialog) {
    ui->setupUi(this);
}

NewDialog::~NewDialog() { delete ui; }

void NewDialog::DisableAll() {
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

void NewDialog::on_comboBox_activated(int index) {
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

void NewDialog::addPC(){
    switch (ui->comboBox->currentIndex()) {
    case 0:{

        ui->lineEditId->text().toInt();
        ui->lineEditCpu->text().toInt();
        ui->lineEditRam->text().toInt();
        ui->lineEditDisplay->text();
        ui->lineEditPrinter->text();

        break;}
    default:
        break;
    }
}
