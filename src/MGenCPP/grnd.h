////////////////////////////////////////////////////////////////////////
///                                                                   //
/// ALL RIGHT RESERVED.                                               //
///                                                                   //
/// The library for solve any problems through the genetic            //
/// algorithm. It was written in c++ language.                        //
///                                                                   //
/// You may NOT download, share, distribute, compiled, read, modify   //
/// or use all or part of this code in any form without the special   //
/// licence from the author.                                          //
///                                                                   //
////////////////////////////////////////////////////////////////////////
///                                                                   //
/// @created on 2019-12-23 07:27:36 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MGenCPP                                                  //
/// @token 5dce2488-386f-4674-b756-3fe478f3db15                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include "defs.h"

#include <MRndCPP/rnd.h>
#include <MRndCPP/buffs.h>
#include <MRndCPP/prob.h>

namespace MGen {

// The set of default tools for random number generator.
class GRnd {
private:
    TRnd&     rnd;       // The main pseudo random number generator from library MRndCPP.

    TRndProb  pMut;      // The probability of mutation.
    TRndProb  pBack;     // The probability of back to the best copy of genotype (from diploid).
    TRndProb  pBests;    // The probability work on the only best fraction.
//    TRndProb  pCross;    // The probability of crossing.
////  TRndProb  pNew;      // The probability of new random specimen with stagnation equal
//                         // zero. It was commented, because is always true if not mutation and
//                         // not cross and not replace.

//    TRndBuff  rndSpec;   // The random specimen (e.g. for select parent).
//    TRndBuff  rndCros;   // The random cross point.
//    TRndBuff  rndBin;    // The binary random (0 or 1).
//    TRndBuff  rndLoc;    // The random position of gen (locus)
//    TRndBuff  rndAll;    // The random value of gen (allel)
//    TRndFBuff rndFAll;   // The random float value of gen (allel)

public:

    GRnd(
        TRnd& rnd
    );

    void init(
        CFLOAT pMut        ,  // The probability of mutation.
        CFLOAT pBack       ,  // The probability of back to the best copy of genotype (from diploid).
        CFLOAT pBests         // The probability work of the best fraction.
//        CULONG __sd        ,  // Random seed.
//        CFLOAT pCross      ,  // The probability of crossing.
//        CUINT  sizePop     ,  // The size of population.
//        CUINT  sizeSpec    ,  // The size of specimen (size of whole genotype).
//        CINT   minInt      ,  // The min value (allele) of each integer gen.
//        CFLOAT maxInt      ,  // The max value (allele) of each integer gen.
//        CFLOAT minFlt      ,  // The min value (allele) of each float gen.
//        CFLOAT maxFlt         // The max value (allele) of each float gen.
    ) noexcept;

    bool isMutation() {
        return pMut();
    }
    bool isBack() {
        return pBack();
    }
    bool isBests() {
        return pBests();
    }

//    TINT getAllel() {
//        return rndAll();
//    }

//    TFLOAT getFAllel() {
//        return rndFAll();
//    }



};

}
