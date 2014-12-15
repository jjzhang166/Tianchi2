#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T10:41:54
#
#-------------------------------------------------
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin
TARGET = $$qtLibraryTarget(tianchi2_sample)
TEMPLATE = app
CONFIG += c++11

TIANCHIDIR = $$PWD/../tianchi
include($$TIANCHIDIR/tianchi_all.pri)

HEADERS += mainwindow.h

SOURCES += main.cpp mainwindow.cpp

FORMS += mainwindow.ui

RC_ICONS += images/qt32.ico

VERSION = 1.0.0.0
#注意：中文时必须采用 GBK 编码
QMAKE_TARGET_PRODUCT = Tianchi2 sample
QMAKE_TARGET_COMPANY = Jonix Fu
QMAKE_TARGET_DESCRIPTION = Sample for Tianchi2.
QMAKE_TARGET_COPYRIGHT = Jonix Fu. jonix@qtcn.org

