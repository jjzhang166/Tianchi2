#依赖的Qt模块：core, gui, widgets

INCLUDEPATH += $$PWD/

HEADERS += \
    $$PWD/tcPageTurnWidget.h \
    $$PWD/tcScreenshot.h \
    $$PWD/tcShadowDialog.h \
    $$PWD/tcWndCaption.h \
    $$PWD/tcWndSizer.h \


SOURCES += \
    $$PWD/tcPageTurnWidget.cpp \
    $$PWD/tcScreenshot.cpp \
    $$PWD/tcShadowDialog.cpp \
    $$PWD/tcWndCaption.cpp \
    $$PWD/tcWndSizer.cpp

FORMS += \
    $$PWD/tcScreenshot.ui \
    $$PWD/tcShadowDialog.ui

RESOURCES += \
    $$PWD/tcWndCaption.qrc
