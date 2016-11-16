#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T16:26:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RedBallTracker
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp

HEADERS  += frmmain.h

FORMS    += frmmain.ui

INCLUDEPATH += C:\\OpenCV-3.1.0\\opencv\\build\\include
LIBS += -LC:\\OpenCV-3.1.0\\build\\x64\\vc14\\lib \
 C:\OpenCV-3.1.0\build\x64\vc14\lib\opencv_world310d.lib
