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
/// @created on 2020-01-09 17:34:22 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MGenCPP                                                  //
/// @token 11dd7559-0f59-41d2-8a7f-06f524e0e23d                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include "defs.h"
#include <string>

namespace MGen {

class DefParams {
public:
    static TULONG rndSeed() noexcept {
        return 0;
    }
    static bool help() noexcept {
        return true;
    }
    static TUINT numberSpecs() noexcept {
        return 256;
    }
    static TFLOAT pMutation() noexcept {
        return 0.9990;
    }
    static TFLOAT pCross() noexcept {
        return 0.0005;
    }
    static TFLOAT pReplace() noexcept {
        return 0.0004;
    }
    static TFLOAT pNew() noexcept {
        return 0.0001;
    }
    static TFLOAT pBack() noexcept {
        return 0.40;
    }
    static TULONG stopCross() noexcept {
        return 0;
    }
    static TFLOAT redunPenal() noexcept {
        return -0.000001;
    }
    static TFLOAT rewAEmpty() noexcept {
        return +0.000001;
    }
    static TFLOAT rewBEmpty() noexcept {
        return +0.000001;
    }
    static TULONG minStagn() noexcept {
        return 100000;
    }
    static TULONG iniStagn() noexcept {
        return 100000;
    }
    static time_t maxTime() noexcept {
        return 0;
    }
    static TULONG maxLoops() noexcept {
        return 0;
    }
    static TUINT haltFreq() noexcept {
        return 0xFFF;
    }
    static TUINT saveFreq() noexcept {
        return 0xFFFF;
    }
    static std::string crossMeth() noexcept {
        return "position";
    }
    static std::string sortItems() noexcept {
        return "true";
    }
    static TFLOAT accEvaluate() noexcept {
        return 0;
    }
    static std::string dataDir() noexcept {
        return "./data/";
    }
    static std::string taskName() noexcept {
        return "";
    }
    static std::string fromStdIn() noexcept {
        return "true";
    }
    static TINT verbosity() noexcept {
        return 1;
    }

};

}
