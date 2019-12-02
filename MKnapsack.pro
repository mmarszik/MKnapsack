CONFIG += c++11
QT += core
QT -= gui

TARGET = MKnapsack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    test00.cpp \
    test01.cpp \
    rnd_sim_lin.cpp \
    rnd_lin.cpp \
    rnd_skip_lin.cpp \
    rnd_fib.cpp \
    rnd_comp_fib.cpp \
    m_array.cpp \
    rnd_xor2.cpp \
    rnd_xor3.cpp \
    rnd_sfibb.cpp \
    rnd_mlin.cpp \
    test02.cpp \
    test03.cpp \
    params.cpp \
    verbout.cpp \
    backpacks.cpp \
    bp_items.cpp \
    rnd_float.cpp \
    rnd_base.cpp \
    test04.cpp \
    dir_exists.cpp \
    create_dir.cpp

HEADERS += \
    rnd.h \
    defs.h \
    rnd_sim_lin.h \
    rnd_lin.h \
    rnd_skip_lin.h \
    rnd_fib.h \
    rnd_buff1.h \
    use_rnd_sim_lin_00.h \
    rnd_buff2.h \
    rnd_buff0.h \
    use_rnd_sim_lin_01.h \
    use_rnd_sim_lin_02.h \
    use_rnd_fib_0.h \
    use_rnd_fib_0a.h \
    use_rnd_fib_1.h \
    use_rnd_fib_1a.h \
    rnd_comp.h \
    use_rnd_comp_0.h \
    use_rnd_comp_1.h \
    use_rnd_comp_2.h \
    use_rnd_comp_3.h \
    use_rnd_lin_1.h \
    use_rnd_lin_1a.h \
    use_rnd_lin_2a.h \
    use_rnd_lin_2.h \
    use_rnd_lin_2b.h \
    use_rnd_lin_2c.h \
    use_rnd_comp_4.h \
    use_rnd_knuth_b.h \
    use_rnd_ministd.h \
    use_rnd_mt19937_64.h \
    use_rnd_ranlux_48.h \
    use_rnd_comp_5.h \
    use_rnd_fib_2.h \
    use_rnd_fib_3.h \
    use_rnd_fib_2a.h \
    use_rnd_fib_3a.h \
    use_rnd_comp_6.h \
    use_rnd_sim_lin_04.h \
    use_rnd_skip_lin_1.h \
    use_rnd_comp_7.h \
    rnd_xor2.h \
    use_rnd_xor2_0.h \
    rnd_xor3.h \
    use_rnd_xor3_0.h \
    use_rnd_skip_lin_2b.h \
    use_rnd_sim_lin_05.h \
    use_rnd_sfib_0.h \
    rnd_sfib.h \
    rnd_mlin.h \
    use_rnd_mlin_0.h \
    m_array.h \
    params.h \
    verbout.h \
    backpacks.h \
    bp_items.h \
    rnd_float.h \
    rnd_base.h \
    dir_exists.h \
    create_dir.h

