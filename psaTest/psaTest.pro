QT += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = psaTest
TEMPLATE = app

include(../psa-headers-sources.pri)

PSA_PATH = ../psa
INCLUDEPATH += $$PSA_PATH # TO DO
DEPENDPATH += $$PSA_PATH #TO DO

SOURCES += \
main.cpp \
    testevent.cpp

HEADERS += \
    testevent.h
