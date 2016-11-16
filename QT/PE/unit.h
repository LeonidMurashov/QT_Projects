#ifndef UNIT_H
#define UNIT_H

#include<QPushButton>
#include<QLabel>
#include<QHBoxLayout>
#include<QFile>
class Unit : QWidget
{

public:

    QPushButton *but;
    QLabel *lbl;


    void del()
    {
        delete but;
        delete lbl;


    }

    Unit(QString name,QString surname)
    {
        
        but = new QPushButton(name + " " + surname);
        lbl = new QLabel(name + " " + surname);




    }



};

#endif // UNIT_H
