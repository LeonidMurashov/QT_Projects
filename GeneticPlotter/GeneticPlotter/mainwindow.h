#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include "qcustomplot.h"

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
    void ReadFromFile();

    QCPGraph *graphBest;
    QCPGraph *graphWorth;
    QCPGraph *graphAverage;


    bool bFirstRead;
    int sliderPosition;
    double maxYValue = 0, minYValue = 99999999999999;

    QTimer *timer;
    QString filePath;
    QString pictureFileName;
    QVector<double> generation, best, worth, average;
    QFile *file;
    int lastTimeFileEdited;
    void MarkWasRead();
    void NormalizePlot();
private slots:
    void CheckUpdates();
    void on_action_triggered(bool checked);
    void on_action_2_triggered();
    void on_horizontalSlider_valueChanged(int value);
};

#endif // MAINWINDOW_H
