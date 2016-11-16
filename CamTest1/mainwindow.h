#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "finder.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void cameraError(QCamera::Error);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QCamera * camera;
    QCameraImageCapture *imageCapture;
    QCameraViewfinder *viewfinder;
    Finder *finder;

    int i2;
signals:
    void captured(QString);
};

#endif // MAINWINDOW_H
