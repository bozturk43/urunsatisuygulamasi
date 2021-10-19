#-------------------------------------------------
#
# Project created by QtCreator 2017-07-29T13:00:46
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RanaCini
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        biskuvisatis.cpp \
    sircasatis.cpp \
    urunekleme.cpp \
    urunguncelleme.cpp \
    sirliurunekleme.cpp \
    sirliurunguncelleme.cpp \
    odemeislemleri.cpp \
    urunturuekleme.cpp \
    musteriislemleri.cpp

HEADERS  += biskuvisatis.h \
    sircasatis.h \
    urunekleme.h \
    urunguncelleme.h \
    sirliurunekleme.h \
    sirliurunguncelleme.h \
    odemeislemleri.h \
    urunturuekleme.h \
    musteriislemleri.h

FORMS    += biskuvisatis.ui \
    sircasatis.ui \
    urunekleme.ui \
    urunguncelleme.ui \
    sirliurunekleme.ui \
    sirliurunguncelleme.ui \
    odemeislemleri.ui \
    urunturuekleme.ui \
    musteriislemleri.ui

RESOURCES += \
    res.qrc
QMAKE_CXXFLAGS += -std=gnu++14

include($$PWD/QtRptProject/QtRPT/QtRPT.pri)
