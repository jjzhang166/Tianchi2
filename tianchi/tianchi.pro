QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 
CONFIG += shared
DESTDIR = ../bin

#TARGET = $$qtLibraryTarget(Qt5Tianchi)
TARGET = Qt5Tianchi
TEMPLATE = lib

#DEFINES += TIANCHI_API=Q_CORE_EXPORT
DEFINES += TIANCHI_API=Q_DECL_EXPORT

include($$PWD/tianchi_all.pri)

VERSION = 0.2.1

#注意：中文时必须采用 GBK 编码
QMAKE_TARGET_PRODUCT = Tianchi2
QMAKE_TARGET_COMPANY = www.qtcn.org
QMAKE_TARGET_DESCRIPTION = Tianchi2 source library for Qt5
QMAKE_TARGET_COPYRIGHT = tianchi2 @ www.qtcn.org
