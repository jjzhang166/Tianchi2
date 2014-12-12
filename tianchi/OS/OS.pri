#依赖的Qt模块：core，gui,widgets
HEADERS  += \
    $$PWD/msime.h \
    $$PWD/tcChinese.h \
    $$PWD/tcOS.h \
    $$PWD/tcAdminAuthorization.h \
    $$PWD/tcRunOnceChecker.h \
    $$PWD/tcSystemInfo.h \
    $$PWD/tcSelfRestarter.h
    
SOURCES += \
    $$PWD/tcChinese.cpp \
    $$PWD/tcOS.cpp \
    $$PWD/tcRunOnceChecker.cpp \
    $$PWD/tcSystemInfo.cpp \
    $$PWD/tcSelfRestarter.cpp 
    
INCLUDEPATH += $$PWD/
    
win32:{
    HEADERS  +=  $$PWD/tcWindows.h
    SOURCES += \
	$$PWD/tcWindows.cpp \
        $$PWD/tcAdminAuthorization_win.cpp \
        $$PWD/tcSystemInfo_win.cpp
        
    win32-g++*:LIBS += -lmpr -lmprapi
}
    
unix:{
    macx:{
        SOURCES += \
            $$PWD/tcAdminAuthorization_mac.cpp \
            $$PWD/tcSystemInfo_mac.cpp
    } else {
        SOURCES += \
            $$PWD/tcAdminAuthorization_x11.cpp \
            $$PWD/tcSystemInfo_x11.cpp

        LIBS += -lutil
    }
}
