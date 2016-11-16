#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QDir>
#include<QInputDialog>
#include<QGraphicsView>
#include<QMouseEvent>
#include<QMessageBox>
#include<QBrush>
#include"myqlabel.h"

#define PROPORTION 8.466

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*QPixmap pix("C:\\Users\\Леонид\\Videos\\фото и видео\\айфон 2015\\2015-08-23\\001.jpg");
    pix = pix.scaled(100,100);
    pix = pix.copy(50,50,100,100);
    ui->label->setPixmap(pix);*/
    counter = 0;
    nameoffile = 0;
    pathtofile = "D://gg//Сropper";
    click = 0;

    x=0;y=0;x1=0;y1=0;
   // on_pushButton_3_clicked();
}
/*
void GraphicsView::mousePressEvent(QMouseEvent *event) {
    this->fixedPoint = event->pos();
}
*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(click == 0)
    {
        x = event->x();
        y = event->y();
        if((ui->label->x()<=x && ui->label->width()+ui->label->x()>=x)&&(ui->label->y()<=y && ui->label->height()+ui->label->y()>=y))
            click++;
    }
    else
    {
        x1 = event->x();
        y1 = event->y();
        if((ui->label->x()<=x1 && ui->label->width()+ui->label->x()>=x1)&&(ui->label->y()<=y1 && ui->label->height()+ui->label->y()>=y1))
        {
            click = 2;
            //paintEvent(new QPaintEvent(QRect(0,0,0,0)));
           // ui->label->refresh(x,y,x1,y1);
            savephoto();
            click=0;
        }
    }
    //QMessageBox::information(this,"info",QString::number(x) + " " + QString::number(y));



}

void MainWindow::savephoto()
{
    x -= ui->label->x();
    y -= ui->label->y();
    x1 -= ui->label->x();
    y1 -= ui->label->y();
    if(x>x1)qSwap(x,x1);
    if(y>y1)qSwap(y,y1);
    if(pixes.size()==0 || x1-x>pixes[counter].width() || y1-y>pixes[counter].height()){QMessageBox::information(this,"Error","Wrong size!");return;}
    ui->textEdit->insertPlainText("Good /" + QString::number(nameoffile) + ".jpg 1  " + QString::number(0) + " "
                                                                                      + QString::number(0) + " "
                                                                                      + QString::number((x1-x)) + " "
                                                                                      + QString::number((y1-y)) + "\n");
    //QRect(x*PROPORTION,y*PROPORTION,(x1-x)*PROPORTION,(y1-y)*PROPORTION)
    //QMessageBox::information(this,"Error",pathtofile + "//" + QString::number(nameoffile) + ".jpg");
   // pixes[counter].copy(x*propx,y*propx,(x1-x)*propx,(y1-y)*propx).save(pathtofile + "//" + QString::number(nameoffile) + ".jpg");
     ui->label->pixmap()->copy(x,y,(x1-x),(y1-y)).save(pathtofile + "//" + QString::number(nameoffile) + ".jpg");
    nameoffile++;//
    ui->lineEdit->setText(QString::number(nameoffile));
}

/*
void MainWindow::paintEvent(QPaintEvent *)
{
      /*  if(click==2)
        {
            click=0;
            QPainter painter(this);
            //painter.drawRect(x,y,x1-x,y1-y);
            painter.drawEllipse(0,0,50,50);

            QMessageBox::information(this,"info",QString::number(x) + " " + QString::number(y) + "\n" + QString::number(x1) + " " + QString::number(y1));
            //click = 0;
        }
}*/

void MainWindow::read()
{
    QDir dir(QInputDialog::getText(this,"Path","Directory:"));
    //QDir dir("C:\\Users\\Леонид\\Videos\\фото и видео");
    QFileInfoList files = dir.entryInfoList();
    foreach (QFileInfo file, files)
    {
        if(file.suffix()=="jpg" || file.suffix()=="JPG")pixes.push_back(QPixmap(file.filePath()));
        if(pixes.size()>49){ui->label_3->setText("MAX");return;}
    }

}

void MainWindow::display()
{
   // ui->label->resize(10,10);
    int pixh = pixes[counter].scaledToWidth(ui->label->width()).height();
    int pixw = pixes[counter].scaledToHeight(ui->label->height()).width();
    if(pixh<=ui->label->height())
    {
        ui->label->setPixmap(pixes[counter].scaledToWidth(ui->label->width()));
       // propx = pixes[counter].width() / pixw;
    }
    else
    {
        ui->label->setPixmap(pixes[counter].scaledToHeight(ui->label->height()));
        //propx = pixes[counter].height() / pixh;
    }
    //ui->label->resize(ui->label->pixmap()->width(), ui->label->pixmap()->height());

//pixes[counter].sc
}

void MainWindow::on_pushButton_clicked()
{
    if(pixes.size()-1>counter)counter++;
    else counter = 0;
    if(pixes.size()>0)display();
    ui->lcdNumber->display(counter+1);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(counter>0)counter--;
    else counter = pixes.size()-1;
    if(pixes.size()>0)display();
    ui->lcdNumber->display(counter+1);
}

void MainWindow::on_pushButton_3_clicked()
{
    pixes.resize(0);
    ui->label_3->setText("");
    read();
    if(pixes.size()>0)display();
    ui->label_2->setText("Фото: " + QString::number(pixes.size()));
    ui->lcdNumber->display(counter+1);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    nameoffile = ui->lineEdit->text().toInt();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    pathtofile = ui->lineEdit->text();
}
