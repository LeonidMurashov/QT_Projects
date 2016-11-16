#include "mainmenu.h"
#include "ui_mainmenu.h"
#include<QGraphicsItem>
#include"qcustomplot.h"
#include<QPixmap>
#include<QClipboard>
#include<QSettings>
#include"mainwindow.h"
#include<QApplication>
#include<QFont>
#include"listwsort.h"
#include<QWidget>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    //QSettings set("LeoMur","PE_Calc_mainmenu");
    dir = new QDir;

    settings = new QSettings("LeoMur", "PE_calc_mainmenu",this);
    loadsettings();
    listWidget = new QListWidget;
    listWidget->setBaseSize(256,457);
    listWidget->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    ui->gridLayout->addWidget(listWidget);


    read();


    MainWindow * plotgen = new MainWindow("","");
    plotgen->resizeplot(770+this->size().width()-1050, 500+this->size().height()-600);
    plot = plotgen->replot(1);
    ui->label_2->setPixmap(plot);
 ///// далее работа только с listWidget
    QFont font;
    font.setPixelSize(14);
    listWidget->setFont(font);

    connect(this->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(on_listWidget_currentRowChanged()));
    //connect(this,SIGNAL(), SIGNAL(resized(int)), this, SLOT(on_listWidget_currentRowChanged()));
    connect(this->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listWidget_doubleClicked()));
    if(list.size()>0)
    {
        listWidget->setCurrentRow(0);
    }

}
void MainMenu::read()
{
    //int ab = 0;
    QString path = dir->absolutePath();
    delete dir;
    dir = new QDir(path);

    foreach (QFileInfo tmp, dir->entryInfoList())
    {
        //bool z =  QFile::exists(tmp.absoluteFilePath());
        //bool y =  tmp.fileName()!="sports.txt";
        //bool x =  tmp.isFile();
        if(tmp.isFile() && tmp.fileName()!="sports.txt" && QFile::exists(tmp.absoluteFilePath()))
        {
            listWsort *listwsort = new listWsort(tmp.filePath(),tmp.absoluteDir().absolutePath(),new QListWidgetItem,-1,"__");
            list.push_back(listwsort);

            QFile *file = new QFile(tmp.absoluteFilePath());
            if (!file->open(QFile::ReadOnly)){QMessageBox::information(this,"Ошибка","Не все файлы прочтены! \n Обратитесь к разработчику. \n File name = " +tmp.fileName() );}
            else
            {
                    QString str;
                    str = file->readLine();
                    str.resize(str.size()-2);
                    int i =0;
                    while(!file->atEnd())
                    {
                        i++;
                        file->readLine();
                    }
                    listwsort->pupils=i;
                    listwsort->str=str;

                    if(i%10==1)listwsort->item->setText(str + " - " + QString::number(i) + " ученик\n");
                    else if(i%10>4 || i%10==0)listwsort->item->setText(str + " - " + QString::number(i) + " учеников\n");
                    else listwsort->item->setText(str + " - " + QString::number(i) + " ученика\n");
                    listwsort->item->setToolTip("Кликните два раза, чтобы открыть");
                    file->close();
            }
        }
    }


    sort();
}


void MainMenu::sort()
{
    for(int i=0;i<list.size();i++)
    {
        for(int j=0;j<list.size();j++)
        {
            if(i>=j){continue;}
            if(!sortfact(list[i],list[j]))qSwap(list[i],list[j]);
        }
    }
    for(int j=0; j<list.size();j++)
    {
        int i = list[j]->pupils;
        QString str = list[j]->str;
        if(i%10==1)list[j]->item->setText(str + " - " + QString::number(i) + " ученик\n");
        else if(i%10>4 || i%10==0)list[j]->item->setText(str + " - " + QString::number(i) + " учеников\n");
        else list[j]->item->setText(str + " - " + QString::number(i) + " ученика\n");
        listWidget->addItem(list[j]->item);
    }
    //qSort(list.begin(),list.end(),sortfact);
}

/**/

void MainMenu::loadsettings()
{
    dir->setPath(settings->value("filepath", QApplication::applicationDirPath()+"/Data/").toString());
    if(settings->value("work_allowed","1")=="0"){QMessageBox::information(this,"Ошибка","Доступ заблокирован!");delete this;}
    //dir->setPath(settings->value("filepath", "D://gg/PE_Calc/").toString());
    if(!dir->exists())dir->mkpath(dir->path());
    //QMessageBox::information(this,QApplication::applicationDirPath(),"Файл не подключен! \n Данные не будут сохранены.");

}

void MainMenu::savesettings()
{
    settings->setValue("filepath",dir->absolutePath());
    settings->setValue("work_allowed",settings->value("work_allowed","1"));
}
MainMenu::~MainMenu()
{
    savesettings();
    delete ui;
}
void MainMenu::on_listWidget_doubleClicked()
{
    //function(index, files, files2);
    win = new MainWindow(list[listWidget->currentRow()]->files,list[listWidget->currentRow()]->files2);
    connect(win,SIGNAL(winclosed()),this,SLOT(refresh()));
    win->show();

}
void MainMenu::on_pushButton_clicked()//добавление
{
    QString nameofnew = QInputDialog::getText(this,"Создание класса","Название");
    if(nameofnew=="")return;
    int i=0;
    QFile *file;
    while(1)
    {

        file = new QFile(dir->absolutePath()+"/"+QString::number(i)+".txt");
        if(file->exists() == 0)break;
        i++;
    }
    if (!file->open(QFile::WriteOnly)){QMessageBox::information(this,"Ошибка","Файл не подключен! \n Данные не будут сохранены.");}
    else  {
      QTextStream stream(file);
      stream.setCodec(QTextCodec::codecForName("UTF-8"));
      stream<<nameofnew<<'\r'<<'\n';
      stream.flush();
      file->close();
    }
    listWidget->addItem(nameofnew+" - 0 учеников\n");
    win = new MainWindow(dir->absolutePath()+"/" + QString::number(i)+".txt",dir->absolutePath());
    connect(win,SIGNAL(winclosed()),this,SLOT(refresh()));
    win->show();


}
void MainMenu::on_pushButton_2_clicked() //удаление
{

    //QMessageBox::information(this,QString::number(listWidget->currentRow()),"Файл не подключен! \n Данные не будут сохранены.");
   if(listWidget->currentRow()<0)return;
    QMessageBox::StandardButton sbut;
    sbut = QMessageBox::question(this,"Удаление класса", "Вы уверены, что хотите безвозвратно удалить " + listWidget->currentItem()->text() + "?", QMessageBox::Yes | QMessageBox::Cancel);

    if(sbut == QMessageBox::Yes)
    {
        //QFile * file = new QFile(files2[listWidget->currentRow()]);
        //file->remove();
        //DeleteFileA(files2[listWidget->currentRow()]);
        QString b = list[listWidget->currentRow()]->files;
        QFile file(b);

        file.remove();
        //QFile::remove(b);
        //QMessageBox::information(this,QString::number(a),b+" \n Данные не будут сохранены.");
        refresh();

        //listWidget->currentItem()->setBackgroundColor(QColor(255,50,50));
    }
    //QFile file = new QFile(files2[])
}

void MainMenu::refresh()
{
    //for (int i=listWidget->count(); i>0;i--)listWidget->removeItemWidget(listWidget->item(i));
  /*  listWidget->removeItemWidget(listWidget->item(5));
    listWidget->removeItemWidget(listWidget->item(4));
    listWidget->removeItemWidget(listWidget->item(3));
    listWidget->removeItemWidget(listWidget->item(2));
    listWidget->removeItemWidget(listWidget->item(1));
    listWidget->removeItemWidget(listWidget->item(0));*/
    delete listWidget;
    listWidget = new QListWidget;
    QFont font;
    font.setPixelSize(14);
    listWidget->setFont(font);
    connect(this->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(on_listWidget_currentRowChanged()));
    connect(this->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_listWidget_doubleClicked()));
    ui->gridLayout->addWidget(listWidget);
    //QMessageBox::information(this,QString::number(listWidget->count())," \n Данные не будут сохранены.");

    list.resize(0);
    read();
}


void MainMenu::on_pushButton_7_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(plot);
    ui->statusbar->showMessage("Изображение скопировано в буфер обмена",3000);
}

void MainMenu::on_listWidget_currentRowChanged()
{
    MainWindow * plotgen = new MainWindow(list[listWidget->currentRow()]->files, list[listWidget->currentRow()]->files2);
    plot = plotgen->replot(1);
    ui->unit_fit_lbl->setText(plotgen->plotsrarefm);
    plotgen->resizeplot(770+this->size().width()-1050, 500+this->size().height()-600);
    plot = plotgen->replot(1);
    ui->label_2->setPixmap(plot);

}
bool MainMenu::sortfact(listWsort *a,listWsort *b)///фактор сортировки классов
{
    QString c = a->item->text(), d = b->item->text();
    int x=0,y=0;
    if(c[0]=='1')
    {
        if(c[1]=='1')x+=11;
        else if (c[1]=='0')x+=10;
        else x+=1;
    }
    else
    {
        if(c[0]=='2' || c[0]=='3' || c[0]=='4' || c[0]=='5' || c[0]=='6' || c[0]=='7' || c[0]=='8' || c[0]=='9'){
            if(c[0]=='2')x+=2;if(c[0]=='3')x+=3;if(c[0]=='4')x+=4;if(c[0]=='5')x+=5;if(c[0]=='6')x+=6;if(c[0]=='7')x+=7;if(c[0]=='8')x+=8;if(c[0]=='9')x+=9;}
        else x+=45;
    }

    if(d[0]=='1')
    {
        if(d[1]=='1')y+=11;
        else if (d[1]=='0')y+=10;
        else y+=1;
    }
    else
    {
        if(d[0]=='2' || d[0]=='3' || d[0]=='4' || d[0]=='5' || d[0]=='6' || d[0]=='7' || d[0]=='8' || d[0]=='9'){
            if(d[0]=='2')y+=2;if(d[0]=='3')y+=3;if(d[0]=='4')y+=4;if(d[0]=='5')y+=5;if(d[0]=='6')y+=6;if(d[0]=='7')y+=7;if(d[0]=='8')y+=8;if(d[0]=='9')y+=9;}
        else y+=45;
    }

    //////
    if(x==y)
    {
        if(c[1]=='0' || c[1]=='1')
        {
            return c[2]<d[2];
        }
        else
        {
            return c[1]<d[1];
        }
    }
    return x<y;
}

void MainMenu::on_action_triggered()
{
    QMessageBox::information(this,"О программе...","PE_Calc - калькулятор физ. подготовки \n Разработчик: Леонид Мурашов \n l.murashov@yandex.ru");
}
