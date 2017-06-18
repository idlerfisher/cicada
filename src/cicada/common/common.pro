#-------------------------------------------------
#
# Project created by QtCreator 2017-06-17T15:34:18
#
#-------------------------------------------------

QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = common
TEMPLATE = lib

INCLUDEPATH += ./include
LIBS += -L../../cicada/lib -lcurl

HEADERS += \
    ccurl.h \
    cexcelreader.h

SOURCES += \
    ccurl.cpp \
    cexcelreader.cpp

DESTDIR = ../../cicada/bin
