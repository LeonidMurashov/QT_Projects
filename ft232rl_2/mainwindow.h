#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"ft232rl_class.h"
#include<QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void maininmainwindow();
private:
    Ui::MainWindow *ui;
    ft232rl_class *Device;

    int TIME;

    QThread thread;
    void cout(QString str);

private slots:
        void refreshslot(QString str);
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

        void on_lineEdit_returnPressed();

        void on_dial_sliderMoved(int position);

        void on_dial_actionTriggered(int action);

        void on_dial_sliderPressed();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

signals:
        void stopthread();
};

#endif // MAINWINDOW_H
