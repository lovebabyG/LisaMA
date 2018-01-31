#-------------------------------------------------
#
# Project created by QtCreator 2018-01-27T20:55:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    CEO.cpp \
    Manager.cpp

HEADERS  += mainwindow.h \
    CEO.h \
    globaldefine.h \
    Manager.h

FORMS    += mainwindow.ui
