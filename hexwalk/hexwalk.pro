QT += charts
CONFIG += static
RC_ICONS = images/hexwalk.ico
#Only for Windows:
QMAKE_LFLAGS += -no-pie -lstdc++ -Bstatic -static-libgcc -static-libstdc++ -static
#Only for Mac:
#ICON = images/hexwalk.icns
###############
VERSION = "1.6.0"
QMAKE_TARGET_COPYRIGHT = "gcarmix"
QMAKE_TARGET_PRODUCT = "HexWalk"
HEADERS = \
    ../src/bytepattern.h \
    ../src/colortag.h \
    ../src/tagparser.hpp \
    advancedsearchdialog.h \
    binanalysisdialog.h \
    converterdialog.h \
    diffdialog.h \
    edittagdialog.h \
    entropychart.h \
    entropydialog.h \
    hashdialog.h \
    hexwalkmain.h \
    optionsdialog.h \
    ../src/qhexedit.h \
    ../src/chunks.h \
    ../src/commands.h \
    resultType.h \
    searchdialog.h \
    stringsdialog.h \
    tagsdialog.h \
    worditemdelegate.h


SOURCES = \
    ../src/bytepattern.cpp \
    ../src/colortag.cpp \
    ../src/tagparser.cpp \
    advancedsearchdialog.cpp \
    binanalysisdialog.cpp \
    converterdialog.cpp \
    diffdialog.cpp \
    edittagdialog.cpp \
    entropychart.cpp \
    entropydialog.cpp \
    hashdialog.cpp \
    hexwalkmain.cpp \
    main.cpp \
    optionsdialog.cpp \
    ../src/qhexedit.cpp \
    ../src/chunks.cpp \
    ../src/commands.cpp \
    searchdialog.cpp \
    stringsdialog.cpp \
    tagsdialog.cpp \
    worditemdelegate.cpp

RESOURCES = \
    hexwalk.qrc

FORMS += \
    advancedsearchdialog.ui \
    binanalysisdialog.ui \
    converterdialog.ui \
    diffdialog.ui \
    edittagdialog.ui \
    entropydialog.ui \
    hashdialog.ui \
    hexwalkmain.ui \
    optionsdialog.ui \
    searchdialog.ui \
    stringsdialog.ui \
    tagsdialog.ui

DEFINES += QHEXEDIT_EXPORTS \
    APP_VERSION=\\\"$$VERSION\\\"
