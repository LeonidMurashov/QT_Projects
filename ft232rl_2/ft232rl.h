#ifndef FT232RL_H
#define FT232RL_H

#include <QObject>

class ft232rl : public QObject
{
    Q_OBJECT
public:
    ft232rl();

signals:
    void refresh(QString str);
public slots:
private:
    void maininmainwindow();
};

#endif // FT232RL_H
