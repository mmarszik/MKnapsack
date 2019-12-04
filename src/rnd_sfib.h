////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:16:08 CET
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

#include "rnd_lin.h"
#include "m_array.h"
#include "rnd_base.h"

template<typename T, utyp SIZE, utyp R, utyp ROT=1, utyp SHIFT=0, utyp INIT=4>
class RndSFib : public RndBase {
private:
    using TBuff = MArray<T,SIZE>;
    TBuff buff;
    utyp  i1, i2;

private:
    static T rot( const T v ) {
        return ( v << ROT ) | ( v >> ( std::numeric_limits<T>::digits - ROT ) );
    }

public:
    RndSFib(){}
    RndSFib(const T __sd) {
        seed(__sd);
    }
    void seed(const T __sd) {
        RndLin2b rnd( __sd );
        for( utyp i=0 ; i<4 ; i++ ) {
            for( utyp j=0 ; j<SIZE ; j++ ) {
                buff[j] <<= 16;
                buff[j] ^= rnd();
            }
        }
        i1 = SIZE - 1;
        i2 = SIZE - 1 - R;
        for( utyp i=0 ; i<SIZE*INIT ; i++ ) {
            (*this)();
        }
    }
    result_type operator()() {
        if( ++i1 >= SIZE ) i1 = 0;
        if( ++i2 >= SIZE ) i2 = 0;
        return ( buff[i1] += rot(buff[i2]) ) >> SHIFT;
    }
};

using RndSFib0 =  RndSFib< ultyp, 9689u, 4187u, 1u, 0u>;

