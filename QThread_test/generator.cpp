#include "generator.h"
#include"mainwindow.h"
#include<QDebug>

generator::generator(QObject *parent) : QObject(parent)
{

}

void generator::SetupThread(QThread &thread, MainWindow *w)
{
    wind = w;
    connect(this,SIGNAL(writesig(QString)),w,SLOT(write(QString)));
    connect(&thread,SIGNAL(started()), this, SLOT(DoWork()));
}

void generator::DoWork()
{
    int i =0;

    while(1)
    {
        i++;
        qDebug()<<i;
        writesig(QString::number(i));
//        ui->label->setText(QString::number(i));
    }
}
