#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include<QThread>
#include"mainwindow.h"

class generator : public QObject
{
    Q_OBJECT
public:
    explicit generator(QObject *parent = 0);    
    void SetupThread(QThread &thread, MainWindow *w);
signals:
    void writesig(QString str);
public slots:
    void DoWork();
private:
    MainWindow *wind;
};

#endif // GENERATOR_H
