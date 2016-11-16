#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include<QGraphicsItem>
#include"qcustomplot.h"
#include<QPixmap>
#include<QClipboard>
#include <QSettings>
#include "mainwindow.h"
#include<QListWidget>
#include<listwsort.h>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_listWidget_doubleClicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void refresh();

    void on_pushButton_7_clicked();
    void on_listWidget_currentRowChanged();

    void on_action_triggered();

private:
    Ui::MainMenu *ui;
    void loadsettings();
    void savesettings();
    void read();
    bool sortfact(listWsort *a, listWsort *b);
    void sort();
    QDir  *dir;
    QSettings * settings;
    QVector <listWsort*> list;
    MainWindow *win;
    QPixmap plot;
    QListWidget * listWidget;



};

#endif // MAINMENU_H
