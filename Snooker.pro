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
    osoba.cpp \
    zalogowany.cpp \
    kontener.cpp \
    dodanieadminapowodzenie.cpp \
    partia.cpp \
    zawodnik.cpp \
    mecz.cpp

HEADERS  += logowanie.h \
    administrator.h \
    osoba.h \
    ../../Downloads/rapidxml/rapidxml_iterators.hpp \
    ../../Downloads/rapidxml/rapidxml_print.hpp \
    ../../Downloads/rapidxml/rapidxml_utils.hpp \
    zalogowany.h \
    kontener.h \
    dodanieadminapowodzenie.h \
    partia.h \
    zawodnik.h \
    mecz.h

FORMS    += logowanie.ui \
    zalogowany.ui \
    dodanieadminapowodzenie.ui

DISTFILES += \
    administratorzy.xml \
    mecze1.xml \
    turnieje.xml \
    zawodnicy.xml
