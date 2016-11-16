#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unit.h"
#include "qcustomplot.h"
#include <QFile>
#include<QSettings>
#include<QDir>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString  fileconstr, QString  dirconstr,QWidget *parent = 0);
    ~MainWindow();
    QVector<QString>sports;
    QDir dir;
    QPixmap replot(bool imggen);
    void resizeplot(int w, int h);
    QString plotsrarefm;
public slots:

    void choose(Unit *a);


private:
    Ui::MainWindow *ui;
    QVector<Unit*> pupils;

    QVBoxLayout  *a;
    QFile *file;
    QFile *file2;    
    int glonum;
    QVector<QVector<QVector<int> > >norms;
    int firstload;
    QPushButton *but;
    QSettings *settings;
    QString lastpath;
    QString nameofgroup;
    QVector<double>x,y;
    QCPGraph *graph;
    QCPGraph *graph2;
    QCPBars *bars;


    int normseditorusing;
    void loadsettings();
    void savesettings();
    void sort();
    void write(Unit *unit, int num);
    void del(int num);
    void clean();
    void read();
    void writefile();
    void table_repaint();
    void normseditor();
    int whatyear();
    int whatsex();
    QString lvl(double b);

signals:
    void unitdeleted(int num);
    void winclosed();

private slots:
    void add_new_button();
    void add_edit_button();
    void on_radioButton_4_clicked();
    void change_default_year();
    void cleanslot();
    void delslot(Unit *c);
    void tablecellchanged(int x,int y);
    void replotslot();
    void normchanged(int x, int y);
    void cellstatbar(int x,int y);
    void destroythis();

    void on_action_triggered();
    void on_pushButton_6_clicked();
    void on_action_2_triggered();

    void tab_changed();
    void on_groupname_but_clicked();
    void on_lineEdit_2_returnPressed();
    void on_lineEdit_returnPressed();
    void on_action_3_triggered();
    void on_action_4_triggered();
    void on_pushButton_2_clicked();
    void on_action_5_triggered();
    void on_pushButton_3_clicked();
    void on_pushButton_7_clicked();
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_8_triggered();
    void on_lineEdit_2_textEdited();
    void on_lineEdit_textEdited();
    void on_action_9_triggered();
    void on_action_PE_Calc_triggered();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
};


#endif // MAINWINDOW_H
