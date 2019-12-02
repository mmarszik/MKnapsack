////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:15:22 CET
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
#include "m_array.h"
#include "rnd_base.h"

//MM: The composition of two pseudo random number generators with lagged.
template<class TRnd1, class TRnd2, utyp SIZE>
class RndComp : public RndBase {
private:
    using TBuff = MArray< utyp , 1u<<SIZE >;
    TBuff buff;
    TRnd1 rnd1;
    TRnd2 rnd2;
public:
    RndComp( cultyp __sd ) {
        seed( __sd );
    }
    void seed( cultyp __sd ) {
        rnd1.seed( __sd ^ 0x4B3B2985634D008 );
        rnd2.seed( __sd ^ 0x73CD8A180586D6A );
        for( utyp i=0 ; i < (1u<<SIZE) ; i++ ) {
            buff[i] = rnd1();
        }
    }
    result_type operator()() {
        cutyp r = rnd2() & ((1u<<SIZE)-1);
        cultyp v = buff[r];
        buff[r] = rnd1();
        return v;
    }
//    utyp operator()() {
//        buff[ rnd2() & ((1u<<SIZE)-1) ] = rnd1();
//        return buff[ rnd2() & ((1u<<SIZE)-1) ];
//    }
//    utyp operator()() {
//        return rnd1() ^ rnd2();
//    }

};

