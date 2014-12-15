CONFIG += c++11

#Common
INCLUDEPATH += $$PWD/Common

HEADERS += \
    $$PWD/Common/tcCommon.h \
    $$PWD/Common/tcFunctionalSortFilterProxyModel.h \
    $$PWD/Common/tcInvoke.h \
    $$PWD/Common/tcRecentUse.hpp \
    $$PWD/Common/tcSingleton.hpp \
    $$PWD/Common/tcTuple.hpp \
    $$PWD/Common/tcVariantMapTableModel.h \
    $$PWD/Widgets/tcWndSizer.h

SOURCES += \
    $$PWD/Common/tcCommon.cpp \
    $$PWD/Common/tcFunctionalSortFilterProxyModel.cpp \
    $$PWD/Common/tcInvoke.cpp \
    $$PWD/Common/tcVariantMapTableModel.cpp \
    $$PWD/Widgets/tcWndSizer.cpp

#Component
INCLUDEPATH += $$PWD/Component

HEADERS += \
    $$PWD/Component/tcdateedit.h

SOURCES += \
    $$PWD/Component/tcdateedit.cpp

#Gui
INCLUDEPATH += $$PWD/Gui

HEADERS += \
    $$PWD/Gui/tcAutoCursor.h

SOURCES += \
    $$PWD/Gui/tcAutoCursor.cpp

#IO
INCLUDEPATH += $$PWD/IO

HEADERS += \
    $$PWD/IO/tcExcelReader.h \
    $$PWD/IO/tcIO.h \
    $$PWD/IO/tcLog.h

SOURCES += \
    $$PWD/IO/tcExcelReader.cpp \
    $$PWD/IO/tcIO.cpp \
    $$PWD/IO/tcLog.cpp

win32:{

    QT += axcontainer

    HEADERS += \
        $$PWD/IO/tcExcel.h

    SOURCES += \
        $$PWD/IO/tcExcel.cpp

}

#Network

QT += network

INCLUDEPATH += $$PWD/Network

HEADERS += \
    $$PWD/Network/tcDownloader.h \
    $$PWD/Network/tcFtp.h \
    $$PWD/Network/tcHttp.h \
    $$PWD/Network/tcUdp.h

SOURCES += \
    $$PWD/Network/tcDownloader.cpp \
    $$PWD/Network/tcFtp.cpp \
    $$PWD/Network/tcHttp.cpp \
    $$PWD/Network/tcUdp.cpp

#OS
INCLUDEPATH += $$PWD/OS

HEADERS += \
    $$PWD/OS/tcAdminAuthorization.h \
    $$PWD/OS/tcChinese.h \
    $$PWD/OS/tcOS.h \
    $$PWD/OS/tcRunOnceChecker.h \
    $$PWD/OS/tcSelfRestarter.h \
    $$PWD/OS/tcSystemInfo.h \
    $$PWD/OS/tcWindows.h

SOURCES += \
    $$PWD/OS/tcChinese.cpp \
    $$PWD/OS/tcOS.cpp \
    $$PWD/OS/tcRunOnceChecker.cpp \
    $$PWD/OS/tcSelfRestarter.cpp \
    $$PWD/OS/tcSystemInfo.cpp \
    $$PWD/OS/tcWindows.cpp

win32:{

    SOURCES += \
        $$PWD/OS/tcAdminAuthorization_win.cpp \
        $$PWD/OS/tcSystemInfo_win.cpp

    LIBS += -lversion

    win32-g++*:
    {
        LIBS += -lmpr -lmprapi
    }
}
unix:{
    macx:{
        SOURCES += \
            $$PWD/OS/tcAdminAuthorization_mac.cpp \
            $$PWD/OS/tcSystemInfo_mac.cpp

        LIBS += -framework Carbon -framework Security

    }else{
        SOURCES += \
            $$PWD/OS/tcAdminAuthorization_x11.cpp \
            $$PWD/OS/tcSystemInfo_x11.cpp

        LIBS += -lutil
    }
}

#Widgets
QT += gui

INCLUDEPATH += $$PWD/Widgets

HEADERS += \
    $$PWD/Widgets/tcWndCaption.h \
    $$PWD/Widgets/tcWndSizer.h

SOURCES += \
    $$PWD/Widgets/tcWndCaption.cpp
    $$PWD/Widgets/tcWndSizer.cpp \

RESOURCES += \
    $$PWD/Widgets/tcWndCaption.qrc

