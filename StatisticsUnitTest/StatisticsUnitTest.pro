QT += testlib
QT += gui
QT += widgets

TARGET = tst_statisticsunittest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES +=  tst_statisticsunittest.cpp \
    ../Game/statistics.cpp

HEADERS += \
    ../Game/statistics.hh

INCLUDEPATH += \
    $$PWD/../Game/ \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Game/ \
    $$PWD/../Course/CourseLib
