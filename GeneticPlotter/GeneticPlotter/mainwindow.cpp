#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setGeometry(960, 470, this->width(), this->height());


    // create and configure plottables:
    graphBest = ui->customPlot->addGraph();
    //graphBest->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graphBest->setPen(QPen(QColor(120, 120, 120), 2));

    graphWorth = ui->customPlot->addGraph();
    //graphWorth->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graphWorth->setPen(QPen(QColor(120, 120, 120), 2));

    graphAverage = ui->customPlot->addGraph();
    //graphAverage->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graphAverage->setPen(QPen(Qt::red, 2));

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->xAxis->setLabel("Поколение");
    ui->customPlot->yAxis->setLabel("Дистанция");
    ui->customPlot->xAxis->setLabelFont(QFont("Helvetica", 15));
    ui->customPlot->yAxis->setLabelFont(QFont("Helvetica", 15));
    ui->customPlot->xAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);

    ui->customPlot->rescaleAxes();
    ui->customPlot->yAxis->setRange(0, 2);

    filePath = "D:\\delme\\logs\\logfile.txt";
    pictureFileName = "D:\\delme\\logs\\graph.png";
    file = new QFile(QString(filePath));

    bFirstRead = true;
    sliderPosition = 0;
    //ui->horizontalSlider->setValue(sliderPosition);
    ReadFromFile();

    timer = new QTimer;
    timer->setInterval(25);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(CheckUpdates()));
    timer->start();
}

void MainWindow::ReadFromFile()
{
    if (!file->open(QFile::ReadOnly)){}//QMessageBox::information(this,"Ошибка","Файл не подключен! \n Требуется изменить путь к файлу.");}
    else
    {
        maxYValue = 0;
        minYValue = 99999999999999;

        QTextStream stream(file);
        QString str;
        generation.clear();best.clear();worth.clear();average.clear();
        generation.push_back(0); best.push_back(0); worth.push_back(0); average.push_back(0);
        while (!stream.atEnd())
        {
           stream>>str;
           if(str == "")break;
           generation.push_back(str.toDouble());

           stream>>str;
           best.push_back(str.toDouble());
           if(str.toDouble() > maxYValue)maxYValue = str.toDouble();

           stream>>str;
           worth.push_back(str.toDouble());
           if(str.toDouble() < minYValue)minYValue = str.toDouble();

           stream>>str;
           average.push_back(str.toDouble());
        }
        file->close();


        if(bFirstRead && best.size()>1)
        {
            double averageStart = 0;//(best[1] + worth[1])/2;
            best[0] = averageStart;
            worth[0] = averageStart;
            average[0] = averageStart;
        }

        graphBest->setData(generation, best);
        graphWorth->setData(generation, worth);
        graphAverage->setData(generation, average);

        ui->customPlot->yAxis->setRange((minYValue-(maxYValue - minYValue)/50)<0 ? (minYValue-(maxYValue - minYValue)/50) : 0, maxYValue+(maxYValue - minYValue)/50);

        ui->label->setText(QString::number(generation.size() - 1));
         NormalizePlot();

        MarkWasRead();
    }


}

void MainWindow::MarkWasRead()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    hFind = FindFirstFile((const wchar_t*) filePath.utf16(), &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        QMessageBox::warning(this,"Ошибка","Файл не открывается!");
    }
    else
    {
        FILETIME ft = FindFileData.ftLastWriteTime;
        SYSTEMTIME st;
        GetSystemTime(&st);
        FileTimeToSystemTime(&ft, &st);
        lastTimeFileEdited = st.wMilliseconds;
        FindClose(hFind);
    }
}

void MainWindow::CheckUpdates()
{
    int timeToCheck;
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    hFind = FindFirstFile((const wchar_t*) filePath.utf16(), &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        QMessageBox::warning(this,"Ошибка","Файл не открывается!");
    }
    else
    {
        FILETIME ft = FindFileData.ftLastWriteTime;
        SYSTEMTIME st;
        GetSystemTime(&st);
        FileTimeToSystemTime(&ft, &st);
        timeToCheck = st.wMilliseconds;
        FindClose(hFind);
    }
    if(timeToCheck != lastTimeFileEdited)
        ReadFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered(bool checked)
{
    if(checked)
    {
        // Always on top
        this->setWindowFlags(Qt::WindowStaysOnTopHint);
        this->show();
    }
    else
    {
        // Deactivate always on top
        this->setWindowFlags(0);
        this->show();
    }
}

// Normalize labels and axes of the plot and demention of slider
void MainWindow::NormalizePlot()
{
    if(sliderPosition + 10 > generation.size() && generation.size() > 10)
        sliderPosition = generation.size() - 9;
    //if(sliderPosition < 0) sliderPosition = 0;

    ui->horizontalSlider->setSingleStep(generation.size() / 10);

    ui->customPlot->xAxis->setRange((-0.8-0.1 * generation.size()/100)+sliderPosition, generation.size() + 0.1* (generation.size()-sliderPosition)/100);

    ui->horizontalSlider->setRange(0, generation.size()<10 ? 0 : generation.size() - 10);
    if(generation.size() <= 10)
        ui->horizontalSlider->setEnabled(false);
    else
        ui->horizontalSlider->setEnabled(true);

    if(generation.size() - sliderPosition < 15)ui->customPlot->xAxis->setAutoTickCount((generation.size() - sliderPosition));
    else ui->customPlot->xAxis->setAutoTickCount(10);    

    ui->customPlot->replot();


    // Saving picture to file
    ///QPixmap pixmap = ui->customPlot->toPixmap(600, 400);
    ///pixmap.save(pictureFileName); (Siquel, to be continued)
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::information(this,"О программе...","Genetic Plotter \n Разработчик: Леонид Мурашов \n l.murashov@yandex.ru");
}
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    sliderPosition = value;
    NormalizePlot();
}
