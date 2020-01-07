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
/// @created on 2019-12-16 23:02:05 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MRndCPP                                                  //
/// @token c9201229-6275-4475-9cd1-6aab271b1ffe                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include <limits>
#include <cstddef>
#include <MxCPP/mx_array.h>

namespace MGen {

    using TFLOAT  = double;
    using CFLOAT  = const TFLOAT;

    using TINT    = int;
    using TUINT   = unsigned int;
    using TLONG   = long long;
    using TULONG  = unsigned long long;

    using CINT    = const TINT;
    using CUINT   = const TUINT;
    using CLONG   = const TLONG;
    using CULONG  = const TULONG;

    constexpr TFLOAT EPSILON0 = std::numeric_limits<TFLOAT>::epsilon();
    constexpr TFLOAT EPSILON1 = 0.000001;

    template<typename T, size_t SIZE> using TGVec = MxArray<T, SIZE>;

}
