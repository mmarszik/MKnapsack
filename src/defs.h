////////////////////////////////////////////////////////////////////////
///                                                                   //
/// The genetic Algorithm to solve Problem Multi-Knapsack.            //
///                                                                   //
/// It is file containing source code of genetic algorithm to solve   //
/// multi-knapsack problem. It turned out that the genetic algorithm  //
/// very well solves the multi-backpack problem.                      //
///                                                                   //
/// The file is share on the open source licence, but unlike GPL,     //
/// MIT, BSD, APACHE, L-GPL, etc, it is NOT standard and NOT          //
/// liberary licence of the open source. By downloading and reading   //
/// this file, you conclude a contract with me. Namely, if you        //
/// understand that my source code can be improved (for example:      //
/// speed up, better algorithms, better implementatnions, better      //
/// parametrs, fixed bugs, etc), you need to present me everything    //
/// in very detail. You can only download, read and compile this      //
/// project only on the your personal computer. You can run the       //
/// executable file and solve any problem, but only on the your own   //
/// personal computer. You can see what the genetic alghorithm work   //
/// in any practical multi-knapsack problem. However you can not use  //
/// results of this program in the business applications. You also    //
/// can NOT modifi, reshare, redistribuate binary or text version     //
/// this or other file from whole project. You can not use whole      //
/// file or fews lines from the file in your or others projects. If   //
/// you need the other or commercial licence please send to me email. //
///                                                                   //
////////////////////////////////////////////////////////////////////////
///                                                                   //
/// @created on 2019-11-30 09:13:09 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 179e4656-b829-43b3-a520-86b950a1c804                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include <MRndCPP/rnd.h>

#define MK_DEBUG

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

typedef uint8_t TGEN;

#include <limits>
constexpr ftyp EPSILON0 = std::numeric_limits<ftyp>::epsilon();
constexpr ftyp EPSILON1 = 0.0000001;


#if defined( __linux__ )
    constexpr char PATHSEP = '/';
#elif defined(_WIN32)
    constexpr char PATHSEP = '\\';
#elif defined(_WIN64)
    constexpr char PATHSEP = '\\';
#endif


#define MAIN_PROGRAM
//#define TEST00_PROGRAM
//#define TEST01_PROGRAM
//#define TEST02_PROGRAM
//#define TEST03_PROGRAM
//#define TEST04_PROGRAM
//#define SANDBOX01_PROGRAM
//#define SANDBOX02_PROGRAM

//#define USING_STD_ARRAY
