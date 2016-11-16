QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TEMPLATE = app
CONFIG += c++11

TARGET = GeneticPlotter2

SOURCES += main.cpp \
    qcustomplot.cpp

HEADERS += \
    qcustomplot.h
