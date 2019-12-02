////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:17:08 CET
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

template<typename TRnd, utyp SIZE1, utyp SIZE2, utyp SIZE3>
class RndXor3 : public RndBase {
private:
    using TBuff = MArray<ultyp,SIZE1+SIZE2+SIZE3>;
    TBuff x;
    utyp i1,i2,i3;

public:
    RndXor3( cultyp __sd ) {
        seed( __sd );
    }
    void seed( cultyp __sd ) {
        TRnd rnd(__sd);
        for( utyp i=0 ; i<2 ; i++ ) {
            for( utyp j=0 ; j<SIZE1+SIZE2+SIZE3 ; j++ ) {
                x[j] = (x[j]<<32) | (rnd() & 0xFFFFFFFFu);
            }
        }
        i1 = SIZE1 - 1;
        i2 = SIZE1 + SIZE2 - 1;
        i3 = SIZE1 + SIZE2 + SIZE3 - 1;
    }
    result_type operator()() {
        if( ++i1 >= SIZE1                 ) i1 = 0;
        if( ++i2 >= SIZE1 + SIZE2         ) i2 = SIZE1;
        if( ++i3 >= SIZE1 + SIZE2 + SIZE3 ) i3 = SIZE1 + SIZE2;
        return x[i1] + x[i2] + x[i3];
    }
};

