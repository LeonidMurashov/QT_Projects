/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblOriginal;
    QLabel *lblThresh;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPauseOrResume;
    QPlainTextEdit *txtXYRadius;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(852, 669);
        centralWidget = new QWidget(frmMain);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblOriginal = new QLabel(centralWidget);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblOriginal->sizePolicy().hasHeightForWidth());
        lblOriginal->setSizePolicy(sizePolicy);
        lblOriginal->setAutoFillBackground(true);
        lblOriginal->setFrameShape(QFrame::Box);
        lblOriginal->setMidLineWidth(0);

        horizontalLayout->addWidget(lblOriginal);

        lblThresh = new QLabel(centralWidget);
        lblThresh->setObjectName(QStringLiteral("lblThresh"));
        sizePolicy.setHeightForWidth(lblThresh->sizePolicy().hasHeightForWidth());
        lblThresh->setSizePolicy(sizePolicy);
        lblThresh->setAutoFillBackground(true);
        lblThresh->setFrameShape(QFrame::Box);
        lblThresh->setMidLineWidth(0);

        horizontalLayout->addWidget(lblThresh);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnPauseOrResume = new QPushButton(centralWidget);
        btnPauseOrResume->setObjectName(QStringLiteral("btnPauseOrResume"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnPauseOrResume->sizePolicy().hasHeightForWidth());
        btnPauseOrResume->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnPauseOrResume);

        txtXYRadius = new QPlainTextEdit(centralWidget);
        txtXYRadius->setObjectName(QStringLiteral("txtXYRadius"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txtXYRadius->sizePolicy().hasHeightForWidth());
        txtXYRadius->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(txtXYRadius);

        verticalSlider_2 = new QSlider(centralWidget);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(verticalSlider_2->sizePolicy().hasHeightForWidth());
        verticalSlider_2->setSizePolicy(sizePolicy3);
        verticalSlider_2->setMaximum(255);
        verticalSlider_2->setValue(100);
        verticalSlider_2->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_2);

        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        sizePolicy3.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy3);
        verticalSlider->setMaximum(255);
        verticalSlider->setValue(200);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        frmMain->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(frmMain);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        frmMain->setStatusBar(statusBar);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QMainWindow *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "frmMain", 0));
        lblOriginal->setText(QString());
        lblThresh->setText(QString());
        btnPauseOrResume->setText(QApplication::translate("frmMain", "Resume", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
