/********************************************************************************
** Form generated from reading UI file 'finder.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDER_H
#define UI_FINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finder
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Finder)
    {
        if (Finder->objectName().isEmpty())
            Finder->setObjectName(QStringLiteral("Finder"));
        Finder->resize(800, 600);
        centralwidget = new QWidget(Finder);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Finder->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Finder);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Finder->setMenuBar(menubar);
        statusbar = new QStatusBar(Finder);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Finder->setStatusBar(statusbar);

        retranslateUi(Finder);

        QMetaObject::connectSlotsByName(Finder);
    } // setupUi

    void retranslateUi(QMainWindow *Finder)
    {
        Finder->setWindowTitle(QApplication::translate("Finder", "MainWindow", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Finder: public Ui_Finder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDER_H
