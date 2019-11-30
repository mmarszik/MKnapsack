////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:13:09 CET
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

#include <limits>

typedef long long ltyp;
typedef unsigned long long ultyp;
typedef int ityp;
typedef unsigned int utyp;
typedef double ftyp;

typedef unsigned  __int128 ulltyp;

typedef const long long cltyp;
typedef const unsigned long long cultyp;
typedef const int cityp;
typedef const unsigned int cutyp;
typedef const double cftyp;

constexpr ftyp EPSILON0 = std::numeric_limits<ftyp>::epsilon();

//#define MAIN_PROGRAM
//#define TEST00_PROGRAM
#define TEST01_PROGRAM
//#define TEST02_PROGRAM
//#define TEST03_PROGRAM

//#define USE_RND_SIM_LIN_00
//#define USE_RND_SIM_LIN_01
//#define USE_RND_SIM_LIN_02
//#define USE_RND_SIM_LIN_04
//#define USE_RND_SIM_LIN_05
//#define USE_RND_FIB_0
//#define USE_RND_FIB_0a
//#define USE_RND_FIB_1
//#define USE_RND_FIB_1a
//#define USE_RND_FIB_2
//#define USE_RND_FIB_3
//#define USE_RND_FIB_2a
//#define USE_RND_FIB_3a
//#define USE_RND_SFIB_0
//#define USE_RND_COMP_0
//#define USE_RND_COMP_1
//#define USE_RND_COMP_2
//#define USE_RND_COMP_3
//#define USE_RND_COMP_4
//#define USE_RND_COMP_5
//#define USE_RND_COMP_6
//#define USE_RND_COMP_7
//#define USE_RND_LIN_1
//#define USE_RND_LIN_1a
//#define USE_RND_LIN_2
//#define USE_RND_LIN_2a
//#define USE_RND_LIN_2b
//#define USE_RND_LIN_2c
#define USE_RND_MLIN_0
//#define USE_RND_RANLUX_48
//#define USE_RND_MT19937_64
//#define USE_RND_KNUTH_B
//#define USE_RND_SKIP_LIN_1
//#define USE_RND_SKIP_LIN_2b
//#define USE_RND_XOR2_0
//#define USE_RND_XOR3_0


//#define USING_STD_ARRAY
