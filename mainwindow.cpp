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

    setData();
}


void MainWindow::setData(){
    ui->ag_cb->clear();
    for(int i=0; i<data.agregators.size(); i++){
        ui->ag_cb->addItem(data.agregators.at(i).param);
    }

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
    int id, cpu, ram;
    QString display, printer, projector, ups, gpu;

    id=ui->lineEditId->text().toInt();
    cpu=ui->lineEditCpu->text().toInt();
    ram=ui->lineEditRam->text().toInt();
    display=ui->lineEditDisplay->text();
    printer=ui->lineEditPrinter->text();
    projector=ui->lineEditProjector->text();
    ups=ui->lineEditUps->text();
    gpu=ui->lineEditGpu->text();



    switch (ui->comboBox->currentIndex()) {
    case 0:{
        baseComputer *ptr = new officeComputer(id,cpu,ram,display,printer);
        //ag_count++;
        //data.agregators.push_back(Agregator(0));

        factory.createObject(ptr, data.agregators.at(ui->ag_cb->currentIndex()));
        data.print();
        break;
    }
    case 1:{
        baseComputer *ptr = new lectureComputer(id,cpu,ram,display,projector);
        //ag_count++;
        //data.agregators.push_back(Agregator(0));
        factory.createObject(ptr, data.agregators.back());
        data.print();
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int agr_idx= ui->ag_cb->currentIndex();
    qDebug()<<data.agregators[agr_idx].content.size();
    ui->table->setRowCount(0);
    int size = data.agregators[agr_idx].content.size();
    ui->table->setRowCount(size);
    for(int i = 0; i<size; i++){
        QTableWidgetItem *i_id = new QTableWidgetItem();
        i_id->setText(QString::number(data.agregators[agr_idx].content[i]->id));
        ui->table->setItem(i,0, i_id);
        QTableWidgetItem *i_cpu = new QTableWidgetItem();
        i_cpu->setText(QString::number(data.agregators[agr_idx].content[i]->cpu));
        ui->table->setItem(i,1, i_cpu);
        QTableWidgetItem *i_ram = new QTableWidgetItem();
        i_ram->setText(QString::number(data.agregators[agr_idx].content[i]->ram));
        ui->table->setItem(i,2, i_ram);









        QTableWidgetItem *i_display = new QTableWidgetItem();

        baseComputer* c = data.agregators[agr_idx].content[i];
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

void MainWindow::DisableAll() {
    ui->lineEditId->clear();
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

void MainWindow::on_comboBox_activated(int index) {
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

void MainWindow::on_pushButton_3_clicked()
{
    data.agregators.push_back(Agregator(ui->lineEdit->text()));
    setData();
}
