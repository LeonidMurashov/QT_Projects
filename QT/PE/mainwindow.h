#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unit.h"
#define ADRESS "//home/myfiles/test.txt"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool write(Unit *unit);
    void del(int num);

public slots:
    void on_pushButton_clicked();
    void clean();
private:
    Ui::MainWindow *ui;
    QVector<Unit*> pupils;
    QVBoxLayout *a = new QVBoxLayout;


};

#endif // MAINWINDOW_H
