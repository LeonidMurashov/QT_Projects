2
#include "frmmain.h"
#include "ui_frmmain.h"

#include<QtCore>
#include<QMessageBox>

// constructor ////////////////////////////////////////////////////////////////////////////////////
frmMain::frmMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmMain) {
    ui->setupUi(this);

    capWebcam.open(0);                  // associate the capture object to the default webcam

    if(capWebcam.isOpened() == false) {                 // if unsuccessful
        QMessageBox::information(this, "", "error: capWebcam not accessed successfully \n\n exiting program\n");        // show error message
        exitProgram();                                  // and exit program
        return;                                         //
    }

    qtimer = new QTimer(this);                          // instantiate timer
    connect(qtimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));     // associate timer to processFrameAndUpdateGUI
    qtimer->start(20);                                  // start timer, set to cycle every 20 msec (50x per sec), it will not actually cycle this often
}

// destructor /////////////////////////////////////////////////////////////////////////////////////
frmMain::~frmMain() {
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void frmMain::exitProgram() {
    if(qtimer->isActive()) qtimer->stop();          // if timer is running, stop timer
    QApplication::quit();                           // and exit program
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void frmMain::processFrameAndUpdateGUI() {
    cv::Mat imgOriginal;                    // original image
    cv::Mat imgHSV;
    cv::Mat imgThreshLow;
    cv::Mat imgThreshHigh;
    cv::Mat imgThresh;

    bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);                    // get next frame from the webcam

    if (!blnFrameReadSuccessfully || imgOriginal.empty()) {                            // if we did not get a frame
        QMessageBox::information(this, "", "unable to read from webcam \n\n exiting program\n");        // show error via message box
        exitProgram();                                                              // and exit program
        return;                                                                     //
    }

    cv::cvtColor(imgOriginal, imgHSV, CV_BGR2HSV);

   // cv::inRange(imgHSV, cv::Scalar(0, 155, 155), cv::Scalar(18, 255, 255), imgThreshLow);
    //cv::inRange(imgHSV, cv::Scalar(165, 155, 155), cv::Scalar(179, 255, 255), imgThreshHigh);

    cv::Canny(imgOriginal,imgThresh,ui->verticalSlider->value(), ui->verticalSlider_2->value());

   // cv::add(imgThreshLow, imgThreshHigh, imgThresh);

    cv::GaussianBlur(imgThresh, imgThresh, cv::Size(3, 3), 0);

    cv::Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    cv::dilate(imgThresh, imgThresh, structuringElement);
    cv::erode(imgThresh, imgThresh, structuringElement);

    std::vector<cv::Vec3f> v3fCircles;                                                                              // declare circles variable
    cv::HoughCircles(imgThresh, v3fCircles, CV_HOUGH_GRADIENT, 2, imgThresh.rows / 4, 100, 50, 10, 400);      // fill variable circles with all circles in the processed image

    for(unsigned int i = 0; i < v3fCircles.size(); i++) {                                                                                       // for each circle
        ui->txtXYRadius->appendPlainText(QString("ball position x =") + QString::number(v3fCircles[i][0]).rightJustified(4, ' ') +              // print ball position and radius
                                                                         QString(", y =") + QString::number(v3fCircles[i][1]).rightJustified(4, ' ') +
                                                                         QString(", radius =") + QString::number(v3fCircles[i][2], 'f', 3).rightJustified(7, ' '));

        cv::circle(imgOriginal, cv::Point((int)v3fCircles[i][0], (int)v3fCircles[i][1]), (int)v3fCircles[i][2], cv::Scalar(0, 0, 255), 3);      // draw red circle around the detected object
        cv::circle(imgOriginal, cv::Point((int)v3fCircles[i][0], (int)v3fCircles[i][1]), 3, cv::Scalar(0, 255, 0), CV_FILLED);                  // draw small green circle at center of detected object
    }

    QImage qimgOriginal = convertOpenCVMatToQtQImage(imgOriginal);                         // convert from OpenCV Mat to Qt QImage
    QImage qimgThresh = convertOpenCVMatToQtQImage(imgThresh);                       //

    ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal));           // show images on form labels
    ui->lblThresh->setPixmap(QPixmap::fromImage(qimgThresh));         //
}

///////////////////////////////////////////////////////////////////////////////////////////////////
QImage frmMain::convertOpenCVMatToQtQImage(cv::Mat mat) {
    if(mat.channels() == 1) {                                   // if 1 channel (grayscale or black and white) image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // return QImage
    } else if(mat.channels() == 3) {                            // if 3 channel color image
        cv::cvtColor(mat, mat, CV_BGR2RGB);                     // flip colors
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // return QImage
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();        // return a blank QImage if the above did not work
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void frmMain::on_btnPauseOrResume_clicked() {
    if(qtimer->isActive() == true) {                // if timer is running we are currently processing an image, so . . .
        qtimer->stop();                                 // stop timer
        ui->btnPauseOrResume->setText(" Resume ");      // and update button text
    } else {                                        // else timer is not running, so we are currently paused, so . . .
        qtimer->start(20);                              // start timer again
        ui->btnPauseOrResume->setText(" Pause ");       // and update button text
    }
}

void frmMain::on_verticalSlider_sliderMoved(int position)
{

}
