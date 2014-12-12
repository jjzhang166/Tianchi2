#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T10:41:54
#
#-------------------------------------------------
QT += core gui network
QT += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = Tianchi2
TEMPLATE = app

TIANCHIDIR = ../tianchi

INCLUDEPATH += \
    $$TIANCHIDIR/Common \
    $$TIANCHIDIR/Component \
    $$TIANCHIDIR/Gui \
    $$TIANCHIDIR/IO \
    $$TIANCHIDIR/Network \
    $$TIANCHIDIR/OS \
    $$TIANCHIDIR/Widgets

HEADERS  += mainwindow.h \
    $$TIANCHIDIR/Common/tcFunctionalSortFilterProxyModel.h \
    $$TIANCHIDIR/Common/tcRecentUse.hpp \
    $$TIANCHIDIR/Common/tcVariantMapTableModel.h \
    $$TIANCHIDIR/Common/tcCommon.h \
    $$TIANCHIDIR/Common/tcSingleton.hpp \
    $$TIANCHIDIR/Common/tcTuple.hpp \
    $$TIANCHIDIR/Component/tcdateedit.h \
    $$TIANCHIDIR/IO/tcIO.h \
    $$TIANCHIDIR/IO/tcLog.h \
    $$TIANCHIDIR/Network/tcDownloader.h \
    $$TIANCHIDIR/Network/tcSingleinstance.h \
    $$TIANCHIDIR/Network/tcUdp.h \
    $$TIANCHIDIR/OS/msime.h \
    $$TIANCHIDIR/OS/tcChinese.h \
    $$TIANCHIDIR/OS/tcOS.h \
    $$TIANCHIDIR/Widgets/tcWindowSizer.h \
    $$TIANCHIDIR/Widgets/tcWndCaption.h \
    $$TIANCHIDIR/Network/tcFtp.h \
    $$TIANCHIDIR/Network/tcHttp.h \
    $$TIANCHIDIR/OS/tcAdminAuthorization.h \
    $$TIANCHIDIR/OS/tcRunOnceChecker.h \
    $$TIANCHIDIR/OS/tcSystemInfo.h \
    $$TIANCHIDIR/OS/tcSelfRestarter.h \
    $$TIANCHIDIR/OS/tcWindows.h

SOURCES += main.cpp mainwindow.cpp \
    $$TIANCHIDIR/Common/tcFunctionalSortFilterProxyModel.cpp \
    $$TIANCHIDIR/Common/tcVariantMapTableModel.cpp \
    $$TIANCHIDIR/Common/tcCommon.cpp \
    $$TIANCHIDIR/Component/tcdateedit.cpp \
    $$TIANCHIDIR/IO/tcIO.cpp \
    $$TIANCHIDIR/IO/tcLog.cpp \
    $$TIANCHIDIR/Network/tcDownloader.cpp \
    $$TIANCHIDIR/Network/tcSingleinstance.cpp \
    $$TIANCHIDIR/Network/tcUdp.cpp \
    $$TIANCHIDIR/OS/tcChinese.cpp \
    $$TIANCHIDIR/OS/tcOS.cpp \
    $$TIANCHIDIR/Widgets/tcWindowSizer.cpp \
    $$TIANCHIDIR/Widgets/tcWndCaption.cpp \
    $$TIANCHIDIR/Network/tcFtp.cpp \
    $$TIANCHIDIR/Network/tcHttp.cpp \
    $$TIANCHIDIR/OS/tcRunOnceChecker.cpp \
    $$TIANCHIDIR/OS/tcSystemInfo.cpp \
    $$TIANCHIDIR/OS/tcSelfRestarter.cpp \
    $$TIANCHIDIR/OS/tcWindows.cpp

FORMS += mainwindow.ui

win32:{
    HEADERS += \
        $$TIANCHIDIR/IO/tcMSExcel.h

    SOURCES += \
        $$TIANCHIDIR/IO/tcMSExcel.cpp \
        $$TIANCHIDIR/OS/tcAdminAuthorization_win.cpp \
        $$TIANCHIDIR/OS/tcSystemInfo_win.cpp

    LIBS += -lversion

}
win32-g++*:
{
    LIBS += -lmpr -lmprapi
}
unix:{
    macx:{
        SOURCES += \
            OS/tcAdminAuthorization_mac.cpp \
            OS/tcSystemInfo_mac.cpp

    }else{
        SOURCES += \
            OS/tcAdminAuthorization_x11.cpp \
            OS/tcSystemInfo_x11.cpp
    }
}

#win32-msvc*:LIBS += -ladvapi32 -lole32

RESOURCES += \
    $$TIANCHIDIR/resource.qrc
