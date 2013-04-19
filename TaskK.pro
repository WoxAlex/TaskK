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

SOURCES += Src/*.cpp
HEADERS += Src/*.h
