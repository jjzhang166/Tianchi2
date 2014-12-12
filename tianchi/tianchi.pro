QT += core gui network
win32:QT += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 

TARGET = $$qtLibraryTarget(TianChi)
TEMPLATE = lib

DEFINES += TIANCHI_API=Q_CORE_EXPORT

include($$PWD/tianchi.pri)

VERSION = 2.0.0
