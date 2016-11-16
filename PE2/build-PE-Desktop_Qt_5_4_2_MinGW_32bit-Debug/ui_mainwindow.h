/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *groupname_but;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_5;
    QRadioButton *radioButton_3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_4;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *male_but;
    QRadioButton *female_but;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *customplot;
    QHBoxLayout *horizontalLayout_10;
    QLabel *unit_fit_lbl;
    QPushButton *pushButton_7;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/gantela.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/3floppy_unmount_5956.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_8->setIcon(icon1);
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_9->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout = new QGridLayout(tab_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        scrollArea = new QScrollArea(tab_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 471, 418));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_4->addWidget(pushButton_4);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        groupname_but = new QPushButton(tab_3);
        groupname_but->setObjectName(QStringLiteral("groupname_but"));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        groupname_but->setFont(font1);
        groupname_but->setAutoRepeat(false);
        groupname_but->setFlat(true);

        horizontalLayout_3->addWidget(groupname_but);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMouseTracking(true);
        lineEdit_2->setAcceptDrops(true);
        lineEdit_2->setEchoMode(QLineEdit::Normal);
        lineEdit_2->setDragEnabled(false);
        lineEdit_2->setReadOnly(false);
        lineEdit_2->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_2->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioButton = new QRadioButton(tab_3);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_5->addWidget(radioButton);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        radioButton_2 = new QRadioButton(tab_3);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setChecked(true);

        horizontalLayout_5->addWidget(radioButton_2);

        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_5->addWidget(pushButton_5);


        verticalLayout_5->addLayout(horizontalLayout_5);

        radioButton_3 = new QRadioButton(tab_3);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_5->addWidget(radioButton_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radioButton_4 = new QRadioButton(tab_3);
        buttonGroup->addButton(radioButton_4);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        horizontalLayout_4->addWidget(radioButton_4);

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetNoConstraint);
        male_but = new QRadioButton(tab_3);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(male_but);
        male_but->setObjectName(QStringLiteral("male_but"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(male_but->sizePolicy().hasHeightForWidth());
        male_but->setSizePolicy(sizePolicy);
        male_but->setChecked(true);

        horizontalLayout_8->addWidget(male_but);

        female_but = new QRadioButton(tab_3);
        buttonGroup_2->addButton(female_but);
        female_but->setObjectName(QStringLiteral("female_but"));
        sizePolicy.setHeightForWidth(female_but->sizePolicy().hasHeightForWidth());
        female_but->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(female_but);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setAcceptDrops(false);
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton->setFlat(false);

        verticalLayout->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tableWidget = new QTableWidget(tab_4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_6 = new QHBoxLayout(tab);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(listWidget);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        customplot = new QCustomPlot(tab);
        customplot->setObjectName(QStringLiteral("customplot"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(customplot->sizePolicy().hasHeightForWidth());
        customplot->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(customplot);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        unit_fit_lbl = new QLabel(tab);
        unit_fit_lbl->setObjectName(QStringLiteral("unit_fit_lbl"));
        sizePolicy1.setHeightForWidth(unit_fit_lbl->sizePolicy().hasHeightForWidth());
        unit_fit_lbl->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(14);
        font2.setItalic(true);
        unit_fit_lbl->setFont(font2);

        horizontalLayout_10->addWidget(unit_fit_lbl);

        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_10->addWidget(pushButton_7);


        verticalLayout_6->addLayout(horizontalLayout_10);


        horizontalLayout_6->addLayout(verticalLayout_6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        tableWidget_2 = new QTableWidget(tab_2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout_7->addWidget(tableWidget_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_9->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_9->addWidget(pushButton_6);


        verticalLayout_7->addLayout(horizontalLayout_9);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_2, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, radioButton_4);
        QWidget::setTabOrder(radioButton_4, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, scrollArea);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_2);
        menu->addAction(action_8);
        mainToolBar->addAction(action_8);

        retranslateUi(MainWindow);
        QObject::connect(radioButton_2, SIGNAL(clicked()), label, SLOT(clear()));
        QObject::connect(radioButton, SIGNAL(clicked()), label, SLOT(clear()));
        QObject::connect(radioButton_3, SIGNAL(clicked()), label, SLOT(clear()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \321\204\320\270\320\267. \320\277\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\272\320\270 - LeoMur", 0));
        action->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\276\320\262", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\267. \320\237\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\272\320\260", 0));
        action_4->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\203\321\207\320\265\320\275\320\270\320\272\320\276\320\262", 0));
        action_5->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\321\202\320\270\320\262\321\213", 0));
        action_6->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\321\200\321\203\320\263\320\276\320\271 \320\272\320\273\320\260\321\201\321\201", 0));
        action_7->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\272\320\273\320\260\321\201\321\201", 0));
        action_8->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        action_8->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_9->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \321\203\321\207\320\265\320\275\320\270\320\272\320\260", 0));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", 0));
#ifndef QT_NO_TOOLTIP
        groupname_but->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\266\320\274\320\270\321\202\320\265, \321\207\321\202\320\276\320\261\321\213 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", 0));
#endif // QT_NO_TOOLTIP
        groupname_but->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_2->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        lineEdit_2->setInputMask(QString());
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\230\320\274\321\217</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-style:italic;\">\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:</span></p></body></html>", 0));
        radioButton->setText(QApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\276\320\264 \320\274\320\265\320\275\321\214\321\210\320\265", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "2000", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\263\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217, \320\267\320\260\320\264\320\260\320\262\320\260\320\265\320\274\321\213\320\271 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0));
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\276\320\264 \320\261\320\276\320\273\321\214\321\210\320\265", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_4->setToolTip(QApplication::translate("MainWindow", "\320\224\321\200\321\203\320\263\320\270\320\265 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\321\213", 0));
#endif // QT_NO_TOOLTIP
        radioButton_4->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\276\320\261\321\213\320\271 \321\201\320\273\321\203\321\207\320\260\320\271", 0));
        label->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-style:italic;\">\320\237\320\276\320\273:</span></p></body></html>", 0));
        male_but->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\266.", 0));
        female_but->setText(QApplication::translate("MainWindow", "\320\226\320\265\320\275.", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\203\321\207\320\265\320\275\320\270\320\272\320\276\320\262", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\266\320\274\320\270\321\202\320\265, \321\207\321\202\320\276\320\261\321\213 \321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\270\320\267 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        unit_fit_lbl->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\261\321\203\320\264\320\265\321\202 \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260", 0));
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260", 0));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\271", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\321\202\320\270\320\262\321\213", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
