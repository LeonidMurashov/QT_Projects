#include "unit.h"
#include "mainwindow.h"
#include <QPainter>
#include <QDate>
Unit::Unit(QString nam, QString surnam, int num, int year, MainWindow * parent)
{
    name = nam;
    surname = surnam;
    number = num;
    yearborn = year;

    but = new QPushButton(name + " " + surname + "   " + QString::number(QDate::currentDate().year()-yearborn) + " лет", this);
    but->setFlat(1);

    delbut = new QPushButton("✘", this);
    delbut->setFlat(1);
    delbut->setFixedSize(30,40);

    lbl = new QLabel(name + " " + surname, this);

    lay = new QHBoxLayout;
    lay->addWidget(but);
    lay->addWidget(delbut);


    connect(this->but, SIGNAL(clicked()), this, SLOT(clickedslot()));
    connect(this, SIGNAL(clicked(Unit*)),parent, SLOT(choose(Unit*)));

    connect(this->delbut, SIGNAL(clicked()), this, SLOT(clickeddelslot()));
    connect(this, SIGNAL(clickeddel(Unit*)),parent, SLOT(delslot(Unit*)));

    connect(parent, SIGNAL(unitdeleted(int)), this, SLOT(numchanged(int)));
}

void Unit::rename()
{
    but->setText(name + " " + surname + "   " + QString::number(QDate::currentDate().year()-yearborn) + " лет" );
    lbl->setText(name + " " + surname);
}

void Unit::registeration(QString str)
{
    int i = 0, j = 0;
    QChar ch = ' ';
    QString str2;
    while(1)
    {
        if(str[i] == ch || str[i] == '\n'){name = str2;j=0;break;}
        str2[j]=str[i];
        j++;
        i++;
    }
    i++;
    str2 = "";
    while(1)
    {
        if(str[i] == ' ' || str[i] == '\n'){surname = str2;j=0;break;}
        str2[j]=str[i];
        j++;
        i++;
    }
    i++;
    str2 = "";
    while(1)
    {
        if(str[i] ==  ' ' || str[i] == '\n'){yearborn = str2.toInt();j=0;break;}
        str2[j]=str[i];
        j++;
        i++;
    }
    rename();
}

QString Unit::unregistration()
{
    QString str;
    str = name + " " + surname + " " + QString::number(yearborn);
    return str;
}

Unit::~Unit()
{
    delete delbut;
    delete lay;
    delete but;
    delete lbl;
    //delete lay;
}
