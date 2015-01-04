TC_COMPONENT = ../tianchi/Component

QT += widgets designer concurrent

TARGET = tianchi4qtc
DESTDIR = ../bin
TEMPLATE = lib

# QSint:
# http://www.oschina.net/p/qsint

INCLUDEPATH += QSint $$TC_COMPONENT/QSint

HEADERS += \
    QSint/actionboxplugin.h \
    QSint/actiongroupplugin.h \
    QSint/actionlabelplugin.h \
    QSint/actionpanelplugin.h \
    QSint/colorgridplugin.h \
    $$TC_COMPONENT/QSint/actionbox.h \
    $$TC_COMPONENT/QSint/actiongroup.h \
    $$TC_COMPONENT/QSint/actionlabel.h \
    $$TC_COMPONENT/QSint/actionpanel.h \
    $$TC_COMPONENT/QSint/actionpanelscheme.h \
    $$TC_COMPONENT/QSint/androidpanelscheme.h \
    $$TC_COMPONENT/QSint/colorgrid.h \
    $$TC_COMPONENT/QSint/macpanelscheme.h \
    $$TC_COMPONENT/QSint/taskgroup_p.h \
    $$TC_COMPONENT/QSint/taskheader_p.h \
    $$TC_COMPONENT/QSint/winvistapanelscheme.h \
    $$TC_COMPONENT/QSint/winxppanelscheme.h

SOURCES += \
    QSint/actionboxplugin.cpp \
    QSint/actiongroupplugin.cpp \
    QSint/actionlabelplugin.cpp \
    QSint/actionpanelplugin.cpp \
    QSint/colorgridplugin.cpp \
    $$TC_COMPONENT/QSint/actionbox.cpp \
    $$TC_COMPONENT/QSint/actiongroup.cpp \
    $$TC_COMPONENT/QSint/actionlabel.cpp \
    $$TC_COMPONENT/QSint/actionpanel.cpp \
    $$TC_COMPONENT/QSint/actionpanelscheme.cpp \
    $$TC_COMPONENT/QSint/androidpanelscheme.cpp \
    $$TC_COMPONENT/QSint/colorgrid.cpp \
    $$TC_COMPONENT/QSint/macpanelscheme.cpp \
    $$TC_COMPONENT/QSint/taskgroup_p.cpp \
    $$TC_COMPONENT/QSint/taskheader_p.cpp \
    $$TC_COMPONENT/QSint/winvistapanelscheme.cpp \
    $$TC_COMPONENT/QSint/winxppanelscheme.cpp

RESOURCES += \
    $$TC_COMPONENT/QSint/schemes.qrc \
    QSint/QSint.qrc

# Tianchi
INCLUDEPATH += tianchi $$TC_COMPONENT/tianchi

HEADERS += \
    tianchi/tcdateeditplugin.h \
    $$TC_COMPONENT/tianchi/tcdateedit.h

SOURCES += \
    tianchi/tcdateeditplugin.cpp \
    $$TC_COMPONENT/tianchi/tcdateedit.cpp

RESOURCES += \
    tianchi/tianchi.qrc

# plugins
HEADERS += \
    tcdesignercomponent.h

SOURCES += \
    tcdesignercomponent.cpp

RC_FILE += tianchi4qtc.rc
