#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   


    ui->scrollAreaWidgetContents->setLayout(a);

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(clean()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::write(Unit *unit)
{

    QFile file(tr(ADRESS));


    if (!file.open(QFile::Append)){QMessageBox::information(this,"Ошибка","Файл не подключен");return 0;}
else  {

         QTextStream stream(&file);
         stream << unit->lbl->text()<<endl;
          stream.flush();
        //QString str = stream.readAll();
       //a->addWidget(new QLabel(str));


          file.close();
  }

}
void MainWindow::del(int num)
{

    QFile file(tr(ADRESS));


    if (!file.open(QFile::ReadWrite)){QMessageBox::information(this,"Ошибка","Файл не подключен");return;}
else  {

         QTextStream stream(&file);
       //  stream << unit->lbl->text()<<endl;
        //  stream.flush();
       // a->addWidget(new QLabel(str));
        QVector <QString> strs;
       while(!stream.atEnd()) strs.push_back(stream.readLine());
      strs.remove(num);
      for(int i=0; i<strs.size(); i++)stream << strs[i];
      delete &strs;
          file.close();
  }

}

void MainWindow::clean()
{
    QFile file(tr(ADRESS));


    if (!file.open(QFile::WriteOnly)){QMessageBox::information(this,"Ошибка","Файл не подключен");return;}
else  {
        QTextStream stream(&file);
        stream << "";
         stream.flush();
         file.close();
         while(pupils.size()!=0) {
             pupils[0]->del();
            pupils.pop_front();
         }
    }
}

void MainWindow::on_pushButton_clicked()
{

    if(ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="")
    {
        Unit *un = new Unit(ui->lineEdit->text(), ui->lineEdit_2->text());
       if (write(un)!=0){
       pupils.push_back(un);
        a->addWidget(pupils[pupils.size()-1]->but);
       }

    }
}
