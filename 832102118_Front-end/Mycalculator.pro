#-------------------------------------------------
#
# Project created by QtCreator 2020-06-15T20:21:46
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mycalculator
TEMPLATE = app


SOURCES += main.cpp\
    Mysql.cpp \
    history.cpp \
        mainwindow.cpp \
    mycal.cpp

HEADERS  += mainwindow.h \
    Mysql.h \
    history.h \
    mycal.h

FORMS    += mainwindow.ui \
    history.ui

CONFIG += C++11
