QT += testlib
QT -= gui

TARGET = tst_date
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_date.cpp \
	../../WelcomeToTampere/date.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"
HEADERS += \
	../../WelcomeToTampere/date.hh
INCLUDEPATH += \
            ../../WelcomeToTampere/
