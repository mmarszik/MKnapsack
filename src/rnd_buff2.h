////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:15:09 CET
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

#include "rnd.h"
#include "m_array.h"

//MM: Attention: It is opposite of the good random number generator ;-)
//MM: It is other pseudo random number generator with cyclic buffer. It
//MM: work fast, but numbers are worse(!!!) than with class TRnd.
//MM: Attention, SIZE and REPEAT will be used as binary offset,
//MM: SIZE = 1 << SIZE  and  REPAT = 1 << REPAT.
template<utyp SIZE, utyp REPEAT, utyp MIN, utyp max>
class RndBuff2 {
private:
    using TBuff = MArray< TRnd::result_type , 1<<SIZE >;
    cutyp max;    // Max range.
    TRnd  &rnd;   // Pseudo random number generator.
    TBuff buf;    // N-Cyclic buffer to number generator.
    utyp  next;   // Index to the next given value.

public:

    RndBuff2( TRnd &rnd, cutyp max ) : rnd(rnd), max(max) {
        next = 0;
        while( next<SIZE ) {
            buf[ next++ ] = rnd() % (max-MIN+1) + MIN;
        }
    }

    TRnd::result_type operator()() {
        if( next >= SIZE ) {
            next = 0;
        }
        if( ! (next & ((1<<REPEAT)-1)) ) {
            buf[ rnd() & ((1<<SIZE)-1) ] = rnd() % (max - MIN + 1) + MIN;
        }
        return buf[ next ++ ];
    }

};

template<utyp MIN>using TRndBuff = RndBuff2<20u, 4u, MIN>;

