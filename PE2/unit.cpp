#include "unit.h"
#include "mainwindow.h"
#include <QPainter>
#include <QDate>
Unit::Unit(QString nam, QString surnam, int num, int year,int se, MainWindow * paren)
{
    name = nam;
    sex= se;
    surname = surnam;
    number = num;
    yearborn = year;
    parent = paren;

    but = new QPushButton(surname + " " + name + "   " + QString::number(QDate::currentDate().year()-yearborn) + " лет", this);
    but->setFlat(1);
    but->setToolTip(QString::number(yearborn));

    delbut = new QPushButton("✘", this);
    delbut->setFlat(1);
    delbut->setFixedSize(60,20);

    lbl = new QLabel(surname + " " + name, this);

    lay = new QHBoxLayout;
    lay->addWidget(but);
    lay->addWidget(delbut);

    scores = QVector<int>(parent->sports.size(),0);

    connect(this->but, SIGNAL(clicked()), this, SLOT(clickedslot()));
    connect(this, SIGNAL(clicked(Unit*)),parent, SLOT(choose(Unit*)));

    connect(this->delbut, SIGNAL(clicked()), this, SLOT(clickeddelslot()));
    connect(this, SIGNAL(clickeddel(Unit*)),parent, SLOT(delslot(Unit*)));

    connect(parent, SIGNAL(unitdeleted(int)), this, SLOT(numchanged(int)));
}

void Unit::rename()
{
    QString str2 = "", str=surname + " " + name + QString::number(QDate::currentDate().year()-yearborn) + " лет";

    //for(int i = 0; i<(20-str.size())/2;i++)str2 += " ";
    for(int i = 0; i<(27-str.size());i++)str2 += " ";
    but->setText(surname + " " + name + str2+" "+ QString::number(QDate::currentDate().year()-yearborn) + " лет");
    //but->setText(surname + " " + name +  +" "+ QString::number(QDate::currentDate().year()-yearborn) + " лет");

    lbl->setText(surname + " " + name);
    but->setToolTip(QString::number(yearborn));
}

void Unit::registeration(QString str)
{
    int i = 0, j = 0;
    QChar ch = ' ';
    QString str2;

    while(1)
    {
        if(str[i] == ch || str[i] == '\n'){surname = str2;j=0;break;}
        str2[j]=str[i];
        j++;
        i++;
    }
    i++;
    str2 = "";
    while(1)
    {
        if(str[i] == ' ' || str[i] == '\n'){name = str2;j=0;break;}
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

    i++;
    str2 = "";
    while(1)
    {
        if(str[i] ==  ' ' || str[i] == '\n'){sex = str2.toInt();j=0;break;}
        str2[j]=str[i];
        j++;
        i++;
    }
    rename();
    if(str[i]!='\r')
    {
        int j2 = 0;
        i++;
        for(int i2 =0;i2<parent->sports.size(); i2++)
        {

            str2 = " ";
            while(1)
            {
                if((str[i]=='\n' || str[i] == '\r') && i==str.size()){i2=parent->sports.size();i--;break;}
                if(str[i] ==  ' ' || str[i] == '\r'){scores[j2]=str2.toInt();j2++;j=0;break;}
                str2[j]=str[i];
                j++;
                i++;
            }
            i++;
            if(str[i] == '\n' || str[i] == '\r')break;
        }
    }
    for(int i2=0; i2<parent->sports.size()-scores.size();i2++)scores.push_back(0);
}

QString Unit::unregistration()
{
    QString str;
    str = surname + " " + name + " " + QString::number(yearborn) + " " + QString::number(sex);
    for(int i=0;i<scores.size();i++)str += " " + QString::number(scores[i]);
    return str;
}

Unit::~Unit()
{
    delete delbut;    
    delete but;
    delete lay;
    delete lbl;
    //delete lay;
}
