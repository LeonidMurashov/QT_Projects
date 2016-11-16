#ifndef FT232RL_CLASS_H
#define FT232RL_CLASS_H

#include <QObject>
#include <windows.h>
#include "ftd2xx.h"

#include<QThread>

class ft232rl_class : public QObject
{
    Q_OBJECT
public:
    ~ft232rl_class();
    explicit ft232rl_class(QObject *parent = 0);
    bool stopbit;
signals:
    void refresh(QString str);
public slots:
    QString maininmainwindow();
    void maininmainwindow_control();
    void swich_of();
    void TIME_changed();
public:
    int LED;
    int BUT;
    unsigned long long TIME;
     FT_HANDLE handle;
    void setupthread(QThread &thread);
private:




    unsigned char port;
     unsigned char statePort;
     unsigned int count;
     char buf;
     DWORD numBytes;




};

#endif // FT232RL_CLASS_H
