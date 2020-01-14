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
#include "def_params.h"

#include <MiscCPP/m_args.h>

#include <cstring>
#include <cmath>
#include <sstream>
#include <random>
#include <algorithm>
#include <fstream>
#include <iostream>

#include <MiscCPP/m_dir.h>
#include <MiscCPP/m_args.h>
#include <MiscCPP/m_limits.h>


namespace MGen {

void Params::setError(const std::string &error) {
    this->help  = true;
    this->error = error;
}

void Params::setDefaults() noexcept(false) {
    help        = DefParams::help();
    rndSeed     = DefParams::rndSeed();
    numberSpecs = DefParams::numberSpecs();
    pMutation   = DefParams::pMutation();
    pCross      = DefParams::pCross();
    pReplace    = DefParams::pReplace();
    pNew        = DefParams::pNew();
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
                rndSeed = ( rndSeed << BITS ) | ( rd() & ((1u<<BITS)-1) );
            }
        }
    }

    //numberSpecs
    {
        const char *arg = extractArg( argc, argv, "numberSpecs" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> numberSpecs;
            if( ss.fail() || numberSpecs < 1 ) {
                setError("Invalid command line arg: numberSpecs");
                return;
            }
        }
    }

    //maxLoops
    {
        const char* arg = extractArg( argc, argv, "maxLoops" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> maxLoops;
#pragma GCC diagnostic ignored "-Wtype-limits"
            if( ss.fail() || maxLoops < 0 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
                setError("Invalid command line arg: maxLoops");
                return;
            }
        }
    }

    //Probability of replace
    {
        const char* arg = extractArg( argc, argv, "pReplace" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pReplace;
            if( ss.fail() || pReplace < 0 || pReplace > 1 ) {
                setError("Invalid command line arg: pReplace");
                return;
            }
        }
    }

    //Probability of new
    {
        const char* arg = extractArg( argc, argv, "pNew" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pNew;
            if( ss.fail() || pNew < 0 || pNew > 1 ) {
                setError("Invalid command line arg: pNew");
                return;
            }
        }
    }


    //The probability of genetic operators:
    {
        //Flags' genetic operators (mutation, corssing, replacing, new) which specified in the command line
        TUINT fOperators = 0;

        //Probability of mutation
        {
            const char* arg = extractArg( argc, argv, "pMutation" , recognizedArg);
            if( arg ) {
                std::istringstream ss(arg);
                ss >> pMutation;
                if( ss.fail() || pMutation < 0 || pMutation > 1 ) {
                    setError("Invalid command line arg: pMutation");
                    return;
                }
                fOperators |= 1; // The probability of the mutations operator was given directly in the command line.
            }
        }

        //Probability of crossing
        {
            const char* arg = extractArg( argc, argv, "pCross" , recognizedArg);
            if( arg ) {
                std::istringstream ss(arg);
                ss >> pCross;
                if( ss.fail() || pCross < 0 || pCross > 1 ) {
                    setError("Invalid command line arg: pCross");
                    return;
                }
                fOperators |= 2; // The probability of the cross operator was given directly in the command line.
            }
        }

        if( fOperators == 1 ) {
            pCross = 1.0 - pMutation;
        } else if( fOperators == 2 ) {
            pMutation = 1.0 - pCross;
        }

        {
            CFLOAT sum = pMutation + pCross;
            if( fabs( 1.0 - sum ) > EPSILON1 ) {
                std::string msg = "Invalid command line arg: pMutatnion + pCross = " + std::to_string(sum) + " <> 1.0 ";
                setError( msg );
                return;
            }
        }

    }

    // Probability back to the diploidy.
    {
        const char* arg = extractArg( argc, argv, "pBack" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pBack;
            if( ss.fail() || pBack < 0 || pBack > 1 ) {
                throw std::invalid_argument("Invalid command line arg: pBack");
            }
        }
    }


    help = false;
}


void Params::showHelp() const {
    std::cout << " --rndSeed=[uint] <1, 2^64-1> default: " << DefParams::rndSeed() << std::endl;
    std::cout << "    The seed of pseudo random number generator." << std::endl;
    std::cout << " The value zero indicates will be used std::random_device." << std::endl;
    std::cout << std::endl;

    std::cout << " --numberSpecs=[uint] <1, MAX_MEMORY> default: " << DefParams::numberSpecs() << std::endl;
    std::cout << "    Default number of specimens." << std::endl;
    std::cout << std::endl;

    std::cout << " --pMutatnion=[float] <0, 1> default: " << DefParams::pMutation() << std::endl;
    std::cout << "    Probability of mutation." << std::endl;
    std::cout << std::endl;

    std::cout << " --pCross=[float] <0, 1> default: " << DefParams::pCross() << std::endl;
    std::cout << "    Probability of crosing specimens. The stagnation of the new specimen" << std::endl;
    std::cout << " created by crossing is equal average stagnation his of two parents." << std::endl;
    std::cout << std::endl;

    std::cout << " --pReplace=[float] <0, 1> default: " << DefParams::pReplace() << std::endl;
    std::cout << "    Probability of replace. The stagnation of the new specimen" << std::endl;
    std::cout << " created by replace is equal stagnation of the source specimen." << std::endl;
    std::cout << std::endl;

    std::cout << " --pNew=[float] <0, 1> default: " << DefParams::pNew() << std::endl;
    std::cout << "    Probability of create new, random specimen. The stagnation of " << std::endl;
    std::cout << " the new specimen created by new operator always is equal zero." << std::endl;
    std::cout << std::endl;

    std::cout << " --pBack=[float] <0, 1> default: " << DefParams::pNew() << std::endl;
    std::cout << "    Probability back the specimen to the last best solve from his copy." << std::endl;
    std::cout << std::endl;

    std::cout << " --stopCross=[uint] <0, 2^64-1> default: " << DefParams::stopCross() << std::endl;
    std::cout << "    When loops reached value x the crossing operation  will" << std::endl;
    std::cout << " be stop. Value zero indicate the crossing operation  continues" << std::endl;
    std::cout << " whole time execute program." << std::endl;
    std::cout << std::endl;

    std::cout << " --redunPenal=[float] <-INF,_INF> default: " << DefParams::redunPenal() << std::endl;
    std::cout << "    The penalty for redundant items in the knapsacks." << std::endl;
    std::cout << " If redunPenal > 0 it will be rewarding for redundant items, not penal." << std::endl;
    std::cout << std::endl;

    std::cout << " --rewAEmpty=[float] <-INF,+INF> default: " << DefParams::rewAEmpty() << std::endl;
    std::cout << "    The reward [A] for the empty place in the knapsack by formula A*empty^B. " << std::endl;
    std::cout << " When A<0 this value is penalty and not is reward. The empty place in " << std::endl;
    std::cout << " backpack is harmful, but when B>1 the genetic algorithm put more items " << std::endl;
    std::cout << " to the one or few knapsacks - maybe even one or several backpacks will " << std::endl;
    std::cout << " be empty. When 0<B<1 the genetic algorithm try put the items evenly to " << std::endl;
    std::cout << " all knapsacks. " << std::endl;
    std::cout << std::endl;

    std::cout << " --rewBEmpty=[float] <0,+INF> default: " << DefParams::rewBEmpty() << std::endl;
    std::cout << "    The reward [B] for the empty place in the knapsack by formula A*empty^B." << std::endl;
    std::cout << std::endl;

    std::cout << " --minStagn=[uint] <0,2^64-1> default: " << DefParams::minStagn() << std::endl;
    std::cout << "    Each specimen have to have the stagnation parameter more than minStagn to apply" << std::endl;
    std::cout << " operators: new, replace nad crossing. Otherwise  will be apply only mutation operator." << std::endl;
    std::cout << std::endl;

    std::cout << " --iniStagn=[uint] <0,2^64-1> default: " << DefParams::iniStagn() << std::endl;
    std::cout << "    The initial stagnation of the all specimens when program is begin." << std::endl;
    std::cout << std::endl;

    std::cout << " --maxTime=[uint] <0,2^32-1> default: " << DefParams::maxTime() << std::endl;
    std::cout << "    The max time for whole run program. When is equal zero, the program is running" << std::endl;
    std::cout << " until the stop condition is true.." << std::endl;
    std::cout << std::endl;

    std::cout << " --maxLoops=[uint] <0,2^64-1> default: " << DefParams::maxLoops() << std::endl;
    std::cout << "    The max number of the computations loops. When is equal zero, the program" << std::endl;
    std::cout << " is running to the end time or without end - when you have to send ctrl+c signal" << std::endl;
    std::cout << " in order to ending program." << std::endl;
    std::cout << std::endl;

    std::cout << " --haltFreq=[uint=2^N-1] <0,22> default: " << DefParams::haltFreq() << std::endl;
    std::cout << "    The frequency of the probiting of the stop condition." << std::endl;
    std::cout << std::endl;

    std::cout << " --saveFreq=[uint=2^N-1] <0,22> default: " << DefParams::saveFreq() << std::endl;
    std::cout << "    The frequency of save file." << std::endl;
    std::cout << std::endl;

    std::cout << " --crossMeth=[string] {position|gens} default: " << DefParams::crossMeth() << std::endl;
    std::cout << "    The method of the crossing specimens." << std::endl;
    std::cout << std::endl;

    std::cout << " --sortItems=[string] true|false default: " << DefParams::sortItems() << std::endl;
    std::cout << "    Sort the items?" << std::endl;
    std::cout << std::endl;

    std::cout << " --accEvaluate=[float] <0,INF> default: " << DefParams::accEvaluate() << std::endl;
    std::cout << "    The acceptable evaluate. The zero value" << std::endl;
    std::cout << " indicates run to stop condition." << std::endl;
    std::cout << std::endl;

    std::cout << " --dataDir=[string] default: " << DefParams::dataDir() << std::endl;
    std::cout << "    The directory with files data." << std::endl;
    std::cout << std::endl;

    std::cout << " --taskName=[string] default: " << DefParams::taskName() << std::endl;
    std::cout << "    The task name will be used to name the files." << std::endl;
    std::cout << std::endl;

    std::cout << " --fromStdIn=[string] {true|false} default: " << DefParams::fromStdIn() << std::endl;
    std::cout << "    The path to file containing backpacks and items." << std::endl;
    std::cout << " If empty it read from stdin." << std::endl;
    std::cout << std::endl;

    std::cout << " --verbosity=[uint] <0,+INF> default: " << DefParams::verbosity() << std::endl;
    std::cout << "    The verbosity." << std::endl;
    std::cout << "    verbosity >= 1 - show random seed." << std::endl;
    std::cout << "    verbosity >= 5 - show input information." << std::endl;
    std::cout << std::endl;

    std::cout << " --help " << std::endl;
    std::cout << "    Show this help" << std::endl;
    std::cout << std::endl;
}


}
