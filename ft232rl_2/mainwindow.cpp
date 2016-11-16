#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ft232rl_class.h"
#include <QThread>
#include <QScrollBar>

//#define TIME 1
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TIME = 200;
    Device =  new ft232rl_class;
    connect(Device,SIGNAL(refresh(QString)),this,SLOT(refreshslot(QString)));
    connect(this,SIGNAL(stopthread()),Device,SLOT(swich_of()));
    Device->moveToThread(&thread);
    Device->setupthread(thread);
    on_pushButton_clicked();
    ui->label_2->setText(QString::number(Device->TIME));
}

MainWindow::~MainWindow()
{
    delete Device;
    delete ui;
}



void MainWindow::refreshslot(QString str)
{
    cout(str);
}


void MainWindow::cout(QString str)
{

    if(str == "1"){ui->label->setStyleSheet("background: red;");return;}
    if(str == "0"){ui->label->setStyleSheet("background: green;");return;}
    ui->textEdit->setText(ui->textEdit->toPlainText()+str);
}

void MainWindow::on_pushButton_clicked()
{
    //on_pushButton_2_clicked();
    cout("Запускаю поток... \n");
    Device->thread()->start();
}

void MainWindow::on_pushButton_2_clicked()
{



    Device->LED=4;
    FT_SetBitMode(Device->handle, ((1<<Device->LED)|(0<<Device->BUT)), 0x04);

     cout("LED = " + QString::number(Device->LED)+"\n");
     Sleep(TIME);
     on_pushButton_3_clicked();


    /*if(thread.isRunning()==1)
    {
        thread.exit();
        delete Device;
        Device = new ft232rl_class;
        Device->moveToThread(&thread);

        connect(Device,SIGNAL(refresh(QString)),this,SLOT(refreshslot(QString)));
        connect(this,SIGNAL(stopthread()),Device,SLOT(swich_of()));

        cout("Поток завершён\n\n");

    }
   //*/
}

void MainWindow::on_pushButton_3_clicked()
{
    Device->LED=0;
    FT_SetBitMode(Device->handle, ((1<<Device->LED)|(0<<Device->BUT)), 0x04);

     cout("LED = " + QString::number(Device->LED)+"\n");

}

void MainWindow::on_pushButton_4_clicked()
{
    Device->LED=2;
    FT_SetBitMode(Device->handle, ((1<<Device->LED)|(0<<Device->BUT)), 0x04);

     cout("LED = " + QString::number(Device->LED)+"\n");
     Sleep(TIME);
     on_pushButton_3_clicked();
}

void MainWindow::on_pushButton_5_clicked()
{
    for(int i = 0; i<300; i++)
    {
        Device->LED=1;
        FT_SetBitMode(Device->handle, ((1<<Device->LED)|(0<<Device->BUT)), 0x04);

         cout("LED = " + QString::number(Device->LED)+"\n");
         Sleep(TIME);
         on_pushButton_3_clicked();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    Device->TIME=ui->lineEdit->text().toInt();
    ui->label_2->setText(ui->lineEdit->text());
    ui->dial->setSliderPosition(ui->lineEdit->text().toInt());
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_6_clicked();
}

void MainWindow::on_dial_sliderMoved(int position)
{
   Device->TIME=position;
  // Device->TIME_changed();
   ui->label_2->setText(QString::number(position));
}


void MainWindow::on_dial_actionTriggered(int action)
{

}

void MainWindow::on_dial_sliderPressed()
{
    on_dial_sliderMoved(ui->dial->value());
}

void MainWindow::on_pushButton_7_clicked()
{
    Device->TIME=Device->TIME+1;
    ui->label_2->setText(QString::number(Device->TIME));
    ui->dial->setSliderPosition(Device->TIME);
}

void MainWindow::on_pushButton_8_clicked()
{

    Device->TIME=Device->TIME-1;
    ui->label_2->setText(QString::number(Device->TIME));
    ui->dial->setSliderPosition(Device->TIME);
}
