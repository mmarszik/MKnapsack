CONFIG += c++14
#QT += core
QT -= gui

TARGET = MKnapsack
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += vendor

DEFINES += MX_USING_ARRAY_3
DEFINES += USE_RND_MLIN_0
DEFINES += USE_RND_BUFF0


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
    vendor/MGenCPP/m_gen.cpp \
    vendor/MGenCPP/m_gen_spec.cpp
HEADERS += \
    src/specimen.h \
    src/backpacks.h \
    src/def_verb.h \
    src/defs.h \
    src/params.h \
    src/bp_items.h \
    vendor/MiscCPP/m_dir.h \
    vendor/MiscCPP/m_args.h \
    vendor/MGenCPP/m_gen.h \
    vendor/MGenCPP/m_gen_spec.h \
    vendor/MGenCPP/m_gen_defs.h
