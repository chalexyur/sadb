#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

#include "data.h"
#include "factory.h"

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    NewDialog(QWidget *parent, Data *d_ptr, Factory *f_ptr);
    ~NewDialog();
    void DisableAll();
    void addPC();
    void upd_room();
    Data *d_ptr;
    Factory *f_ptr;

private slots:

    void on_typeBox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_H
