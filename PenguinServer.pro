#-------------------------------------------------
#
# Project created by QtCreator 2013-11-03T12:07:52
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = PenguinServer
CONFIG   += console
CONFIG   -= app_bundle

LIBS  += -lsqlite3 -lpolarssl

TEMPLATE = app


SOURCES += main.cpp \
    serverthread.cpp \
    clientsmanager.cpp \
    serverlistener.cpp \
    connectedclient.cpp \
    sharedlist.cpp \
    ../messageenvelop.cpp \
    database.cpp

HEADERS += \
    serverthread.h \
    clientsmanager.h \
    serverlistener.h \
    connectedclient.h \
    sharedlist.h \
    ../messageenvelop.h \
    database.h

