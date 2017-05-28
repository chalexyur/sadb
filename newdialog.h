#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

#include "data.h"
#include "factory.h"
#include "class.h"

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    NewDialog(QWidget *parent, Data *d_ptr);
    ~NewDialog();
    void DisableAll();
    void addPC();
    void upd_room();
    Data *dptr;

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_H
