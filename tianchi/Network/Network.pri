#依赖的Qt模块：core，network
HEADERS  += \
    $$PWD/tcDownloader.h \
    $$PWD/tcUdp.h \
    $$PWD/tcFtp.h \
    $$PWD/tcHttp.h \
    
SOURCES += \
    $$PWD/tcDownloader.cpp \
    $$PWD/tcSingleinstance.cpp \
    $$PWD/tcUdp.cpp \
    $$PWD/tcFtp.cpp \
    $$PWD/tcHttp.cpp

INCLUDEPATH += $$PWD/
