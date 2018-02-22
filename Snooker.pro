#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T10:28:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snooker
TEMPLATE = app


SOURCES += main.cpp\
        logowanie.cpp \
    administrator.cpp \
    osoba.cpp

HEADERS  += logowanie.h \
    administrator.h \
    osoba.h \
    ../../Downloads/rapidxml/rapidxml_iterators.hpp \
    ../../Downloads/rapidxml/rapidxml_print.hpp \
    ../../Downloads/rapidxml/rapidxml_utils.hpp

FORMS    += logowanie.ui

DISTFILES += \
    administratorzy.xml \
    mecze1.xml \
    turnieje.xml \
    zawodnicy.xml
