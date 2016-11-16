#include "mainwindow.h"
#include "generator.h"
#include <QApplication>
#include<QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow;
    w->show();

    generator gen;
    QThread thread;


    gen.moveToThread(&thread);
    gen.SetupThread(thread, w);

    thread.start();


    return a.exec();
}
