#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    protected:
    bool eventFilter(QObject * obj, QEvent * event);
    return a.exec();
}
