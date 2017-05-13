#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    ~NewDialog();
    void DisableAll();

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_H
