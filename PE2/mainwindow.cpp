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
#include<QGraphicsItem>
#include"qcustomplot.h"
#include<QPixmap>
#include<QClipboard>
#include<QTextCodec>


MainWindow::MainWindow(QString fileconstr,QString dirconstr, QWidget *parent) :
    QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    normseditorusing=0;

    this->setAttribute(Qt::WA_DeleteOnClose);

    file = new QFile(fileconstr);

    settings = new QSettings("LeoMur", "PE_calc_file_"+file->fileName(),this);
    loadsettings();
    dir.setPath(dirconstr);

    a = new QVBoxLayout;

    ui->scrollAreaWidgetContents->setLayout(a);
   // ui->scrollAreaWidgetContents_2->str
    ui->scrollArea->setMaximumWidth(350);//20 символов

    but = new QPushButton("новый ученик...");   ///кнопка для виду
    but->setHidden(1);
    but->setFlat(1);
    but->setEnabled(0);



    file2 = new QFile(dir.path() + "/sports.txt");
    read();

    this->setWindowTitle("Калькулятор физ. подготовки - " + nameofgroup);

    graph = ui->customplot->addGraph();
    graph2 = ui->customplot->addGraph();
    bars = new QCPBars(ui->customplot->xAxis,ui->customplot->yAxis);
            ui->customplot->addPlottable(bars);

    //ui->customplot->xAxis->setAutoTickLabels(0);//TickVectorLabels(QVector<QString>(10,"1"));

    replot(0);

    connect(ui->pushButton_4, SIGNAL(clicked()), this,SLOT(add_new_button()));
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(add_edit_button()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this,SLOT(change_default_year()));
    connect(ui->tableWidget,SIGNAL(cellChanged(int,int)), this,SLOT(tablecellchanged(int,int)));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)), this,SLOT(cellstatbar(int,int)));
    connect(ui->tableWidget_2,SIGNAL(cellChanged(int,int)), this,SLOT(normchanged(int,int)));
    connect(ui->listWidget,SIGNAL(itemSelectionChanged()),this, SLOT(replotslot()));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tab_changed()));
    //connect(this, SIGNAL(), this, SLOT(destroythis()));
    //поле для экспериментов




    ui->tabWidget->setCurrentIndex(0);
    glonum = pupils.size();

    this->setGeometry(QApplication::desktop()->width()/2+30-this->width()/2, QApplication::desktop()->height()/2+10-this->height()/2, this->width(), this->height());

}
void MainWindow::write(Unit *unit, int num)
{
        ui->pushButton->setText("Добавить");
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");///возможность добавить ещё одного
        if(num==pupils.size())          ///ученика после создания
        {
            ///запись
            pupils.push_back(unit);
            a->addLayout(pupils[pupils.size()-1]->lay);
            unit->rename();
        }
        else
        {
            ////перезапись
            QVector <int>b = pupils[num]->scores;
            delete pupils[num];
            a->removeItem(pupils[num]->lay);

            emit unitdeleted(num);
            a->addLayout(unit->lay);
            pupils[num] = unit;
            unit->scores = b;
            unit->rename();
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
    table_repaint();
    glonum = 0;
}
void MainWindow::delslot(Unit *c)
{
    if(QMessageBox::question(this,"Удаление ученика"," Будет удалёны данные ученика (" + c->surname + " " + c->name + ")\n Вы уверены, что хотите совершить это действие?")==QMessageBox::Yes)
    {
        del(c->number);
        table_repaint();
    }
}
void MainWindow::clean()
{
    QMessageBox::StandardButton sbut;
    sbut = QMessageBox::question(this,"Очистка списка", "Вы уверены, что хотите безвозвратно удалить содержимое списка учеников?", QMessageBox::Yes | QMessageBox::Cancel);

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


    if(ui->lineEdit_2->text()!="")
    {
        ///преобразование из одной строки в два слова
        QString str = ui->lineEdit_2->text();
        QString surname="", name="";
        int i = 0, sec=0;
        while(i<str.size())
        {
            if(str[i] == ' ')
            {
                if(i==0){str.chop(0);continue;}
                else if(i>0){sec++;i++;continue;}
                else break;
            }

                if(sec>1)break;
                if(sec==0)surname+=str[i];
                else name+=str[i];

            i++;
        }
        if(name == "")name="*";

        ///////////

        but->setHidden(1);
        if(glonum ==pupils.size()) write(new Unit(name, surname,pupils.size(),whatyear(),whatsex(),this),pupils.size());
        else write(new Unit(name, surname,pupils.size(),whatyear(),whatsex(),this),glonum);
        pupils[0]->but->setDisabled(1);
        pupils[0]->but->setDisabled(0);

        ///сортировка после добавления/изменения
        sort();
        table_repaint();
        ui->lineEdit_2->setEnabled(1);
    }
    replot(0);


}
void MainWindow::choose(Unit * a)
{
    ///настройка ньюансов
    //QMessageBox::warning(this,"war","awe");
    ui->pushButton->setText("Изменить");
    but->setHidden(1);

    pupils[pupils.size()-1]->but->setDown(0);

    for(int i = 0; i< pupils.size();i++)
    {
        pupils[i]->but->setFlat(1); //Убирает выделение с кнопок
    }


    a->but->setFlat(0);

    glonum = a->number;

    ///само выделение
    //ui->lineEdit->setText(a->name);
    ui->lineEdit_2->setText(a->surname + " " + a->name);

        if(a->yearborn == ui->radioButton_2->text().toInt()-1) ui->radioButton->setChecked(1);
    else if(a->yearborn == ui->radioButton_2->text().toInt()) ui->radioButton_2->setChecked(1);
    else if(a->yearborn == ui->radioButton_2->text().toInt()+1){ ui->radioButton_3->setChecked(1);}
    else {ui->radioButton_4->setChecked(1);ui->label->setText(QString::number(a->yearborn));}

        if(a->sex==0)ui->male_but->setChecked(1);
        else ui->female_but->setChecked(1);
        ///снова ньюансы
    if(!ui->radioButton_4->isChecked())ui->label->setText("");

}
void MainWindow::read()
{
    int fred = 0;
    ///чтение списка критериев
    if (!file2->open(QFile::ReadOnly)){}//QMessageBox::information(this,"Ошибка","Файл не подключен! \n Требуется изменить путь к файлу.");}
    else
    {
        QTextStream stream(file2);
        QString str;

           while (!stream.atEnd())
           {
               QVector<QVector<int> >vec(2);
               //str = file2->readLine();
               stream>>str;
               if(str=="" || str==" " || str=="\n")continue;
               for(int i =0; i<str.size();i++)if(str[i]=='_')str[i]=' ';
               sports.push_back(str);
               for(int i=0; i<18;i++)
               {
                   stream>>str;
                   if(str=="" || str==" " || str=="\n"){i--;continue;}
                   vec[0].push_back(str.toInt());
               }
               for(int i=0; i<18;i++)
               {
                   stream>>str;
                   if(str=="" || str==" " || str=="\n"){i--;continue;}
                   vec[1].push_back(str.toInt());
               }
                    norms.push_back(vec);


              // stream<<str;
               //norms.push_back(str.toInt());
           }
           file2->close();
           fred++;
    }
    ///чтение списка учеников
    if (!file->open(QFile::ReadWrite)){}//QMessageBox::information(this,"Ошибка","Файл не подключен! \n Требуется изменить путь к файлу.");}
    else
    {
    QTextStream stream(file);
    QString str;

    nameofgroup = file->readLine();
    //for(int i =0; i<nameofgroup.size();i++)if(nameofgroup[i]=='\n')nameofgroup[i]=' ';
    if(nameofgroup.size()!=0)nameofgroup.resize(nameofgroup.size()-2);
    if(nameofgroup!="")ui->groupname_but->setText(nameofgroup);

       while (!stream.atEnd())
       {
           str = file->readLine();
           if(str=="\n")continue;
           Unit *unit = new Unit("ne zadano","-//-",pupils.size(),0,0 ,this);
           write(unit, pupils.size());           
           unit->registeration(str);
           if(pupils[pupils.size()-1]->name=="" || pupils[pupils.size()-1]->surname==""){del(pupils.size()-1);continue;}
       }
       file->close();
       fred++;
     }
    if(fred==2)
    {
        sort();
        table_repaint();
        normseditor();
    }
}
void MainWindow::writefile()
{
    if (!file->open(QFile::WriteOnly)){QMessageBox::information(this,"Ошибка","Файл не подключен! \n Данные не будут сохранены.");}
    else  {
      QTextStream stream(file);
      stream.setCodec(QTextCodec::codecForName("UTF-8"));
      stream<<ui->groupname_but->text()<<'\r'<<'\n';
      for (int i = 0; i <pupils.size(); i++)stream<<pupils[i]->unregistration()<<'\r'<<'\n';
      stream.flush();
      file->close();
    }
    if(normseditorusing>1)
    {
        if (!file2->open(QFile::WriteOnly)){QMessageBox::information(this,"Ошибка","Файл не подключен! \n Данные не будут сохранены.");}
        else  {
          QTextStream stream(file2);
          //stream.setCodec(QTextCodec::codecForName("UTF-8"));
          for (int i = 0; i <sports.size(); i++)
          {
              for(int j=0; j<sports[i].size(); j++)if(sports[i][j]==' ')sports[i][j]='_';
              stream<<sports[i]<<" ";
              for(int j =0; j<18; j++)stream<<norms[i][0][j]<<" ";
              for(int j =0; j<18; j++)stream<<norms[i][1][j]<<" ";
              stream<<'\r'<<'\n';
          }
          stream.flush();
          file2->close();
        }
    }
}

/*
8Г
Мурашова Анна 2008 1 104 2 17 14

Мурашов	Никита 2008 0 82 5 3 9

Мурашов Леонид 2000 0 160 40 25 -9

Прыжки_в_длину_с_места 900 10 7 10 10 0 112 127 140 152 163 174 185 196 206 216 225 233 5 2 52 24 14 0 104 120 132 142 152 160 167 173 177 180 180 178
Отжимания 2 2 10 2 2 0 13 15 17 19 21 23 25 28 32 37 40 42 5 2 65 5 14 0 8 9 10 11 12 13 14 14 15 15 16 16
Пресс 2 2 24 2 10 0 13 14 15 16 17 18 19 20 21 22 23 24 5 5 42 5 5 0 12 13 14 15 16 17 18 19 20 21 21 21
Растяжка 0 0 0 0 0 0 4 5 6 7 8 9 9 10 10 11 11 11 0 0 0 0 0 0 6 7 8 9 10 11 12 12 13 13 13 13
 */

int MainWindow::whatsex()
{
    if(ui->female_but->isChecked())return 1;
    else return 0;
}
 int MainWindow::whatyear()
{
    if(ui->radioButton->isChecked())return ui->radioButton_2->text().toInt()-1;
    if(ui->radioButton_2->isChecked())return ui->radioButton_2->text().toInt();
    if(ui->radioButton_3->isChecked())return ui->radioButton_2->text().toInt()+1;
    if(ui->radioButton_4->isChecked())return ui->label->text().toInt();
    return -1;
}
void MainWindow::table_repaint()
{
    ///перерисовка списка при графике
    ui->listWidget->clear();
    ui->listWidget->addItem("Физ. подготовка всей группы");
    for(int i=0; i<pupils.size();i++)ui->listWidget->addItem(pupils[i]->lbl->text());


    ///перерисовка таблицы
    ui->tableWidget->setRowCount(pupils.size());
    ui->tableWidget->setColumnCount(sports.size());

    QStringList strl;
    for(int i = 0; i<sports.size();i++)strl.push_back(sports[i]);
    ui->tableWidget->setHorizontalHeaderLabels(strl);

    for(int i =0; i<ui->tableWidget->columnCount();i++) ui->tableWidget->horizontalHeader()->resizeSection(i,sports[i].size()*11);
    //table->horizontalHeader()->resizeSection(logicalIndex, size);

    QStringList strl2;
    for(int i = 0; i<pupils.size();i++)strl2.push_back(pupils[i]->surname +" "+ pupils[i]->name);
    ui->tableWidget->setVerticalHeaderLabels(strl2);

    ///заполнение таблицы + тултипы
     for(int j = 0; j<ui->tableWidget->rowCount();j++)
         for(int i = 0; i<pupils[0]->scores.size();i++)
            if (pupils[j]->scores[i]!=0)
            {
                ui->tableWidget->setItem(j,i,new QTableWidgetItem(QString::number(pupils[j]->scores[i])));
                double norm =norms[i][pupils[j]->sex][QDate::currentDate().year() - pupils[j]->yearborn-1];
                double result = (pupils[j]->scores[i]-norm)/norm;
                if(QString::number(result)!="nan")
                {
                    result = (double)qFloor(result*100)/100;
                    ui->tableWidget->item(j,i)->setToolTip(QString::number(result) +" "+ lvl(result));

                }
            }
            else ui->tableWidget->setItem(j,i,new QTableWidgetItem(""));
     ui->tabWidget->setCurrentIndex(0);
}
void MainWindow::normseditor()
{
    normseditorusing++;
    ui->tableWidget_2->setRowCount(sports.size()*2);
    ui->tableWidget_2->setColumnCount(13);

    QStringList strl;
    for(int i = 0; i<sports.size();i++){strl.push_back(sports[i] + " М");strl.push_back(sports[i] + " Ж");}
    ui->tableWidget_2->setVerticalHeaderLabels(strl);

    for(int i =ui->tableWidget_2->columnCount(); i>=0;i--) ui->tableWidget_2->horizontalHeader()->resizeSection(i,50);

    QStringList strl2;
    for(int i = 5; i<=18;i++)strl2.push_back(QString::number(i+1));
    ui->tableWidget_2->setHorizontalHeaderLabels(strl2);

    for(int i = 0; i<13; i++)
        for(int j = 0; j<sports.size(); j++)
            ui->tableWidget_2->setItem(j*2,i,new QTableWidgetItem(QString::number(norms[j][0][i+5])));
    for(int i = 0; i<13; i++)
        for(int j = 0; j<sports.size(); j++)
            ui->tableWidget_2->setItem(j*2+1,i,new QTableWidgetItem(QString::number(norms[j][1][i+5])));
     ui->tabWidget->setCurrentIndex(0);
}
void MainWindow::normchanged(int x, int y)
{
    if(!ui->tableWidget_2->item(x,y)->text().toInt())ui->tableWidget_2->item(x,y)->setText("0");
    if(norms[x/2][x%2][y+5] != ui->tableWidget_2->item(x,y)->text().toInt())
    {
        norms[x/2][x%2][y+5] = ui->tableWidget_2->item(x,y)->text().toInt();
        ui->tableWidget_2->item(x,y)->setBackgroundColor(QColor(255,255,150));
        replot(0);
        normseditorusing++;
    }

}
QString MainWindow::lvl(double b)
{
         if(b>=-0.2 && b<=0.2) return "Хорошо";
    else if(b>0.2  &&  b<=0.65)return "Отлично";
    else if(b>0.65 &&  b<=1)   return "Супер";
    else if(b>1)               return "Опасно высокий";
    else if(b>=-0.6 && b<-0.2) return "Удовл.";
    else if(b>=-1 && b<-0.6)   return "Неудовл.";
    else                       return "Опасно низкий";
}
void MainWindow::resizeplot(int w, int h)
{
    ui->customplot->resize(w,h);
}
QPixmap MainWindow::replot(bool imggen)
{
    QVector<double> x1(2,-1), y1;
    int total = 0,total2 = 0,num = ui->listWidget->currentRow()-1;
    if(num==-2)num=-1;
    double sr_arefm = 0, sr_arefm2 = 0,maxy = 0,miny = 0;
    if(pupils.size()!=0)
    {
        if(num==-1 || imggen==1)
        {

            bars->setPen(Qt::NoPen);
            bars->setBrush(QColor(120, 120, 120,200));

            ///рисование графика класса
            for(int j=0; j<pupils.size();j++)
            {
                sr_arefm = 0;
                total=0;
                for(int i =0; i<pupils[j]->scores.size();i++)
                {
                    double norm =norms[i][pupils[j]->sex][QDate::currentDate().year() - pupils[j]->yearborn-1];
                    if(pupils[j]->scores[i]==0)continue;
                    //y.push_back((pupils[j]->scores[i]-norm)/norm);
                    sr_arefm+=(pupils[j]->scores[i]-norm)/norm;
                    total++;
                }
                if(total==0)continue;
                sr_arefm2 += sr_arefm/total;
                if(sr_arefm/total > maxy)maxy=sr_arefm/total;
                if(sr_arefm/total < miny)miny=sr_arefm/total;
                y.push_back(sr_arefm/total);
                x.push_back(total2*5+3);
                total2++;
            }

            if(maxy > 1)
            {
                if(miny <-1)ui->customplot->yAxis->setRange(miny-0.1, maxy+0.1);
                else ui->customplot->yAxis->setRange(-1, maxy+0.1);
            }
            else
            {
                if(miny <-1)ui->customplot->yAxis->setRange(miny-0.1, 1);
                else ui->customplot->yAxis->setRange(-1, 1);
            }
            ui->customplot->xAxis->setRange(0, total2*5);
            x1[1]=total2*5;
            //graph->setData(x,y);
            y1 = QVector<double>(2,sr_arefm2/total2);
            if(QString::number(y1[0]) == "nan")ui->unit_fit_lbl->setText("Нет данных для вычисления уровня физ. подготовки класса");
            else if (QString::number(y1[0])=="inf") ui->unit_fit_lbl->setText("Отсутствуют некоторые нормативы для данного возраста");
            else
            {
                y1 = QVector<double>(2,(double)qFloor(sr_arefm2/total2*1000)/1000);
                plotsrarefm = "Уровень общей физ. подготовки класса: " + QString::number(y1[0])+ " "+ lvl(y1[0]);
                ui->unit_fit_lbl->setText("Уровень общей физ. подготовки класса: " + QString::number(y1[0])+ " "+ lvl(y1[0]));
            }
            //graph2->setData(x1,y1);
            graph->setData(y1,y1);
            graph2->setData(x1,y1);
            bars->setData(x,y);
            bars->setWidth(5);
            ui->customplot->replot();

            x.clear();
            y.clear();

        }
        else
        {
            ///рисование графика ученика

            graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
            graph->setPen(QPen(QColor(120, 120, 120), 2));

            bars->setWidth(0);
            for(int i =0; i<pupils[num]->scores.size();i++)
            {
                double norm =norms[i][pupils[num]->sex][QDate::currentDate().year() - pupils[num]->yearborn-1];
                if(pupils[num]->scores[i]==0)continue;
                y.push_back((pupils[num]->scores[i]-norm)/norm);
                sr_arefm+=y[total];
                if(y[total]>maxy)maxy=y[total];
                if(y[total]<miny)miny=y[total];
                total++;
            }

            for(int i=0; i<total;i++)x.push_back(5*i+2);

            if(maxy > 1)
            {
                if(miny <-1)ui->customplot->yAxis->setRange(miny-0.1, maxy+0.1);
                else ui->customplot->yAxis->setRange(-1, maxy+0.1);
            }
            else
            {
                if(miny <-1)ui->customplot->yAxis->setRange(miny-0.1, 1);
                else ui->customplot->yAxis->setRange(-1, 1);
            }

            ui->customplot->xAxis->setRange(0, sports.size()*5);

            x1[1]=sports.size()*5;
            y1 = QVector<double>(2,sr_arefm/total);
            if(QString::number(y1[0])=="nan")ui->unit_fit_lbl->setText("Нет данных для вычисления уровня физ. подготовки ученика");
            else if(QString::number(y1[0])=="inf")ui->unit_fit_lbl->setText("Отсутствуют некоторые нормативы для данного возраста: " + QString::number(QDate::currentDate().year() - pupils[num]->yearborn));
            else
            {
                y1 = QVector<double>(2,(double)qFloor(sr_arefm/total*1000)/1000);
                ui->unit_fit_lbl->setText("Уровень общей физ. подготовки ученика: " + QString::number(y1[0]) + " "+ lvl(y1[0]));
            }
            graph->setData(x,y);
            graph2->setData(x1,y1);
            ui->customplot->replot();

            x.clear();
            y.clear();

            //ui->listWidget->setEnabled(0);


        }

    }
                return ui->customplot->toPixmap(); //просматриватся mainmenu
}
void MainWindow::tablecellchanged(int x, int y)
{
    pupils[x]->scores[y] = ui->tableWidget->item(x,y)->text().toInt();
    if (ui->tableWidget->item(x,y)->text().toInt()==0)ui->tableWidget->item(x,y)->setText("");
    replot(0);
}

void MainWindow::replotslot()
{
    replot(0);
}
void MainWindow::cellstatbar(int x, int y) ///вызывается по нажатию ячейки
{
    double norm =norms[y][pupils[x]->sex][QDate::currentDate().year() - pupils[x]->yearborn-1];
    double result = (pupils[x]->scores[y]-norm)/norm;
    if(QString::number(result)!="nan")
    {
        if(ui->tableWidget->item(x,y)->text()=="")
        {
            ui->statusBar->showMessage("");
            return;
        }
        result = (double)qFloor(result*100)/100;
        ui->statusBar->showMessage(QString::number(result) +" "+ lvl(result));

    }
    //ui->statusBar->showMessage(ui->tableWidget->item(x,y)->text(),3000);
}
void MainWindow::loadsettings()
 {
     //if (settings->value("firstload", "1")==1);

     ui->radioButton_2->setText(settings->value("yeardefault","2000").toString());
     //dir.setPath(settings->value("filepath", "C://Program Files/LeoMur/").toString());
     //if(!dir.exists())dir.mkpath(dir.path());
     //ui->statusBar->showMessage(dir.path()+ "/file.txt",6000);
 }
void MainWindow::savesettings()
 {
     //settings->setValue("filepath",dir.path());
     settings->setValue("yeardefault",ui->radioButton_2->text().toInt());
     //settings->setValue("firstload","0");
 }
void MainWindow::destroythis()///не используется
{
    delete this;
}

void MainWindow::add_new_button()
{

    ui->pushButton->setText("Добавить");
    ui->pushButton_4->setDisabled(1);
    ui->pushButton_4->setDisabled(0);
    a->addWidget(but);
    but->setHidden(0);
    but->setDown(1);

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");    ///
    ui->radioButton_2->setChecked(1);
    ui->male_but->setChecked(1);

    for(int i = 0; i< pupils.size();i++)
    {
        pupils[i]->but->setFlat(1); //Убирает выделение с кнопок
    }
    glonum = pupils.size();
}
void MainWindow::on_radioButton_4_clicked()
{
    ui->label->setText(QString::number(QInputDialog::getInt(this, "Введите год рождения","Год",ui->radioButton_2->text().toInt(),QDate::currentDate().year()-18,QDate::currentDate().year()-6)));
}
void MainWindow::change_default_year()
{
    ui->label->setText("");
    ui->radioButton_2->setChecked(1);
    ui->radioButton_2->setText(QString::number(QInputDialog::getInt(this, "Введите год рождения","Год",ui->radioButton_2->text().toInt(),QDate::currentDate().year()-18,QDate::currentDate().year()-6)));
}
void MainWindow::on_action_triggered()
{
    QFileDialog *wnd = new QFileDialog;
    wnd->setFileMode(QFileDialog::Directory);
    wnd->setDirectory(dir.path());

    QString str = wnd->getExistingDirectory();

    if(str!="" && str != dir.path())
    {
        file->remove();
        delete file;
        file2->remove();
        delete file2;

        lastpath = dir.path();

        dir.setPath(str);
        if(!dir.exists())dir.mkpath(str);
        file = new QFile(dir.path() + "/test.txt");
        file2 = new QFile(dir.path() + "/sports.txt");
        file->open(QFile::ReadWrite);
          if (!file->isWritable() && !file->isReadable())
            {
              file->close();
                dir.setPath(lastpath);
                file = new QFile(dir.path() + "/test.txt");
                file2 = new QFile(dir.path() + "/sports.txt");
                QMessageBox::information(this,"Ошибка","Путь к файлу не изменён!");
                ui->statusBar->showMessage("Оставлен преждний путь к файлу: " + dir.path()+ "/file.txt",6000);
                writefile();
            }
          else
            {
              file->close();
              writefile();
              ui->statusBar->showMessage("Путь к файлу изменён: " + dir.path()+ "/file.txt",6000);
            }
    }
    else
    {  
        ui->statusBar->showMessage("Оставлен преждний путь к файлу: " + dir.path()+ "/file.txt",6000);
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    if(sports.size()!=0)
    {
        if(QMessageBox::question(this,"Удаление последнего элемента","Последняя дисциплина("+ sports[sports.size()-1] +") и её данные будут удалены\n\n Вы уверены, что хотите совершить это действие?")==QMessageBox::Yes)
        {

                norms.pop_back();
                sports.pop_back();
                for(int i = 0; i<pupils.size();i++)pupils[i]->scores.pop_back();
                table_repaint();
                normseditor();
                ui->tabWidget->setCurrentIndex(3);
        }
    }

    /*dir.setPath("//home/leonid/myfiles/");
    dir.mkdir("newDir");
    file = new QFile(dir.path() + "/test.txt");
     ui->statusBar->showMessage(dir.path()+ "/file.txt",6000);*/
}
void MainWindow::on_pushButton_3_clicked()
{
    QString c = QInputDialog::getText(this, "Введите название дисциплины","Название дисциплины",QLineEdit::Normal,"");
    if(c!="")
    {
        sports.push_back(c);
        QVector <int>b(18,0);
        QVector <QVector<int> >a(2,b);
        norms.push_back(a);
        for(int i = 0; i<pupils.size();i++)pupils[i]->scores.push_back(0);
        table_repaint();
        normseditor();
        for(int x = 0; x<ui->tableWidget_2->rowCount();x++)
            for(int y = 0; y<ui->tableWidget_2->columnCount();y++)
                ui->tableWidget_2->item(x,y)->setBackgroundColor(QColor(255,255,255));
        ui->tabWidget->setCurrentIndex(3);
    }
}
void MainWindow::on_action_2_triggered()
{
    cleanslot();
}

void MainWindow::tab_changed()
{
    ui->statusBar->showMessage("");
}
void MainWindow::on_groupname_but_clicked()
{
    QString a = QInputDialog::getText(this, "Измените название группы","Название",QLineEdit::Normal,nameofgroup);
    if(a!="")nameofgroup = a;
    ui->groupname_but->setText(nameofgroup);
        this->setWindowTitle("Калькулятор физ. подготовки - " + nameofgroup);
}
void MainWindow::on_action_3_triggered()
{
    ui->centralWidget->hide();
}
void MainWindow::on_lineEdit_2_returnPressed()
{
    add_edit_button();
}
void MainWindow::on_lineEdit_returnPressed()
{
    add_edit_button();
}
void MainWindow::on_pushButton_2_clicked()
{
    if(QMessageBox::question(this,"Очищение таблицы","Вы уверены, что хотите совершить это действие?")==QMessageBox::Yes)
    {
        for(int i = 0; i<pupils.size();i++)pupils[i]->scores = QVector<int>(sports.size(), 0);
        table_repaint();
    }
}
void MainWindow::on_action_4_triggered()
{
     ui->centralWidget->show();
}
bool sorting(Unit*a,Unit*b)
{
    return a->surname[0]<b->surname[0];
}
void MainWindow::sort()
{
    for(int i = 0; i<pupils.size();i++)a->removeItem(pupils[i]->lay);

    qSort(pupils.begin(),pupils.end(),sorting);     ///сортировка
    for(int i=0; i<pupils.size();i++)
    {
        a->addLayout(pupils[i]->lay);
    }
    for(int i =0;i<pupils.size();i++)pupils[i]->number=i;

}

MainWindow::~MainWindow()
{   
    writefile();
    savesettings();
    delete ui;
    emit winclosed();
}
void MainWindow::on_action_5_triggered()
{
   // norms w(this);
   // w.exec();
}
void MainWindow::on_pushButton_7_clicked()
{
    QPixmap pic = ui->customplot->toPixmap();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(pic);
    ui->statusBar->showMessage("Изображение скопировано в буфер обмена",3000);

}
void MainWindow::on_action_6_triggered()
{

    QFileDialog *wnd = new QFileDialog;
    wnd->setFileMode(QFileDialog::DirectoryOnly);


    QString str = wnd->getExistingDirectory(this,"Выберете папку с файлами класса",dir.path());



    if(str!="" && str != dir.path())
    {
        ui->statusBar->showMessage(str,6000);
        writefile();
        lastpath = dir.path();
        dir.setPath(str);
        file = new QFile(dir.path() + "/test.txt");
        file2 = new QFile(dir.path() + "/sports.txt");
        if(!dir.exists() || !file->exists())
        {
            QMessageBox::information(this,"Ошибка","В выбранной папке отсутствуют нужные файлы.");
            dir.setPath(lastpath);
            file = new QFile(dir.path() + "/test.txt");
            file2 = new QFile(dir.path() + "/sports.txt");
            ui->statusBar->showMessage("Файл не открыт. Действие отменено.",6000);
            return;
        }

        ///чистка нычек
        for(int i = 0; i<pupils.size();i++)a->removeItem(pupils[i]->lay);
        for(int i = 0; i<pupils.size();i++)delete pupils[i];
        norms.clear();
        pupils.clear();
        sports.clear();

        read();

        for(int i = 0; i<ui->tableWidget_2->rowCount();i++)
            for(int j =0; j<ui->tableWidget_2->columnCount();j++)
                ui->tableWidget_2->item(i,j)->setBackground(QColor(Qt::red));
    }
}
void MainWindow::on_action_7_triggered()
{

    QFileDialog *wnd = new QFileDialog;
    wnd->setFileMode(QFileDialog::DirectoryOnly);


    QString str = wnd->getExistingDirectory(this,"Выберете папку для файлов класса",dir.path());



    if(str!="" && str != dir.path())
    {
        ui->statusBar->showMessage(str,6000);
        writefile();
        lastpath = dir.path();
        dir.setPath(str);
        file = new QFile(dir.path() + "/test.txt");
        file2 = new QFile(dir.path() + "/sports.txt");
        if(!dir.exists() || !file->exists())
        {
            QMessageBox::information(this,"Ошибка","В выбранной папке отсутствуют нужные файлы.");
            dir.setPath(lastpath);
            file = new QFile(dir.path() + "/test.txt");
            file2 = new QFile(dir.path() + "/sports.txt");
            ui->statusBar->showMessage("Файл не открыт. Действие отменено.",6000);
            return;
        }

        ///чистка нычек
        for(int i = 0; i<pupils.size();i++)a->removeItem(pupils[i]->lay);
        for(int i = 0; i<pupils.size();i++)delete pupils[i];
        norms.clear();
        pupils.clear();
        sports.clear();

        read();

        for(int i = 0; i<ui->tableWidget_2->rowCount();i++)
            for(int j =0; j<ui->tableWidget_2->columnCount();j++)
                ui->tableWidget_2->item(i,j)->setBackground(QColor(Qt::red));
    }
}


void MainWindow::on_action_8_triggered()
{
    writefile();
    savesettings();
    ui->statusBar->showMessage("Сохранено",6000);
}

void MainWindow::on_lineEdit_2_textEdited()
{
   // QString str = ui->lineEdit_2->text();

    //for(int i = 0; i<str.size();i++)if(str[i]==' ')str[i]='_';
    //if(str3!="")ui->lineEdit_2->setText(str2+ " "+str3);
   //  ui->lineEdit_2->setText(str);
}

void MainWindow::on_lineEdit_textEdited()
{
    QString str = ui->lineEdit->text();
    for(int i = 0; i<str.size();i++)if(str[i]==' ')str[i]='_';
    ui->lineEdit->setText(str);
}

void MainWindow::on_action_9_triggered()
{
    /*menu = new MainMenu;
    connect(this,SIGNAL(winclosed()),menu,SLOT(refresh()));
    menu->show();
*/}

void MainWindow::on_action_PE_Calc_triggered()
{
     QMessageBox::information(this,"О программе...","PE_Calc - калькулятор физ. подготовки \n Разработчик: Леонид Мурашов \n l.murashov@yandex.ru");
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{

}
