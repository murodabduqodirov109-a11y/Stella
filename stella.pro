QT += core gui widgets texttospeech

CONFIG += c++17
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    stellawindow.cpp \
    stellacore.cpp \
    particleeffect.cpp

HEADERS += \
    stellawindow.h \
    stellacore.h \
    particleeffect.h

TARGET = Stella
