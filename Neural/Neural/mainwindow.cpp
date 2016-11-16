#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->installEventFilter(this);
}
bool MainWindow::eventFilter(QObject * obj, QEvent * event)
{
    if ((event->type() == QEvent::MouseButtonPress))
    {
        QMessageBox mes;
        mes.setText(obj->objectName());
        mes.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
