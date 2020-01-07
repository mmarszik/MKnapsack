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
/// @created on 2019-11-30 09:43:41 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MGenCPP                                                  //
/// @token d144734d-ba0f-47fa-a693-3b0ce021ffe4                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#include "params.h"

#include <MiscCPP/m_args.h>

#include <cstring>
#include <cmath>
#include <sstream>
#include <random>
#include <algorithm>
#include <fstream>

#include <MiscCPP/m_dir.h>
#include <MiscCPP/m_args.h>
#include <MiscCPP/m_limits.h>


namespace MGen {

namespace Def {
    static TULONG rndSeed() noexcept {
        return 0;
    }
    static bool help() noexcept {
        return true;
    }
}

void Params::setError(const std::string &error) {
    this->help  = true;
    this->error = error;
}

void Params::setDefaults() noexcept(false) {
    help        = Def::help();
    rndSeed     = Def::rndSeed();
}

void Params::init(
    int argc,
    char *argv[]
) noexcept(false)  {
    std::vector<int> recognizedArg( argc , 0 );
    setDefaults();

    //help
    {
        const char *arg = extractArg( argc, argv, "help", recognizedArg );
        if( arg != NULL ) {
            setError("");
            return;
        }
    }

    //rndSeed
    {
        const char *arg = extractArg( argc, argv, "rndSeed", recognizedArg );
        if( arg ) {
            std::istringstream ss(arg);
            ss >> rndSeed;
            if( ss.fail() ) {
                setError("Invalid command line arg: rndSeed");
                return;
            }
        }
        if( rndSeed == 0 ) {
            CUINT BITS = 8;
            std::random_device rd;
            for( TUINT i=0 ; i<MLimits<decltype(rndSeed)>::digits() ; i+=BITS ) {
                seed = ( seed << BITS ) | ( rd() & ((1u<<BITS)-1) );
            }
        }

    }


    help = false;

}

bool MGen::Params::isHelp() const {
    return help;
}

TULONG Params::getSeed() const {
    return rndSeed;
}

}
