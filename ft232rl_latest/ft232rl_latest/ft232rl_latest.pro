#-------------------------------------------------
#
# Project created by QtCreator 2016-01-24T14:51:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ft232rl_latest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    ftd2xx.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ -lftd2xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lftd2xx
else:unix: LIBS += -L$$PWD/ -lftd2xx

#DISTFILES += \
#    ftd2xx.lib
