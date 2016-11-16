#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include "ft232rl_class.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;//device);
    w.show();



   // thread.start();/**/
    return a.exec();
}
