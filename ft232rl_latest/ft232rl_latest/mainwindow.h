#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <windows.h>
#include "ftd2xx.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    FT_HANDLE handle;
    unsigned char port;
    DWORD numBytes;
    unsigned char TIME;
    int time;

    void cout(QString a);

private slots:

    void ftchek();
    void bitbang();

    void on_dial_valueChanged(int value);

    void on_lineEdit_returnPressed();
    void on_verticalSlider_valueChanged(int value);
};

#endif // MAINWINDOW_H
