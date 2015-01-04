QT += core
CONFIG += c++11

# =====================================================================================================================
# Common
# ---------------------------------------------------------------------------------------------------------------------
INCLUDEPATH += $$PWD/Common

HEADERS += \
    $$PWD/Common/tcCommon.h \
    $$PWD/Common/tcFunctionalSortFilterProxyModel.h \
    $$PWD/Common/tcInvoke.h \
    $$PWD/Common/tcRecentUse.hpp \
    $$PWD/Common/tcSingleton.hpp \
    $$PWD/Common/tcTuple.hpp \
    $$PWD/Common/tcVariantMapTableModel.h

SOURCES += \
    $$PWD/Common/tcCommon.cpp \
    $$PWD/Common/tcFunctionalSortFilterProxyModel.cpp \
    $$PWD/Common/tcInvoke.cpp \
    $$PWD/Common/tcVariantMapTableModel.cpp


# =====================================================================================================================
# Component
# ---------------------------------------------------------------------------------------------------------------------
INCDIR = $$PWD/Component
INCLUDEPATH += $$INCDIR

# QSint:
# http://www.oschina.net/p/qsint

INCLUDEPATH += $$INCDIR/QSint

HEADERS += \
    $$INCDIR/QSint/actionbox.h \
    $$INCDIR/QSint/actiongroup.h \
    $$INCDIR/QSint/actionlabel.h \
    $$INCDIR/QSint/actionpanel.h \
    $$INCDIR/QSint/actionpanelscheme.h \
    $$INCDIR/QSint/androidpanelscheme.h \
    $$INCDIR/QSint/colorgrid.h \
    $$INCDIR/QSint/macpanelscheme.h \
    $$INCDIR/QSint/taskgroup_p.h \
    $$INCDIR/QSint/taskheader_p.h \
    $$INCDIR/QSint/winvistapanelscheme.h \
    $$INCDIR/QSint/winxppanelscheme.h

SOURCES += \
    $$INCDIR/QSint/actionbox.cpp \
    $$INCDIR/QSint/actiongroup.cpp \
    $$INCDIR/QSint/actionlabel.cpp \
    $$INCDIR/QSint/actionpanel.cpp \
    $$INCDIR/QSint/actionpanelscheme.cpp \
    $$INCDIR/QSint/androidpanelscheme.cpp \
    $$INCDIR/QSint/colorgrid.cpp \
    $$INCDIR/QSint/macpanelscheme.cpp \
    $$INCDIR/QSint/taskgroup_p.cpp \
    $$INCDIR/QSint/taskheader_p.cpp \
    $$INCDIR/QSint/winvistapanelscheme.cpp \
    $$INCDIR/QSint/winxppanelscheme.cpp

RESOURCES += \
    $$INCDIR/QSint/schemes.qrc

# tianchi
INCLUDEPATH += $$INCDIR/tianchi
HEADERS += \
    $$INCDIR/tianchi/tcdateedit.h

SOURCES += \
    $$INCDIR/tianchi/tcdateedit.cpp


# =====================================================================================================================
# Encrypt
# ---------------------------------------------------------------------------------------------------------------------
INCLUDEPATH += $$PWD/Encrypt

HEADERS += \
    $$PWD/Encrypt/tcAES.h

SOURCES += \
    $$PWD/Encrypt/tcAES.cpp

# 第三方源码包 - Crypto++
CRYPTOPP_DIR = $$PWD/Encrypt/cryptopp562
include($$CRYPTOPP_DIR/cryptopp.pri)


# =====================================================================================================================
# Gui
# ---------------------------------------------------------------------------------------------------------------------
QT += gui

INCLUDEPATH += $$PWD/Gui

HEADERS += \
    $$PWD/Gui/tcAutoCursor.h \
    $$PWD/Gui/tcGuiCommon.h

SOURCES += \
    $$PWD/Gui/tcAutoCursor.cpp \
    $$PWD/Gui/tcGuiCommon.cpp


# =====================================================================================================================
# IO
# ---------------------------------------------------------------------------------------------------------------------
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


# =====================================================================================================================
# Network
# ---------------------------------------------------------------------------------------------------------------------
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


# =====================================================================================================================
# OS
# ---------------------------------------------------------------------------------------------------------------------
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


# =====================================================================================================================
# QRCode
# ---------------------------------------------------------------------------------------------------------------------
INCLUDEPATH += $$PWD/QRCode

HEADERS += $$PWD/QRCode/tcQrencode.h
SOURCES += $$PWD/QRCode/tcQrencode.cpp
# 第三方源码包 - QRencode
QRENCODE_DIR = $$PWD/QRCode/qrencode
include($$QRENCODE_DIR/qrencode.pri)

HEADERS += $$PWD/QRCode/tcZxing.h
SOURCES += $$PWD/QRCode/tcZxing.cpp
# 第三方源码包 - ZXing
ZXING_DIR = $$PWD/QRCode/zxing
include($$ZXING_DIR/zxing.pri)

# =====================================================================================================================
# Widgets
# ---------------------------------------------------------------------------------------------------------------------
QT += gui

INCLUDEPATH += $$PWD/Widgets

HEADERS += \
    $$PWD/Widgets/tcPageTurnWidget.h \
    $$PWD/Widgets/tcScreenshot.h \
    $$PWD/Widgets/tcShadowDialog.h \
    $$PWD/Widgets/tcWidget.h \
    $$PWD/Widgets/tcWndSizer.h

SOURCES += \
    $$PWD/Widgets/tcPageTurnWidget.cpp \
    $$PWD/Widgets/tcScreenshot.cpp \
    $$PWD/Widgets/tcShadowDialog.cpp \
    $$PWD/Widgets/tcWidget.cpp \
    $$PWD/Widgets/tcWndSizer.cpp

FORMS += \
    $$PWD/Widgets/tcScreenshot.ui \
    $$PWD/Widgets/tcShadowDialog.ui

RESOURCES += \
    $$PWD/Widgets/tcShadowDialog.qrc


