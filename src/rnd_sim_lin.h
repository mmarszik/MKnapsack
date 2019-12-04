////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:16:28 CET
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
#include "rnd_base.h"

//MM: Simplest linear psuedo random numbers generator.
template<typename T, T A, T B, T M=0, utyp SHIFT=0>
class RndSimLin : public RndBase {
private:
    T v;
public:
    RndSimLin(){
    }
    RndSimLin(const T __sd) {
        seed(__sd);
    }
    void seed(const T __sd) {
        v = __sd;
        for( utyp i=0 ; i<10 ; i++ ) {
            (*this)();
        }
    }
    result_type operator()() {
        if( M == 0 ) {
            if( SHIFT == 0 ) {
                return v = v * A + B;
            }
            return (v = v * A + B) >> SHIFT;
        }
        if( SHIFT == 0 ) {
            return v = (v * A + B) % M;
        }
        return (v = (v * A + B) % M) >> SHIFT;
    }
};

using RndSimLin00 = RndSimLin<  ultyp, 785269ull, 1259391056969ull,              0ull,  32u >;
using RndSimLin01 = RndSimLin<  ultyp, 785269ull, 1259391056969ull, 21641981640689ull,   0u >;
using RndSimLin02 = RndSimLin<  ultyp, 991811ull, 2842826673569ull,              0ull,  32u >;
using RndSimLin03 = RndSimLin<  ultyp, 991811ull, 2842826673569ull, 12639539681863ull,   0u >;
using RndSimLin04 = RndSimLin<  ultyp,1645253ull, 1327634909599ull,  7129848157699ull,   0u >;

using RndSimLin05 = RndSimLin< ulltyp, 48744881ull, 147915133152863ull, 0ull, 95u >;

