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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblOriginal;
    QLabel *lblCanny;
    QLabel *mylbl;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mylbl2;
    QLabel *mylbl3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit3;
    QSpinBox *spinBox_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1579, 911);
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

        lblCanny = new QLabel(centralWidget);
        lblCanny->setObjectName(QStringLiteral("lblCanny"));
        sizePolicy.setHeightForWidth(lblCanny->sizePolicy().hasHeightForWidth());
        lblCanny->setSizePolicy(sizePolicy);
        lblCanny->setAutoFillBackground(true);
        lblCanny->setFrameShape(QFrame::Box);
        lblCanny->setMidLineWidth(0);

        horizontalLayout->addWidget(lblCanny);

        mylbl = new QLabel(centralWidget);
        mylbl->setObjectName(QStringLiteral("mylbl"));
        mylbl->setEnabled(true);
        sizePolicy.setHeightForWidth(mylbl->sizePolicy().hasHeightForWidth());
        mylbl->setSizePolicy(sizePolicy);
        mylbl->setAutoFillBackground(true);
        mylbl->setFrameShape(QFrame::Box);
        mylbl->setMidLineWidth(0);

        horizontalLayout->addWidget(mylbl);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mylbl2 = new QLabel(centralWidget);
        mylbl2->setObjectName(QStringLiteral("mylbl2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mylbl2->sizePolicy().hasHeightForWidth());
        mylbl2->setSizePolicy(sizePolicy1);
        mylbl2->setAutoFillBackground(true);
        mylbl2->setFrameShape(QFrame::Box);
        mylbl2->setMidLineWidth(0);

        horizontalLayout_2->addWidget(mylbl2);

        mylbl3 = new QLabel(centralWidget);
        mylbl3->setObjectName(QStringLiteral("mylbl3"));
        sizePolicy1.setHeightForWidth(mylbl3->sizePolicy().hasHeightForWidth());
        mylbl3->setSizePolicy(sizePolicy1);
        mylbl3->setAutoFillBackground(true);
        mylbl3->setFrameShape(QFrame::Box);
        mylbl3->setMidLineWidth(0);

        horizontalLayout_2->addWidget(mylbl3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 2, -1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(lineEdit);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(1000);
        spinBox->setValue(50);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        lineEdit2 = new QLineEdit(centralWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        sizePolicy2.setHeightForWidth(lineEdit2->sizePolicy().hasHeightForWidth());
        lineEdit2->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(lineEdit2);

        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(1000);
        spinBox_2->setValue(99);

        horizontalLayout_4->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_4);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        lineEdit3 = new QLineEdit(centralWidget);
        lineEdit3->setObjectName(QStringLiteral("lineEdit3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit3->sizePolicy().hasHeightForWidth());
        lineEdit3->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(lineEdit3);

        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(1000);
        spinBox_3->setValue(5);

        horizontalLayout_5->addWidget(spinBox_3);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        frmMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(frmMain);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1579, 21));
        frmMain->setMenuBar(menuBar);
        mainToolBar = new QToolBar(frmMain);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        frmMain->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
        lblCanny->setText(QString());
        mylbl->setText(QString());
        mylbl2->setText(QString());
        mylbl3->setText(QString());
        label->setText(QApplication::translate("frmMain", "depth", 0));
        lineEdit->setText(QApplication::translate("frmMain", "50", 0));
        label_2->setText(QApplication::translate("frmMain", "sizex", 0));
        lineEdit2->setText(QApplication::translate("frmMain", "100", 0));
        label_3->setText(QApplication::translate("frmMain", "sizey", 0));
        lineEdit3->setText(QApplication::translate("frmMain", "5", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
