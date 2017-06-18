#-------------------------------------------------
#
# Project created by QtCreator 2017-06-17T15:34:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = cicada
TEMPLATE = app

INCLUDEPATH += ../common \
               ../common/include

LIBS += -L../../cicada/lib \
        -L../../cicada/bin \
        -lcommon

SOURCES += main.cpp \
    cicadamainwindow.cpp

HEADERS  += \
    cicadamainwindow.h

FORMS    += cicadamainwindow.ui

DESTDIR = ../../cicada/bin

RESOURCES += \
    images.qrc

RC_FILE = images/cicada.rc
