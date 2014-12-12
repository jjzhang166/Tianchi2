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

INCLUDEPATH += ./Common ./Component ./Gui ./IO ./Network ./OS ./Widgets

HEADERS  += mainwindow.h \
    Common/TcFunctionalSortFilterProxyModel.h \
    Common/TcRecentUse.hpp \
    Common/TcVariantMapTableModel.h \
    Common/tcCommon.h \
    Common/tcSingleton.hpp \
    Common/tcTuple.hpp \
    Component/tcdateedit.h \
    IO/tcIO.h \
    IO/tcLog.h \
    Network/tcDownloader.h \
    Network/tcSingleinstance.h \
    Network/tcUdp.h \
    OS/msime.h \
    OS/tcChinese.h \
    OS/tcOS.h \
    Widgets/tcWindowSizer.h \
    Widgets/tcWndCaption.h \
    Network/tcFtp.h \
    Network/tcHttp.h \
    OS/tcAdminAuthorization.h \
    OS/tcRunOnceChecker.h \
    OS/tcSystemInfo.h \
    OS/tcSelfRestarter.h \
    OS/tcWindows.h

SOURCES += main.cpp mainwindow.cpp \
    Common/TcFunctionalSortFilterProxyModel.cpp \
    Common/TcVariantMapTableModel.cpp \
    Common/tcCommon.cpp \
    Component/tcdateedit.cpp \
    IO/tcIO.cpp \
    IO/tcLog.cpp \
    Network/tcDownloader.cpp \
    Network/tcSingleinstance.cpp \
    Network/tcUdp.cpp \
    OS/tcChinese.cpp \
    OS/tcOS.cpp \
    Widgets/tcWindowSizer.cpp \
    Widgets/tcWndCaption.cpp \
    Network/tcFtp.cpp \
    Network/tcHttp.cpp \
    OS/tcRunOnceChecker.cpp \
    OS/tcSystemInfo.cpp \
    OS/tcSelfRestarter.cpp \
    OS/tcWindows.cpp

FORMS += mainwindow.ui

win32:{
    HEADERS += \
        IO/tcMSExcel.h

    SOURCES += \
        IO/tcMSExcel.cpp \
        OS/tcAdminAuthorization_win.cpp \
        OS/tcSystemInfo_win.cpp

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
    resource.qrc
