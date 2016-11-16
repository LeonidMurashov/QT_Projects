#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QInputDialog>
#include<QDebug>
#include<QSettings>
#include<QDate>
#include<QFileDialog>
#include<QListWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new QSettings("LeoMur", "PE_calc",this);
    loadsettings();

    a = new QVBoxLayout;

    ui->scrollAreaWidgetContents->setLayout(a);
   // ui->scrollAreaWidgetContents_2->str
    ui->scrollArea->setMaximumWidth(305);

    but = new QPushButton("новый ученик...");
    but->setHidden(1);
    but->setFlat(1);
    but->setEnabled(0);


    file = new QFile(dir.path() + "/test.txt");
    //connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(cleanslot()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this,SLOT(add_new_button()));
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(add_edit_button()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this,SLOT(change_default_year()));
   // write(new Unit("Леонид","Мурашов",pupils.size(),this), pupils.size());

    read();
    glonum = pupils.size();
}


void MainWindow::write(Unit *unit, int num)
{
    ui->pushButton->setEnabled(0);
        if(num==pupils.size())
        {
            ///запись
            pupils.push_back(unit);
            a->addLayout(pupils[pupils.size()-1]->lay);


        }
        else
        {
            ////перезапись           
            delete pupils[num];
            a->removeItem(pupils[num]->lay);

            emit unitdeleted(num);
            a->addLayout(unit->lay);
            pupils[num] = unit;           


        }

        glonum = pupils.size();

}
void MainWindow::del(int num)
{
    ///////////////удаление одного

    delete pupils[num];
    pupils.erase(pupils.begin()+num);
    emit unitdeleted(num);

    glonum = pupils.size();
}
void MainWindow::cleanslot()
{

    clean();
    glonum = 0;
}
void MainWindow::delslot(Unit *c)
{
    del(c->number);
    glonum = 0;
}
void MainWindow::clean()
{
    QMessageBox::StandardButton sbut;
    sbut = QMessageBox::question(this,"Очистка списка", "Вы уверены, что хотите безвозвратно удалить содержание этого списка?", QMessageBox::Yes | QMessageBox::Cancel);

    if(sbut == QMessageBox::Yes)
    {
         while(pupils.size()!=0)
         {
            delete pupils[0];
            pupils.pop_front();
         }
    }
}
void MainWindow::add_edit_button()
{


    if(ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="")
    {
        but->setHidden(1);
        if(glonum ==pupils.size()) write(new Unit(ui->lineEdit->text(), ui->lineEdit_2->text(),pupils.size(),whatyear(),this),pupils.size());
        else write(new Unit(ui->lineEdit->text(), ui->lineEdit_2->text(),pupils.size(),whatyear(),this),glonum);
        pupils[0]->but->setDisabled(1);
        pupils[0]->but->setDisabled(0);
    }


}
void MainWindow::choose(Unit * a)
{
    ///настройка ньюансов
    //QMessageBox::warning(this,"war","awe");
    ui->pushButton->setText("Изменить");
    but->setHidden(1);
    ui->pushButton->setEnabled(1);
    pupils[pupils.size()-1]->but->setDown(0);

    for(int i = 0; i< pupils.size();i++)
    {
        pupils[i]->but->setFlat(1); //Убирает выделение с кнопок
    }


    a->but->setFlat(0);

    glonum = a->number;

    ///само выделение
    ui->lineEdit->setText(a->name);
    ui->lineEdit_2->setText(a->surname);

        if(a->yearborn == ui->radioButton_2->text().toInt()-1) ui->radioButton->setChecked(1);
    else if(a->yearborn == ui->radioButton_2->text().toInt()) ui->radioButton_2->setChecked(1);
    else if(a->yearborn == ui->radioButton_2->text().toInt()+1){ ui->radioButton_3->setChecked(1);}
    else {ui->radioButton_4->setChecked(1);ui->label->setText(QString::number(a->yearborn));}

    ///снова ньюансы
    if(!ui->radioButton_4->isChecked())ui->label->setText("");

}
void MainWindow::read()
{
    if (!file->open(QFile::ReadWrite)){QMessageBox::information(this,"Ошибка","Файл не подключен! \n Требуется изменить путь к файлу.");}
    else
    {
       QTextStream stream(file);
    QString str;

       while (!stream.atEnd())
       {

           Unit *unit = new Unit("ne zadano","-//-",pupils.size(),whatyear(),this);
           write(unit, pupils.size());
           str = file->readLine();
           unit->registeration(str);
           if(pupils[pupils.size()-1]->name=="" || pupils[pupils.size()-1]->surname==""){del(pupils.size()-1);continue;}

       }


       file->close();
     }
}
int MainWindow::whatyear()
{
    if(ui->radioButton->isChecked())return ui->radioButton_2->text().toInt()-1;
    if(ui->radioButton_2->isChecked())return ui->radioButton_2->text().toInt();
    if(ui->radioButton_3->isChecked())return ui->radioButton_2->text().toInt()+1;
    if(ui->radioButton_4->isChecked())return ui->label->text().toInt();
    return -1;
}
void MainWindow::add_new_button()
{
    ui->pushButton->setEnabled(1);
    ui->pushButton->setText("Добавить");
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_4->setDisabled(0);
    a->addWidget(but);
    but->setHidden(0);
    but->setDown(1);
    //ui->lineEdit->setText("");
   // ui->lineEdit_2->setText("");
    //ui->radioButton_2->setChecked(1);
    for(int i = 0; i< pupils.size();i++)
    {
        pupils[i]->but->setFlat(1); //Убирает выделение с кнопок
    }
    glonum = pupils.size();
}
void MainWindow::on_radioButton_4_clicked()
{
    ui->label->setText(QString::number(QInputDialog::getInt(this, "Введите год рождения","Год",ui->radioButton_2->text().toInt(),1900)));
}
void MainWindow::change_default_year()
{
    ui->label->setText("");
    ui->radioButton_2->setChecked(1);
    ui->radioButton_2->setText(QString::number(QInputDialog::getInt(this, "Введите год рождения","Год",ui->radioButton_2->text().toInt(),1900)));
}
void MainWindow::loadsettings()
{
    if (settings->value("firstload", "1")==1);
    dir.setPath(settings->value("filepath", "C:\Program Files\LeoMur").toString());
    ui->radioButton_2->setText(settings->value("yeardefault","2000").toString());    
    ui->statusBar->showMessage(dir.path()+ "\file.txt",6000);
}
void MainWindow::savesettings()
{
    settings->setValue("filepath",dir.path());
    settings->setValue("yeardefault",ui->radioButton_2->text().toInt());
    settings->setValue("firstload","0");
}

MainWindow::~MainWindow()
{

    if (!file->open(QFile::WriteOnly)){QMessageBox::information(this,"Ошибка","Файл не подключен! \n Данные не будут сохранены.");}
else  {
       QTextStream stream(file);
       for (int i = 0; i <pupils.size(); i++)stream<<pupils[i]->unregistration()<<endl;
       stream.flush();
       file->close();
     }

    savesettings();

    delete ui;
}




void MainWindow::on_action_triggered()
{
    QFileDialog *wnd = new QFileDialog;
    wnd->setFileMode(QFileDialog::Directory);
    wnd->setDirectory(dir);

    QString str = wnd->getExistingDirectory();



    if(str!="")
    {

        file->remove();
        delete file;

        lastpath = dir.path();

        dir.setPath(str);
        file = new QFile(dir.path() + "/test.txt");


        if (!file->open(QFile::ReadWrite))
            {
                dir.setPath(lastpath);
                file = new QFile(dir.path() + "/test.txt");
                QMessageBox::information(this,"Ошибка","Путь к файлу не изменён! Причина: не возможно создать файл в данной папке.");
                ui->statusBar->showMessage("Оставлен преждний путь к файлу: " + dir.path()+ "/file.txt",6000);
            }
          else  {

            QTextStream stream(file);
            for (int i = 0; i <pupils.size(); i++)stream<<pupils[i]->unregistration()<<endl;
            stream.flush();
            file->close();
            ui->statusBar->showMessage("Путь к файлу изменён: " + dir.path()+ "/file.txt",6000);
        }

    }
    else
    {
        //QMessageBox::information(this,"Ошибка","Путь к файлу не изменён! Причина: неправильно указан путь.");
        ui->statusBar->showMessage("Оставлен преждний путь к файлу: " + dir.path()+ "/file.txt",6000);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    dir.setPath("//home/leonid/myfiles");
    file = new QFile(dir.path() + "/test.txt");
     ui->statusBar->showMessage(dir.path()+ "/file.txt",6000);
}

void MainWindow::on_action_2_triggered()
{
    cleanslot();
}
