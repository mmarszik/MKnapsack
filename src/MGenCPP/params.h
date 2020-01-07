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
/// @created on 2019-11-30 09:14:22 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MGenCPP                                                  //
/// @token 20568ad3-53a4-4f66-ab34-56a3280081d4                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////


#pragma once

#include "defs.h"
#include <string>

namespace MGen {

class Params {
private:
    TULONG  rndSeed;         // The seed of pseudo random number generator. The value zero indicates will be used std::random_device.

protected:
    bool        help;        // Show help?
    std::string error;

private:
    void setDefaults();

protected:
    void setError(const std::string &error);

public:
    void init(int argc, char *argv[]);
    bool isHelp() const;

    TULONG getSeed() const;
};


}
