#依赖的Qt模块：core，network

QT += network

INCLUDEPATH += $$PWD/

HEADERS  += \
    $$PWD/tcDownloader.h \
    $$PWD/tcUdp.h \
    $$PWD/tcFtp.h \
    $$PWD/tcHttp.h \
    
SOURCES += \
    $$PWD/tcDownloader.cpp \
    $$PWD/tcUdp.cpp \
    $$PWD/tcFtp.cpp \
    $$PWD/tcHttp.cpp

