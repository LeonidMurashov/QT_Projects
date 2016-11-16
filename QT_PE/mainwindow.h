#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unit.h"
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
    explicit MainWindow(QWidget *parent = 0 );
    ~MainWindow();
    void write(Unit *unit, int num);
    void del(int num);
    void clean();
    void read();
    int whatyear();

public slots:
    void cleanslot();    
    void delslot(Unit *c);
    void choose(Unit *a);

private:
    Ui::MainWindow *ui;
    QVector<Unit*> pupils;
    QVBoxLayout  *a;
    QFile *file;
    QDir dir;
    int glonum;
    int firstload;
    QPushButton *but;
    QSettings *settings;
    QString lastpath;
    void loadsettings();
    void savesettings();

signals:
    void unitdeleted(int num);

private slots:
    void add_new_button();
    void add_edit_button();
    void on_radioButton_4_clicked();
    void change_default_year();

    void on_action_triggered();
    void on_pushButton_6_clicked();
    void on_action_2_triggered();
};

#endif // MAINWINDOW_H
