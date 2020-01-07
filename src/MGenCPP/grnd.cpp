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
/// @created on 2019-12-23 07:27:54 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MGenCPP                                                  //
/// @token d8a307a8-997a-4d8f-9588-ae427053c8a6                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#include "grnd.h"
#include <cassert>

namespace MGen {

GRnd::GRnd() :
    rnd(0), pMut(rnd), pCross(rnd), pReplace(rnd), pBack(rnd), rndSpec(rnd), rndCros(rnd), rndBin(rnd), rndLoc(rnd), rndAll(rnd), rndFAll(rnd)
{
}

void GRnd::init(
    CULONG __sd        ,  // Random seed
    CFLOAT pMut        ,  // The probability of mutation.
    CFLOAT pCross      ,  // The probability of crossing.
    CFLOAT pReplace    ,  // The probability of replace.
    CFLOAT pBack       ,  // The probability of back to the best copy of genotype (from diploid).
    CUINT  sizePop     ,  // The size of population.
    CUINT  sizeSpec    ,  // The size of specimen (size of whole genotype)
    CINT   minInt      ,  // The min value (allele) of each integer gen
    CFLOAT maxInt      ,  // The max value (allele) of each integer gen
    CFLOAT minFlt      ,  // The min value (allele) of each float gen
    CFLOAT maxFlt         // The max value (allele) of each float gen
) noexcept : rnd(__sd), pMut(rnd), pCross(rnd), pReplace(rnd), pBack(rnd), rndSpec(rnd), rndCros(rnd), rndBin(rnd), rndLoc(rnd), rndAll(rnd), rndFAll(rnd)
{
    assert(pMut + pCross + pReplace <= 1 + EPSILON1 );

    this->pMut.setP( pMut );
    this->pCross.setP( pCross );
    this->pReplace.setP( pReplace );
    this->pBack.setP( pBack );
    this->rndSpec.setMinMax( 0 , sizePop-1 );
    this->rndLoc.setMinMax( 0 , sizeSpec-1 );
    this->rndAll.setMinMax( minInt , maxInt );
    this->rndFAll.setMinMax( minFlt , maxFlt );


}

}
