#include "camtracking.h"
#include "ui_camtracking.h"

CamTracking::CamTracking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CamTracking)
{
    ui->setupUi(this);
}

CamTracking::~CamTracking()
{
    delete ui;
}
