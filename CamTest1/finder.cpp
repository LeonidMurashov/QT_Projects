#include "finder.h"
#include "ui_finder.h"
#include <QPixmap>


Finder::Finder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Finder)
{
    ui->setupUi(this);
    
}

Finder::~Finder()
{
    delete ui;
}

void Finder::capturedslot(QString adr)
{
    QPixmap pic(adr);
    ui->label->setPixmap(pic);
    this->show();
}
