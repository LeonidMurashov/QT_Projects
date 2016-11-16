#ifndef NORMS_H
#define NORMS_H

#include <QDialog>
#include<QFile>
#include<mainwindow.h>
namespace Ui {
class norms;
}

class norms : public QDialog
{
    Q_OBJECT

public:
    explicit norms(MainWindow *parent = 0);
    ~norms();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::norms *ui;
    QFile *file;
};

#endif // NORMS_H
