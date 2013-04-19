#-------------------------------------------------
#
# Project created by QtCreator 2013-04-16T23:18:19
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11
QT       += core

QT       -= gui

TARGET = TaskK
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

#INCLUDEPATH = /usr/include/c++/4.8.0/

TARGET =   TaskK
DESTDIR = Bin
OBJECTS_DIR = Bin/.obj
MOC_DIR = Bin/.moc
RCC_DIR = Bin/.rcc
UI_DIR = Bin/.ui

SOURCES += Src/main.cpp \
    Src/icell.cpp \
    Src/binarydata.cpp \
    Src/stringcell.cpp \
    Src/intcell.cpp \
    Src/errorcell.cpp \
    Src/formulacell.cpp \
    Src/emptycell.cpp \
    Src/icellstorage.cpp \
    Src/simplecellstorage.cpp \
    Src/tablereader.cpp \
    Src/tablewriter.cpp \
    Src/icomputer.cpp \
    Src/simplecomputer.cpp \
    Src/itablereader.cpp

HEADERS += \
    Src/icell.h \
    Src/binarydata.h \
    Src/stringcell.h \
    Src/intcell.h \
    Src/errorcell.h \
    Src/formulacell.h \
    Src/emptycell.h \
    Src/icellstorage.h \
    Src/simplecellstorage.h \
    Src/tablereader.h \
    Src/tablewriter.h \
    Src/icomputer.h \
    Src/simplecomputer.h \
    Src/itablereader.h
