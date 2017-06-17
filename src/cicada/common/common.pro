#-------------------------------------------------
#
# Project created by QtCreator 2017-06-17T15:34:18
#
#-------------------------------------------------

QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = common
TEMPLATE = lib

INCLUDEPATH += ./include
LIBS += -L../../cicada/lib -lcurl

HEADERS += \
    ccurl.h

SOURCES += \
    ccurl.cpp

DESTDIR = ../../cicada/bin
