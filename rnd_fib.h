////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:15:31 CET
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

template<typename T, utyp SIZE, utyp R, T M1, T M2, T A, T MOD=0, utyp INIT=4, utyp SHIFT=0>
class RndFib : public RndBase {
private:
    using TBuff = MArray<T,SIZE>;
    TBuff buff;
    utyp  i1, i2;
public:
    RndFib(){}
    RndFib(const T __sd) {
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
        if( MOD == 0 ) {
            return ( buff[i1] = buff[i1] * M1 + buff[i2] * M2 + A ) >> SHIFT;
        } else {
            return ( buff[i1] = (buff[i1] * M1 + buff[i2] * M2 + A) % MOD ) >> SHIFT;
        }
    }
};

using RndFib0  =  RndFib< ultyp,  55u,  24u,                   1ull,                   1ull,                   0ull,  0ull, 4u, 5u >;
using RndFib0a =  RndFib< ultyp,  55u,  24u,  467215392725233709ull,  611270373676516397ull,  869843207682474811ull,  0ull, 4u, 5u >;
using RndFib1  =  RndFib< ultyp,  71u,  65u,                   1ull,                   1ull,                   0ull,  0ull, 4u, 5u >;
using RndFib1a =  RndFib< ultyp,  71u,  65u,  115863979857357701ull,  629390526482068033ull,  657629269220325019ull,  0ull, 4u, 5u >;
using RndFib2  =  RndFib< ultyp, 521u, 353u,                   1ull,                   1ull,                   0ull,  0ull, 4u, 5u >;
using RndFib2a =  RndFib< ultyp, 521u, 353u, 4112492776315134143ull, 2856502054400409791ull, 4455332773284362119ull,  0ull, 4u, 5u >;
using RndFib3  =  RndFib< ultyp, 607u, 334u,                   1ull,                   1ull,                   0ull,  0ull, 4u, 5u >;
using RndFib3a =  RndFib< ultyp, 607u, 334u, 1438097939015544337ull, 2095838886465443359ull, 1126833020129680393ull,  0ull, 4u, 5u >;

