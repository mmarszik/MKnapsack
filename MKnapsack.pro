CONFIG += c++14
#QT += core
QT -= gui

TARGET = MKnapsack
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += vendor

DEFINES += MX_USING_ARRAY_3
DEFINES += USE_RND_MLIN_0
DEFINES += USE_RND_BUFF_0
DEFINES += USE_RND_F_BUFF_0
DEFINES += USE_RND_PROB_0

TEMPLATE = app

SOURCES += src/main.cpp \
    src/params.cpp \
    src/specimen.cpp \
    src/bp_items.cpp \
    src/backpacks.cpp \
    src/test04.cpp \
    src/test03.cpp \
    src/test02.cpp \
    vendor/MRndCPP/rnd_mlin.cpp \
    vendor/MiscCPP/m_dir.cpp \
    vendor/MiscCPP/m_args.cpp \
    vendor/MiscCPP/m_next_line.cpp \
    vendor/MiscCPP/m_verb_out.cpp \
    vendor/MiscCPP/m_trim.cpp \
    src/sandbox01.cpp \
    src/sandbox02.cpp \
    vendor/MGenCPP/params.cpp \
    vendor/MGenCPP/specimen.cpp \
    vendor/MGenCPP/genetic.cpp \
    vendor/MGenCPP/rnd.cpp \
    vendor/MGenCPP/genotype.cpp
HEADERS += \
    src/specimen.h \
    src/backpacks.h \
    src/def_verb.h \
    src/defs.h \
    src/params.h \
    src/bp_items.h \
    vendor/MiscCPP/m_dir.h \
    vendor/MiscCPP/m_args.h \
    vendor/MGenCPP/defs.h \
    vendor/MGenCPP/params.h \
    vendor/MGenCPP/specimen.h \
    vendor/MGenCPP/genetic.h \
    vendor/MGenCPP/rnd.h \
    vendor/MGenCPP/genotype.h \
    vendor/MRndCPP/rnd.h \
    vendor/MRndCPP/buff.h \
    vendor/MRndCPP/prob.h
