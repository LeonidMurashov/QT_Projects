
#include "frmmain.h"
#include "ui_frmmain.h"

#include<QtCore>
#include<QMessageBox>

// constructor ////////////////////////////////////////////////////////////////////////////////////
frmMain::frmMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmMain) {
    ui->setupUi(this);

   // this->showFullScreen();
    ui->mylbl->hide();
    ui->mylbl2->hide();
    ui->mylbl3->hide();

    capWebcam.open(1);              // associate the capture object to the default webcam

    if(capWebcam.isOpened() == false) {                 // if unsuccessful
        QMessageBox::information(this, "", "error: capWebcam not accessed successfully \n\n exiting program\n");        // show error message
        exitProgram();                          // and exit program
        return;                                 //
    }

    qtimer = new QTimer(this);                                                      // instantiate timer
    connect(qtimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));     // associate timer to processFrameAndUpdateGUI
    qtimer->start(20);                  // start timer, set to cycle every 20 msec (50x per sec), it will not actually cycle this often
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
    cv::Mat imgOriginal;                // input image
    cv::Mat imgOriginal2;
    cv::Mat imgGrayscale;               // grayscale of input image
    cv::Mat imgBlurred;                 // intermediate blured image
    cv::Mat imgCanny;                   // Canny edge image
    cv::Mat imgBoxfiltered;

    bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);                    // get next frame from the webcam

    if (!blnFrameReadSuccessfully || imgOriginal.empty()) {                            // if we did not get a frame
        QMessageBox::information(this, "", "unable to read from webcam \n\n exiting program\n");        // show error via message box
        exitProgram();                                                                              // and exit program
        return;                                                                                     //
    }

    cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);		// convert to grayscale

    cv::GaussianBlur(imgGrayscale, imgBlurred, cv::Size(5, 5), 1.8);     // blur




    int aa, ba, ca;
    if ((ui->lineEdit->text().toInt()!=0))aa = ui->lineEdit->text().toInt();
    else {aa = 1;ui->lineEdit->setText(QString::number(aa));}
    if (ui->lineEdit2->text().toInt()!=0)ba = ui->lineEdit2->text().toInt();
    else {ba = 5;ui->lineEdit2->setText(QString::number(ba));}
    if (ui->lineEdit3->text().toInt()!=0)ca = ui->lineEdit3->text().toInt();
    else {ca = 5;ui->lineEdit3->setText(QString::number(ca));}

    //cv::boxFilter(imgOriginal, imgBoxfiltered,aa,cv::Size(ba,ca));

    cv::Canny(imgBlurred, imgCanny, 50, 100);                           // get Canny edges

    QImage qimgOriginal = convertOpenCVMatToQtQImage(imgOriginal);             // convert from OpenCV Mat to Qt QImage
    QImage qimgCanny = convertOpenCVMatToQtQImage(imgCanny);
    QImage qimgBoxfiltered = convertOpenCVMatToQtQImage(imgBoxfiltered);//
    int scale = 2;
    ui->lblOriginal->setPixmap(QPixmap::fromImage(qimgOriginal).scaledToWidth(ui->lblOriginal->width()-scale));       // show images on form labels
    ui->lblCanny->setPixmap(QPixmap::fromImage(qimgCanny).scaledToWidth(ui->lblCanny->width()-scale));             //
    ui->mylbl->setPixmap(QPixmap::fromImage(qimgBoxfiltered).scaledToWidth(ui->mylbl->width()-scale));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
QImage frmMain::convertOpenCVMatToQtQImage(cv::Mat mat) {
    if(mat.channels() == 1) {                   // if grayscale image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // declare and return a QImage
    } else if(mat.channels() == 3) {            // if 3 channel color image
        cv::cvtColor(mat, mat, CV_BGR2RGB);     // invert BGR to RGB
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // declare and return a QImage
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();        // return a blank QImage if the above did not work
}

void frmMain::on_lineEdit_textChanged(const QString &arg1)
{
    ui->spinBox->setValue(arg1.toInt());
}

void frmMain::on_lineEdit2_textChanged(const QString &arg1)
{
   ui->spinBox_2->setValue(arg1.toInt());
}

void frmMain::on_lineEdit3_textChanged(const QString &arg1)
{
    ui->spinBox_3->setValue(arg1.toInt());
}

void frmMain::on_spinBox_valueChanged(int arg1)
{
    ui->lineEdit->setText(QString::number(arg1));
}

void frmMain::on_spinBox_2_valueChanged(int arg1)
{
    ui->lineEdit2->setText(QString::number(arg1));
}

void frmMain::on_spinBox_3_valueChanged(int arg1)
{
    ui->lineEdit3->setText(QString::number(arg1));
}
