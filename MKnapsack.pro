CONFIG += c++14
#QT += core
QT -= gui

TARGET = MKnapsack
CONFIG += console
CONFIG -= app_bundle

CONFIG += object_with_source
CONFIG += object_parallel_to_source

QMAKE_CXXFLAGS += -O3

INCLUDEPATH += vendor/

DEFINES += MX_USING_ARRAY_2
DEFINES += USE_RND_XOR2_0
DEFINES += USE_RND_BUFF_1a
DEFINES += USE_RND_F_BUFF_0
DEFINES += USE_RND_PROB_0

TEMPLATE = app

SOURCES += src/main.cpp \
    vendor/MRndCPP/rnd_mlin.cpp \
    vendor/MxCPP/mx_array.cpp

HEADERS += \
    vendor/MRndCPP/use_rnd_mlin_0.h \
    vendor/MRndCPP/rnd_mlin.h \
    vendor/MRndCPP/prob.h \
    vendor/MRndCPP/buffs.h \
    vendor/MRndCPP/rnd.h \
    vendor/MxCPP/mx_array.h
