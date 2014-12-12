#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T10:41:54
#
#-------------------------------------------------
QT += core gui network
win32:QT += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = Tianchi2
TEMPLATE = app

HEADERS  += mainwindow.h

SOURCES += main.cpp mainwindow.cpp

FORMS += mainwindow.ui

include($$PWD/../tianchi/tianchi.pri)
