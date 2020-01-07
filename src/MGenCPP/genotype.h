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
/// @created on 2019-12-23 10:34:23 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MGenCPP                                                  //
/// @token b38a9824-8b2b-43f4-93da-b49561f43d37                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include "defs.h"

namespace MGen {

//MM: Default genotype is a combination of integer and float numbers.
template<class Params, CUINT SIZE_INT, CUINT SIZE_FLT, typename TINT, typename TFLT>
class Genotype {
private:
    TGVec<TINT, SIZE_INT> igens;  //MM: The integer numbers.
    TGVec<TFLT, SIZE_FLT> fgens;  //MM: The float numbers.

public:
    Genotype() noexcept {
    }

    void init(
        Params &p
    ) noexcept {
        for( TUINT i=0 ; i<SIZE_INT ; i++ ) {
            igens[i] = p.getAllel();
        }
        for( TUINT i=0 ; i<SIZE_FLT ; i++ ) {
            fgens[i] = p.getFAllel();
        }
    }

    virtual void evaluate(Params &p) const = 0;

};

}

