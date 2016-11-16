#ifndef CAMTRACKING_H
#define CAMTRACKING_H

#include <QMainWindow>

namespace Ui {
class CamTracking;
}

class CamTracking : public QMainWindow
{
    Q_OBJECT

public:
    explicit CamTracking(QWidget *parent = 0);
    ~CamTracking();

private:
    Ui::CamTracking *ui;
};

#endif // CAMTRACKING_H
