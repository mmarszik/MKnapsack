////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:45:35 CET
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

#include "defs.h"

#ifdef TEST02_PROGRAM

#include <iostream>
#include <random>
#include <cmath>

int main(int argc, char *argv[]) {
    std::random_device rd;
    ultyp v = 0;
    for( utyp i=0 ; i<4 ; i++ ) {
        v = ( v << 8 ) | ( rd() & 0xFF );
    }
    cultyp cpyV = v;
    std::cout << v << std::endl;
    cultyp BITS = ((1ull<<36)-1);
    cultyp A = 13399171ull;
    cultyp B = 1981891ull;
    ultyp i = 0;
    do {
        v = (v * A + B) & BITS;
        i ++ ;
    } while( v != cpyV );
    std::cout << i << " " << log2( i ) << std::endl;
    std::cout << v << std::endl;
    return 0;
}

#endif
