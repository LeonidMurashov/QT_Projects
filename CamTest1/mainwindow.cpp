#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QMessageBox>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    camera = new QCamera();//QCameraInfo::defaultCamera());
    connect(camera,SIGNAL(error(QCamera::Error)),this,SLOT(cameraError(QCamera::Error)));

    viewfinder = new QCameraViewfinder;
    viewfinder->setMinimumSize(50,50);
    ui->gridLayout->addWidget(viewfinder);
    camera->setViewfinder(viewfinder);
    camera->setCaptureMode(QCamera::CaptureStillImage);

    imageCapture = new QCameraImageCapture(camera);

    finder = new Finder;
    connect(this,SIGNAL(captured(QString)),finder,SLOT(capturedslot(QString)));
    camera->start();
    i2=0;

}

MainWindow::~MainWindow()
{
    delete imageCapture;
    delete camera;
    delete ui;
}

void MainWindow::cameraError(QCamera::Error)
{
    QMessageBox::warning(this,"Ошибка", "Отсутствует камера");
}

void MainWindow::on_pushButton_clicked()
{

   // ui->label->setText("");
 // for(int i=0; i<2; i++)
 // {
      camera->searchAndLock();
      imageCapture->capture("D:\\робот\\photo.jpg");
      camera->unlock();
      captured("D:\\робот\\photo.jpg");
      //imageCapture->cancelCapture();

   //   while(imageCapture->isReadyForCapture()==0)qDebug("k");
   //}



   /*
    imageCapture->capture("D:\\робот\\1.jpg");
    camera->unlock();
    if(camera->state()==QCamera::ActiveState)qDebug("1");
    if(camera->state()!=QCamera::ActiveState)qDebug("2");
    camera->searchAndLock();
    imageCapture->capture("D:\\робот\\2.jpg");
    */
}
