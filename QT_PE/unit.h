#ifndef UNIT_H
#define UNIT_H


#include<QPushButton>
#include<QLabel>
#include<QHBoxLayout>
#include<QFile>
#include <QMainWindow>
#include<QMessageBox>

class MainWindow;
class Unit : public QWidget   //!!!!!!!!!!!!! public
{
    Q_OBJECT
public:

    QHBoxLayout *lay;
    QPushButton *but;
    QPushButton *delbut;
    QLabel *lbl;
    QString name;
    QString surname;
    QVector <int> scores;
    int number;
    int yearborn;
    void rename();
    void registeration(QString str);
    QString unregistration();
    ~Unit();

    Unit(QString nam,QString surnam,int num,int year, MainWindow * parent);
public slots:
    void clickedslot()
    {

        emit clicked(this);

    }
    void clickeddelslot()
    {

        emit clickeddel(this);

    }
    void numchanged(int num)
    {
        if(number>num)number--;
    }

signals:
    void clicked(Unit *a); // <- сигнал пишется вот так
    void clickeddel(Unit *a);



};

#endif // UNIT_H
