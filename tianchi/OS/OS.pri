#依赖的Qt模块：core，gui,widgets

INCLUDEPATH += $$PWD/

HEADERS += \
    $$PWD/tcAdminAuthorization.h \
    $$PWD/tcChinese.h \
    $$PWD/tcOS.h \
    $$PWD/tcRunOnceChecker.h \
    $$PWD/tcSelfRestarter.h \
    $$PWD/tcSystemInfo.h \
    $$PWD/tcWindows.h

SOURCES += \
    $$PWD/tcChinese.cpp \
    $$PWD/tcOS.cpp \
    $$PWD/tcRunOnceChecker.cpp \
    $$PWD/tcSelfRestarter.cpp \
    $$PWD/tcSystemInfo.cpp \
    $$PWD/tcWindows.cpp

win32:{

    SOURCES += \
        $$PWD/tcAdminAuthorization_win.cpp \
        $$PWD/tcSystemInfo_win.cpp

    LIBS += -lversion

    win32-g++*:
    {
        LIBS += -lmpr -lmprapi
    }
}
unix:{
    macx:{
        SOURCES += \
            $$PWD/tcAdminAuthorization_mac.cpp \
            $$PWD/tcSystemInfo_mac.cpp

        LIBS += -framework Carbon -framework Security

    }else{
        SOURCES += \
            $$PWD/tcAdminAuthorization_x11.cpp \
            $$PWD/tcSystemInfo_x11.cpp

        LIBS += -lutil
    }
}

