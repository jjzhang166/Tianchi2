#依赖的Qt模块：core，axcontainer（windows下）
HEADERS  += \
      $$PWD/tcIO.h \
      $$PWD/tcLog.h 
    
SOURCES += \
      $$PWD/tcIO.cpp \
      $$PWD/tcLog.cpp

INCLUDEPATH += $$PWD/

win32:{
  HEADERS  += $$PWD/tcMSExcel.h
  SOURCES += $$PWD/tcMSExcel.cpp
  
  LIBS += -lversion
}
