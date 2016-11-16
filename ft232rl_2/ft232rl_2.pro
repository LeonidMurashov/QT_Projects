#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T14:33:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ft232rl_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ft232rl_class.cpp \
    camtracking.cpp

HEADERS  += mainwindow.h \
    ft232rl_class.h \
    ftd2xx.h \
    camtracking.h

FORMS    += mainwindow.ui \
    camtracking.ui

DISTFILES +=


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ -lftd2xx
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lftd2xxd
#else:unix: LIBS += -L$$PWD/ -lftd2xx


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ -lftd2xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lftd2xx
else:unix: LIBS += -L$$PWD/ -lftd2xx

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
