#include "norms.h"
#include "ui_norms.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
norms::norms(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::norms)
{
    ui->setupUi(this);
    file = new QFile(parent->dir.path() + "/norms.txt");

    for(int i=0; i<parent->sports.size();i++)ui->listWidget->addItem(parent->sports[i]);
}

norms::~norms()
{
    delete ui;
}

void norms::on_buttonBox_accepted()
{
    if (!file->open(QFile::WriteOnly)){QMessageBox::information(this,"Ошибка","Файл не подключен! \n Данные не будут сохранены.");}
    else  {
      QTextStream stream(file);
      for (int i = 0; i <ui->listWidget->count(); i++)stream<<ui->listWidget->item(i)->text()<<endl;
      stream.flush();
      file->close();
    }
}
