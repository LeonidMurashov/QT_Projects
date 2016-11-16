
#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
namespace Ui {
    class frmMain;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
class frmMain : public QMainWindow {
    Q_OBJECT

public slots:
    void processFrameAndUpdateGUI();            // function prototype

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit2_textChanged(const QString &arg1);

    void on_lineEdit3_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

private:
    Ui::frmMain *ui;

    cv::VideoCapture capWebcam;         // Capture object to use with webcam

    QTimer* qtimer;             // timer for processFrameAndUpdateGUI()

    QImage frmMain::convertOpenCVMatToQtQImage(cv::Mat mat);       // function prototype

    void frmMain::exitProgram();                    // function prototype
};

#endif // FRMMAIN_H
