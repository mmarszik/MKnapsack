////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:14:58 CET
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
//MM: It is pseudo random number generator with cyclic buffer. It work fast
//MM: but numbers are worse(!!!) than with class TRnd. Next pseudo random
//MM: numbers are given from buffer, each pseudo random number is given REPEAT
//MM: times. So the big value of REPEAT and small value of SIZE implicite the
//MM  worse pseudo random numbers, but accelerate the generate process their.
template<utyp SIZE, utyp REPEAT, utyp MIN, utyp max>
class RndBuff1 {
private:
    using TBuff = MArray<TRnd::result_type,SIZE>;
    cutyp max;    // Max range.
    TRnd  &rnd;   // Pseudo random number generator.
    TBuff buf;    // N-Cyclic buffer to number generator.
    utyp  next;   // Index to the next given value.
    utyp  repeat; // Number repeat to reset buffer.

private:
    void reset() {
        for( utyp i=0 ; i<SIZE ; i++ ) {
            buf[ i ] = rnd() % (max-MIN+1) + MIN;
        }
        repeat = REPEAT;
    }

public:
    RndBuff1( TRnd &rnd, cutyp max ) : rnd(rnd), max(max) {
        next   = SIZE-1;
        repeat = 1;
    }
    TRnd::result_type operator()() {
        if( ++next == SIZE ) {
            next = 0;
            if( --repeat == 0 ) {
                reset();
            }
        }
        return buf[ next ];
    }
};

template<utyp MIN>
using TRndBuff = RndBuff1<1u<<20, 1u<<4, MIN>;

