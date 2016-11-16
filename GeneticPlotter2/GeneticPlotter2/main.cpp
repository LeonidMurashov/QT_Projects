#include <QCoreApplication>
#include <QPixmap>
#include "qcustomplot.h"

#define DEFAILT_SIZE_X 800
#define DEFAILT_SIZE_Y 600
#define DEFAULT_FINPUTADRESS "D:\\delme\\logs\\logfile.txt"
#define DEFAULT_FOUTPUTADRESS "D:\\delme\\logs\\graph.png"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<double> generation, best, worth, average;

    // Parse command line for parameters
    QCommandLineParser parser;

    parser.addPositionalArgument("size_x", "Size X.");
    parser.addPositionalArgument("size_y", "Size Y.");
    parser.addPositionalArgument("fInputAdress", "Input file adress (.txt).");
    parser.addPositionalArgument("fOutputAdress", "Output file adress (.png).");

    // Call parse() to find out the positional arguments.
    parser.parse(QCoreApplication::arguments());

    const QStringList args = parser.positionalArguments();
    int size_X = args.size() < 1 ? DEFAILT_SIZE_X : args[0].toInt();
    int size_Y = args.size() < 2 ? DEFAILT_SIZE_X : args[1].toInt();
    QString fInputAdress = args.size() < 3 ? DEFAULT_FINPUTADRESS : args[2];
    QString fOutputAdress = args.size() < 4 ? DEFAULT_FOUTPUTADRESS : args[3];


    //DEBUG delme

    QFile *db = new QFile("D:\\delme\\logs\\logfileDEBUG.txt");
    if (!db->open(QFile::WriteOnly)){}//QMessageBox::information(this,"Ошибка","Файл не подключен! \n Требуется изменить путь к файлу.");}
    else
    {
        QTextStream stream(db);
        stream<<fOutputAdress;
        db->close();
    }



    ////////////////////////////////////////////////////
    // Graph creating part  ////////////////////////////
    ////////////////////////////////////////////////////

    QCustomPlot * customPlot = new QCustomPlot;
    QCPGraph *graphBest;
    QCPGraph *graphWorth;
    QCPGraph *graphAverage;

    // create and configure plottables:
    graphBest = customPlot->addGraph();
    //graphBest->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graphBest->setPen(QPen(QColor(120, 120, 120), 2));

    graphWorth = customPlot->addGraph();
    //graphWorth->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graphWorth->setPen(QPen(QColor(120, 120, 120), 2));

    graphAverage = customPlot->addGraph();
    //graphAverage->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graphAverage->setPen(QPen(Qt::red, 2));

    // set some pens, brushes and backgrounds:
    customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    customPlot->axisRect()->setBackground(axisRectGradient);

    customPlot->xAxis->setLabel("Поколение");
    customPlot->yAxis->setLabel("Дистанция");
    customPlot->xAxis->setLabelFont(QFont("Helvetica", 15));
    customPlot->yAxis->setLabelFont(QFont("Helvetica", 15));
    customPlot->xAxis->setLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);

    customPlot->rescaleAxes();
    customPlot->yAxis->setRange(0, 2);

   ////////////////////////////////////////////////////
   // Reading part  ///////////////////////////////////
   ////////////////////////////////////////////////////
    double maxYValue = 0;
    double minYValue = 999999999999;

    QFile *fInput = new QFile(fInputAdress);
    if (!fInput->open(QFile::ReadOnly)){}//QMessageBox::information(this,"Ошибка","Файл не подключен! \n Требуется изменить путь к файлу.");}
    else
    {
        QTextStream stream(fInput);
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
        fInput->close();

        if(best.size()>1)
        {
            double averageStart = 0;//(best[1] + worth[1])/2;
            best[0] = averageStart;
            worth[0] = averageStart;
            average[0] = averageStart;
        }

        graphBest->setData(generation, best);
        graphWorth->setData(generation, worth);
        graphAverage->setData(generation, average);

        customPlot->yAxis->setRange((minYValue-(maxYValue - minYValue)/50)<0 ? (minYValue-(maxYValue - minYValue)/50) : 0, maxYValue+(maxYValue - minYValue)/50);


        // Normalize Plot
        customPlot->xAxis->setRange((-0.8-0.1 * generation.size()/100), generation.size() + 0.1* (generation.size())/100);

        if(generation.size() < 15)customPlot->xAxis->setAutoTickCount(generation.size());
        else customPlot->xAxis->setAutoTickCount(10);

        customPlot->replot();
    }

    // Saving picture to file
    QPixmap pixmap = customPlot->toPixmap(size_X, size_Y);
    pixmap.save(fOutputAdress);
}
