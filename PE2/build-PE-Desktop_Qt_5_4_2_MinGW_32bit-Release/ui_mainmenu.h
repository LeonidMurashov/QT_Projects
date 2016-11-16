/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QLabel *unit_fit_lbl;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(1000, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/PE_Calc.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainMenu->setWindowIcon(icon);
        MainMenu->setWindowOpacity(1);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(26);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font1;
        font1.setPointSize(14);
        pushButton->setFont(font1);

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(72);
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        unit_fit_lbl = new QLabel(centralwidget);
        unit_fit_lbl->setObjectName(QStringLiteral("unit_fit_lbl"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(unit_fit_lbl->sizePolicy().hasHeightForWidth());
        unit_fit_lbl->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setPointSize(14);
        font3.setItalic(true);
        unit_fit_lbl->setFont(font3);

        horizontalLayout->addWidget(unit_fit_lbl);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        QFont font4;
        font4.setPointSize(12);
        pushButton_7->setFont(font4);

        horizontalLayout->addWidget(pushButton_7);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \321\204\320\270\320\267. \320\277\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\272\320\270 - LeoMur", 0));
        label->setText(QApplication::translate("MainMenu", "\320\232\320\273\320\260\321\201\321\201\321\213:", 0));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainMenu", "\320\224\320\276\320\261\320\260\321\213\320\270\321\202\321\214 \320\272\320\273\320\260\321\201\321\201", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainMenu", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271", 0));
        label_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainMenu", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainMenu", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        pushButton_2->setShortcut(QApplication::translate("MainMenu", "Del", 0));
        unit_fit_lbl->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("MainMenu", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\261\321\203\320\264\320\265\321\202 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260", 0));
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QApplication::translate("MainMenu", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
