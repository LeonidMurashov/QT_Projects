#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T17:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PE_Calc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    unit.cpp \
    qcustomplot.cpp \
    mainmenu.cpp \
    listwsort.cpp

HEADERS  += mainwindow.h \
    unit.h \
    qcustomplot.h \
    mainmenu.h \
    listwsort.h

FORMS    += mainwindow.ui \
    mainmenu.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    ../qcustomplot/documentation/qcustomplot.qch \
    qcustomplot.qch

RC_FILE = iconka.rc
#win32:RC_FILE = iconka.rc
#для статической линковки
#CONFIG += release
#CONFIG += static

#QMAKE_LFLAGS += -static -static-libgcc
#LIBS += -static-libgcc

