#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <bitset>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    timer->setInterval(50);

    numBytes = 0;
    port = 0;
    TIME = 60;
    time = 0;

    ui->dial->setValue(TIME);
    ui->label->setText(QString::number(TIME));



    cout("FTDI Bit Bang mode-----\n");

    if(FT_Open(0, &handle) != FT_OK)
    {
       cout("Can't open device\nWaiting for device...\n");
       connect(this->timer, SIGNAL(timeout()), this, SLOT(ftchek()));
    }
    else
    {
        cout("Device is open\n");
        FT_SetBitMode(handle, (1023), 0x04);
        connect(this->timer, SIGNAL(timeout()), this, SLOT(bitbang()));
    }
    timer->start();
}

void MainWindow::cout(QString a)
{
    ui->plainTextEdit->appendPlainText(a);
}

void MainWindow::ftchek()
{
    handle = 0;
    if(FT_Open(0, &handle) != FT_OK);
    else
    {
        cout("\nDevice is open\n");
        FT_SetBitMode(handle, (1023), 0x04);
        connect(this->timer, SIGNAL(timeout()), this, SLOT(bitbang()));
        disconnect(this->timer, SIGNAL(timeout()), this, SLOT(ftchek()));
    }
}

void MainWindow::bitbang()
{
    std::bitset<8> bits(TIME);
    std::bitset<8> bits2;
     bits2[3]=bits[0];
     bits2[6]=bits[1];
     bits2[5]=bits[2];
     bits2[7]=bits[3];
     bits2[1]=bits[4];/// у FT непоследовательная распиновка
     bits2[2]=bits[5];
     bits2[4]=bits[6];
     bits2[0]=bits[7];


     port = bits2.to_ulong();//bits.to_ulong();

     FT_Write(handle, &port, 1, &numBytes);

     time++;

     if(time==50)
     {
         time = 0;
         FT_Close(handle);

         handle = 0;
         if(FT_Open(0, &handle) != FT_OK)
         {
            cout("Device missed\nSearching for device...\n");
            disconnect(this->timer, SIGNAL(timeout()), this, SLOT(bitbang()));
            connect(this->timer, SIGNAL(timeout()), this, SLOT(ftchek()));
         }
         else
         {
             FT_SetBitMode(handle, (1023), 0x04);
         }
     }

}


MainWindow::~MainWindow()
{
    FT_Close (handle);
    timer->stop();
    delete timer;
    delete ui;
}



void MainWindow::on_dial_valueChanged(int value)
{
    TIME=value;
    ui->label->setText(QString::number(value));
    ui->verticalSlider->setValue(value);
}



void MainWindow::on_lineEdit_returnPressed()
{
    ui->dial->setValue(ui->lineEdit->text().toInt());
    ui->label->setText(QString::number(ui->dial->value()));
    ui->verticalSlider->setValue(ui->lineEdit->text().toInt());
    TIME = ui->lineEdit->text().toInt();
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->dial->setValue(value);
    ui->label->setText(QString::number(value));
    TIME = value;
}
