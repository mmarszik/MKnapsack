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

#DEFINES += MX_USING_ARRAY_2
DEFINES += USE_RND_MT19937_64
DEFINES += USE_RND_BUFF_1
DEFINES += USE_RND_F_BUFF_1
DEFINES += USE_RND_PROB_0

TEMPLATE = app

SOURCES += src/main.cpp \
    vendor/MRndCPP/rnd_mlin.cpp \
    vendor/MxCPP/mx_array.cpp \
    src/MGenCPP/genotype.cpp \
    src/MGenCPP/params.cpp \
    vendor/MiscCPP/m_args.cpp \
    src/MGenCPP/grnd.cpp \
    src/MGenCPP/def_params.cpp

HEADERS += \
    vendor/MRndCPP/use_rnd_mlin_0.h \
    vendor/MRndCPP/rnd_mlin.h \
    vendor/MRndCPP/prob.h \
    vendor/MRndCPP/buffs.h \
    vendor/MRndCPP/rnd.h \
    vendor/MxCPP/mx_array.h \
    src/MGenCPP/genotype.h \
    src/MGenCPP/defs.h \
    src/MGenCPP/params.h \
    vendor/MiscCPP/m_args.h \
    src/MGenCPP/grnd.h \
    src/MGenCPP/def_params.h
