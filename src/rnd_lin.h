////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:15:43 CET
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

#include "defs.h"
#include "rnd_sim_lin.h"
#include "rnd_base.h"

template<typename T, T A, T B, T M=0, utyp BITS=32, utyp SHIFT=0>
class RndLin : public RndBase {
private:
    RndSimLin<T,A,B,M,SHIFT> rnd;
public:
    RndLin() {
    }
    RndLin(const T __sd) : rnd(__sd) {
    }
    void seed(const T __sd) {
        rnd.seed(__sd);
    }
    result_type operator()() {
        utyp r=0;
        for( utyp i=0 ; i<std::numeric_limits<decltype(r)>::digits ; i+=BITS ) {
#pragma GCC diagnostic ignored "-Wshift-count-overflow"
            r <<= BITS;
#pragma GCC diagnostic error "-Wshift-count-overflow"
            r |= rnd() & ((1ull<<BITS)-1);
        }
        return r;
    }
};

using RndLin1  = RndLin<ultyp, 1645253ull, 1327634909599ull,             0ull, 32u, 32u>;
using RndLin1a = RndLin<ultyp, 1645253ull, 1327634909599ull,             0ull, 16u,  0u>;
using RndLin2  = RndLin<ultyp, 1645253ull, 1327634909599ull, 7129848157699ull, 32u,  0u>;
using RndLin2a = RndLin<ultyp, 1645253ull, 1327634909599ull, 7129848157699ull, 16u,  0u>;
using RndLin2b = RndLin<ultyp, 1645253ull, 1327634909599ull, 7129848157699ull, 11u, 12u>;
using RndLin2c = RndLin<ultyp, 1645253ull, 1327634909599ull, 7129848157699ull,  8u,  0u>;

