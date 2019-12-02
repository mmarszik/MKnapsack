////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:15:58 CET
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

//MM: Multilinear psuedo random numbers generator.
class RndMLin : public RndBase {
private:
    const static MArray<ultyp, 16> A;
    const static MArray<ultyp, 16> B;
    MArray<ulltyp,16> V;
    ultyp v;
    utyp x;

public:
    RndMLin(){
    }
    RndMLin(cultyp __sd) {
        seed(__sd);
    }
    void seed(cultyp __sd) {
        const static MArray<ultyp, 32> X = {0x2A8A8E7B69275E7Bull, 0xC60C57AD9B23A6C5ull, 0xD9005720730353ECull, 0xB355D0AC65D932B4ull, 0x93419492C098DCA3ull, 0x67C980BE4B5CBE6Dull, 0xC02690505B01ED78ull, 0x3037D55D993E674Bull, 0xE0443DB9A597DD17ull, 0x17B7E6E04A43D417ull, 0x57322B091789D992ull, 0x97456758E6AE397Eull, 0xE65C5A81589EED86ull, 0x2A1C2E6192C178EDull, 0xC23115A5B5D01A87ull, 0x6B91EDE5889A648Aull, 0xC91EA73561B8CD39ull, 0x4DB893E0CC8248E3ull, 0x98D38A4D5B9BE969ull, 0x2D077C6CB4A823BDull, 0xE712A94440067BB2ull, 0xC30B7025675AE401ull, 0xA23315A68A5B4621ull, 0x22D6B2B1D9714D17ull, 0xD8E26531867CB0A1ull, 0xA76D46B7E90A4086ull, 0xDA71B684588E8C96ull, 0x817E2AD3025EC218ull, 0xB0136A731A8A1B28ull, 0x95E9CC38A11349C2ull, 0x373A30554835A0CCull, 0xBCB37B54049DCE31ull};
        v = __sd;
        x = 0;
        for( utyp i=0,j=0 ; i<16 ; i++ ) {
            V[i] = __sd ^ X[j++];
            V[i] <<= 64;
            V[i] |= __sd ^ X[j++];
        }
    }
    result_type operator()() {
        v = v * 543657589ull + 4253133281ull;
        cutyp i = v >> 60;
        return ( V[i] = V[i] * A[i] + B[i] ) >> 93;
    }
};


