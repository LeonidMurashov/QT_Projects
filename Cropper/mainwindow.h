#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPixmap>
#include<QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector <QPixmap>pixes;
    int propx;
    int x, y, x1, y1, click;
    int counter,nameoffile;
    QString pathtofile;
    void mousePressEvent(QMouseEvent *event);
    void refresh();
    void savephoto();

private slots:
    void read();
    void display();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
