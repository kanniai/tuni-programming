QT += testlib
QT += gui
QT += widgets

TARGET = tst_statisticsunittest


CONFIG   += console
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES +=  tst_statisticsunittest.cpp \
    ../Game/statistics.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../Game/statistics.hh \
    ../Course/CourseLib/interfaces/istatistics.hh

INCLUDEPATH += \
    $$PWD/../Game/ \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Game/ \
    $$PWD/../Course/CourseLib
