/********************************************************************************
** Form generated from reading UI file 'camtracking.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMTRACKING_H
#define UI_CAMTRACKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamTracking
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CamTracking)
    {
        if (CamTracking->objectName().isEmpty())
            CamTracking->setObjectName(QStringLiteral("CamTracking"));
        CamTracking->resize(800, 600);
        menubar = new QMenuBar(CamTracking);
        menubar->setObjectName(QStringLiteral("menubar"));
        CamTracking->setMenuBar(menubar);
        centralwidget = new QWidget(CamTracking);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        CamTracking->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CamTracking);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CamTracking->setStatusBar(statusbar);

        retranslateUi(CamTracking);

        QMetaObject::connectSlotsByName(CamTracking);
    } // setupUi

    void retranslateUi(QMainWindow *CamTracking)
    {
        CamTracking->setWindowTitle(QApplication::translate("CamTracking", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class CamTracking: public Ui_CamTracking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMTRACKING_H
