////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:14:33 CET
/// @author MMarszik (Mariusz Marszalkowski mmarszik@gmail.com)
/// Brief:
/// Description:
///
////////////////////////////////////////////////////////////////////////////////////////////////
///
/// It is file containing source code of genetic algorithm to solve
/// multi-knapsack problem. It turned out that the genetic algorithm
/// very well solves the multi-backpack problem.
///
/// The file is share on the open source licence, but unlike GPL, MIT, BSD
/// APACHE, L-GPL, etc,  it is NOT standard and NOT liberary licence of the
/// open source. By downloading and reading this file, you conclude a contract
/// with me. Namely, if you understand that my source code can be improved
/// (for example: speed up, better algorithms, better parametrs,  fixed
/// bugs, etc), you need to present me everything in very detail. You
/// can only download, read and compile this project only on the your
/// personal computer. You can run the executable file and solve
/// education or example problem, but only on the your own personal
/// computer. You can see what the genetic alghoritm work in any
/// practical multi-knapsack problem. However you can not use result
/// this project in the  business applications. You also can NOT modifi,
/// reshare, redistribuate binary or text version this or other file from
/// whole project.  You can not use whole file or fews lines from the file
/// in your or others projects.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "defs.h"

#if defined( USE_RND_SIM_LIN_00 )
    #include "use_rnd_sim_lin_00.h"
#elif  defined( USE_RND_SIM_LIN_01 )
    #include "use_rnd_sim_lin_01.h"
#elif  defined( USE_RND_SIM_LIN_02 )
    #include "use_rnd_sim_lin_02.h"
#elif  defined( USE_RND_SIM_LIN_04 )
    #include "use_rnd_sim_lin_04.h"
#elif  defined( USE_RND_SIM_LIN_05 )
    #include "use_rnd_sim_lin_05.h"
#elif  defined( USE_RND_FIB_0 )
    #include "use_rnd_fib_0.h"
#elif  defined( USE_RND_FIB_0a )
    #include "use_rnd_fib_0a.h"
#elif  defined( USE_RND_FIB_1 )
    #include "use_rnd_fib_1.h"
#elif  defined( USE_RND_FIB_1a )
    #include "use_rnd_fib_1a.h"
#elif  defined( USE_RND_FIB_2 )
    #include "use_rnd_fib_2.h"
#elif  defined( USE_RND_FIB_3 )
    #include "use_rnd_fib_3.h"
#elif  defined( USE_RND_FIB_2a )
    #include "use_rnd_fib_2a.h"
#elif  defined( USE_RND_FIB_3a )
    #include "use_rnd_fib_3a.h"
#elif  defined( USE_RND_SFIB_0 )
    #include "use_rnd_sfib_0.h"
#elif  defined( USE_RND_COMP_0 )
    #include "use_rnd_comp_0.h"
#elif  defined( USE_RND_COMP_1 )
    #include "use_rnd_comp_1.h"
#elif  defined( USE_RND_COMP_2 )
    #include "use_rnd_comp_2.h"
#elif  defined( USE_RND_COMP_3 )
    #include "use_rnd_comp_3.h"
#elif  defined( USE_RND_COMP_4 )
    #include "use_rnd_comp_4.h"
#elif  defined( USE_RND_COMP_5 )
    #include "use_rnd_comp_5.h"
#elif  defined( USE_RND_COMP_6 )
    #include "use_rnd_comp_6.h"
#elif  defined( USE_RND_COMP_7 )
    #include "use_rnd_comp_7.h"
#elif  defined( USE_RND_LIN_1 )
    #include "use_rnd_lin_1.h"
#elif  defined( USE_RND_LIN_1a )
    #include "use_rnd_lin_1a.h"
#elif  defined( USE_RND_LIN_2 )
    #include "use_rnd_lin_2.h"
#elif  defined( USE_RND_LIN_2a )
    #include "use_rnd_lin_2a.h"
#elif  defined( USE_RND_LIN_2b )
    #include "use_rnd_lin_2b.h"
#elif  defined( USE_RND_LIN_2c )
    #include "use_rnd_lin_2c.h"
#elif  defined( USE_RND_MLIN_0 )
    #include "use_rnd_mlin_0.h"
#elif  defined( USE_RND_RANLUX_48 )
    #include "use_rnd_ranlux_48.h"
#elif  defined( USE_RND_MT19937_64 )
    #include "use_rnd_mt19937_64.h"
#elif  defined( USE_RND_KNUTH_B )
    #include "use_rnd_knuth_b.h"
#elif  defined( USE_RND_SKIP_LIN_1 )
    #include "use_rnd_skip_lin_1.h"
#elif  defined( USE_RND_SKIP_LIN_2b )
    #include "use_rnd_skip_lin_2b.h"
#elif  defined( USE_RND_XOR2_0 )
    #include "use_rnd_xor2_0.h"
#elif  defined( USE_RND_XOR3_0 )
    #include "use_rnd_xor3_0.h"
#endif

#include "rnd_buff0.h"

