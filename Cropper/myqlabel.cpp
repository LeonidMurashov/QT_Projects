#include "myqlabel.h"
#include<QPainter>
#include<QMessageBox>
#include<QEvent>

MyQLabel::MyQLabel(QWidget *parent)
{

}

void MyQLabel::paintEvent(QEvent*)
{
    QPainter painter(this);
    //painter.drawRect(_x,_y,_x1-_x,_y1-_y);
    painter.drawEllipse(0,0,50,50);
    QMessageBox::information(this,"info","333");
}

void MyQLabel::refresh(int x, int y, int x1, int y1)
{
    _x=x;
    _y=y;
    _x1=x1;
    _y1=y1;
    QMessageBox::information(this,"info","222");
    repaint();

}

