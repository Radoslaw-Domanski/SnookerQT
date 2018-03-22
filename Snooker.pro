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
    partia.cpp \
    zawodnik.cpp \
    mecz.cpp \
    konteneradministrator.cpp \
    turniej.cpp \
    kontenerzawodnik.cpp \
    kontenerturniej.cpp

HEADERS  += logowanie.h \
    administrator.h \
    osoba.h \
    zalogowany.h \
    partia.h \
    zawodnik.h \
    mecz.h \
    konteneradministrator.h \
    turniej.h \
    kontenerzawodnik.h \
    kontenerturniej.h

FORMS    += logowanie.ui \
    zalogowany.ui

DISTFILES += \
    administratorzy.xml \
    mecze1.xml \
    turnieje.xml \
    zawodnicy.xml
