#依赖的Qt模块：core，axcontainer（windows下）

INCLUDEPATH += $$PWD/

HEADERS  += \
      $$PWD/tcIO.h \
      $$PWD/tcLog.h 
    
SOURCES += \
      $$PWD/tcIO.cpp \
      $$PWD/tcLog.cpp

win32:{

    QT += axcontainer

    HEADERS += \
        $$PWD/tcExcel.h \
        $$PWD/tcExcelReader.h

    SOURCES += \
        $$PWD/tcExcel.cpp \
        $$PWD/tcExcelReader.cpp

    LIBS += -lversion
}
