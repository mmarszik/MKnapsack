////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:43:41 CET
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

#include <cstring>
#include <cmath>
#include <sstream>
#include <typeinfo>
#include <random>
#include <algorithm>
#include <fstream>

#include "params.h"
#include "dir_exists.h"
#include "create_dir.h"

static ultyp defRndSeed() noexcept {
    return 0;
}
static utyp defNumberSpecs() noexcept {
    return 256;
}
static ftyp defPMutatnion() noexcept {
    return 0.9990;
}
static ftyp defPCross() noexcept {
    return 0.0005;
}
static ftyp defPReplace() noexcept {
    return 0.0004;
}
static ftyp defPNew() noexcept {
    return 0.0001;
}
static ftyp defPBack() noexcept {
    return 0.40;
}
static ultyp defStopCross() noexcept {
    return 0;
}
static ftyp defRedunPenal() noexcept {
    return -0.000001;
}
static ftyp defRewAEmpty() noexcept {
    return +0.000001;
}
static ftyp defRewBEmpty() noexcept {
    return +0.000001;
}
static ultyp defMinStagn() noexcept {
    return 100000;
}
static ultyp defIniStagn() noexcept {
    return 100000;
}
static time_t defMaxTime() noexcept {
    return 0;
}
static ultyp defMaxLoops() noexcept {
    return 0;
}
static utyp defHaltFreq() noexcept {
    return 0xFFF;
}
static utyp defSaveFreq() noexcept {
    return 0xFFFF;
}
static std::string defCrossMeth() noexcept {
    return "position";
}
static std::string defSortItems() noexcept {
    return "true";
}
static ftyp defAccEvaluate() noexcept {
    return 0;
}
static std::string defDataDir() noexcept {
    return "./data/";
}
static std::string defTaskName() noexcept {
    return "";
}
static std::string defFromStdIn() noexcept {
    return "true";
}
static ityp defVerbosity() noexcept {
    return 1;
}


static char* extractArg( int argc , char *argv[] , const char *arg , std::vector<utyp> &recognized ) noexcept {
    for( int i=1 ; i<argc ; i++ ) {
        int off = 0;
        if( argv[i][0] == '-' )
            off++;
        if( off && argv[i][1] == '-' )
            off++;
        if( strncasecmp( argv[i]+off , arg , strlen(arg) ) == 0 ) {
            off += strlen(arg);
            recognized[i] ++ ;
            return argv[i]+off;
        }
    }
    return NULL;
}

void Params::setDefaults() noexcept(false) {
    rndSeed     = defRndSeed();
    numberSpecs = defNumberSpecs();
    pMutatnion  = defPMutatnion();
    pCross      = defPCross();
    pReplace    = defPReplace();
    pNew        = defPNew();
    if( fabs( 1.0 - pMutatnion + pReplace + pNew + pCross ) > EPSILON0 ) {
        throw std::invalid_argument("Invalid sum of the probabiliteis pMutatnion + pReplace + pNew ");
    }
    pBack     = defPBack();
    stopCross = defStopCross();
    redunPenal= defRedunPenal();
    rewAEmpty = defRewAEmpty();
    rewBEmpty = defRewBEmpty();
    minStagn  = defMinStagn();
    iniStagn  = defIniStagn();
    maxTime   = defMaxTime();
    maxLoops  = defMaxLoops();
    haltFreq  = defHaltFreq();
    saveFreq  = defSaveFreq();
    if( defCrossMeth() == "position" ) {
        crossMeth = ECM_POSITION;
    } else if(defCrossMeth() == "gens") {
        crossMeth = ECM_GENS;
    } else {
        throw std::invalid_argument("Invalid defCrossMeth");
    }
    if( defSortItems() == "true" ) {
        sortItems = true;
    } else if( defSortItems() == "false" ) {
        sortItems = false;
    } else {
        throw std::invalid_argument("Invalid defSortItems");
    }
    accEvaluate = defAccEvaluate();
    dataDir     = defDataDir();
    taskName    = defTaskName();
    if( defFromStdIn() == "true" ) {
        fromStdIn = true;
    } else if( defFromStdIn() == "false" ) {
        fromStdIn = false;
    } else {
        throw std::invalid_argument("Invalid defFromStdIn");
    }
    verbosity = defVerbosity();
    help      = false;
}

std::string Params::getDataPath() const noexcept {
    std::string dir = getDataDir();
    if( dir[dir.size()-1] != PATHSEP ) {
        dir += PATHSEP;
    }
    dir += "data_";
    dir += getTaskName();
}


Params::Params(int argc, char *argv[]) noexcept(false) {
    char *arg;
    std::vector<utyp> recognizedArg( argc , 0 );

    if( (arg = extractArg( argc, argv, "help", recognizedArg )) != NULL ) {
        if( ! arg[0] ) {
            throw std::invalid_argument("Help");
        }
    }

    setDefaults();

    arg = extractArg( argc, argv, "rndSeed", recognizedArg );
    if( arg ) {
        std::istringstream ss(arg);
        ss >> rndSeed;
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: rndSeed");
        }
    }
    if( rndSeed == 0 ) {
        std::random_device rd;
        cutyp BITS = 8;
        for( uint i=0 ; i<std::numeric_limits<decltype(rndSeed)>::digits ; i+=BITS ) {
            rndSeed <<= BITS;
            rndSeed |= rd() & ((1<<BITS)-1);
        }
    }

    arg = extractArg( argc, argv, "numberSpecs" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> numberSpecs;
        if( ! ss.good() || numberSpecs < 1 ) {
            throw std::invalid_argument("Invalid command line arg: numberSpecs");
        }
    }

    //The probability of genetic operators:
    {
        //Flags' genetic operators (mutation, corssing, replacing, new) which specified in the command line
        utyp fOperators = 0;

        arg = extractArg( argc, argv, "pMutatnion" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pMutatnion;
            if( ! ss.good() || pMutatnion < 0 || pMutatnion > 1 ) {
                throw std::invalid_argument("Invalid command line arg: pMutatnion");
            }
            fOperators |= 1; // The probability of the mutations operator was given directly in the command line.
        }

        arg = extractArg( argc, argv, "pCross" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pCross;
            if( ! ss.good() || pCross < 0 || pCross > 1 ) {
                throw std::invalid_argument("Invalid command line arg: pCross");
            }
            fOperators |= 2; // The probability of the cross operator was given directly in the command line.
        }

        arg = extractArg( argc, argv, "pReplace" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pReplace;
            if( ! ss.good() || pReplace < 0 || pReplace > 1 ) {
                throw std::invalid_argument("Invalid command line arg: pReplace");
            }
            fOperators |= 4; // The probability of the replace operator was given directly in the command line.
        }

        arg = extractArg( argc, argv, "pNew" , recognizedArg);
        if( arg ) {
            std::istringstream ss(arg);
            ss >> pNew;
            if( ! ss.good() || pNew < 0 || pNew > 1 ) {
                throw std::invalid_argument("Invalid command line arg: pNew");
            }
            fOperators |= 8; // The probability of the new operator was given directly in the command line.
        }

        if( fOperators == (15 & ~1) ) {
            cftyp sum = pCross + pReplace + pNew;
            if( sum > 1.0 ) {
                std::string msg = "Invalid command line arg: pCross + pReplace + pNew = " + std::to_string(sum) + " > 1.0 ";
                throw std::invalid_argument( msg );
            }
            pMutatnion = 1.0 - sum;
        } else if( fOperators == (15 & ~2) ) {
            cftyp sum = pMutatnion + pReplace + pNew;
            if( sum > 1.0 ) {
                std::string msg = "Invalid command line arg: pMutatnion + pReplace + pNew = " + std::to_string(sum) + " > 1.0 ";
                throw std::invalid_argument( msg );
            }
            pCross = 1.0 - sum;
        } else if( fOperators == (15 & ~4) ) {
            cftyp sum = pMutatnion + pCross + pNew;
            if( sum > 1.0 ) {
                std::string msg = "Invalid command line arg: pMutatnion + pCross + pNew = " + std::to_string(sum) + " > 1.0 ";
                throw std::invalid_argument( msg );
            }
            pReplace = 1.0 - sum;
        } else if( fOperators == (15 & ~8) ) {
            cftyp sum = pMutatnion + pCross + pReplace;
            if( sum > 1.0 ) {
                std::string msg = "Invalid command line arg: pMutatnion + pCross + pReplace = " + std::to_string(sum) + " > 1.0 ";
                throw std::invalid_argument( msg );
            }
            pNew = 1.0 - sum;
        }

        {
            cftyp sum = pMutatnion + pCross + pReplace + pNew;
            if( fabs( 1.0 - sum ) > EPSILON1 ) {
                std::string msg = "Invalid command line arg: pMutatnion + pCross + pReplace + pNew = " + std::to_string(sum) + " <> 1.0 ";
                throw std::invalid_argument( msg );
            }
        }
    }

    arg = extractArg( argc, argv, "pBack" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> pBack;
        if( ! ss.good() || pBack < 0 || pBack > 1 ) {
            throw std::invalid_argument("Invalid command line arg: pBack");
        }
    }

    arg = extractArg( argc, argv, "stopCross" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> stopCross;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || stopCross < 0 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: stopCross");
        }
    }

    arg = extractArg( argc, argv, "redunPenal" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> redunPenal;
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: redunPenal");
        }
    }

    arg = extractArg( argc, argv, "redunPenal" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> redunPenal;
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: redunPenal");
        }
    }

    arg = extractArg( argc, argv, "rewAEmpty" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> rewAEmpty;
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: rewAEmpty");
        }
    }

    arg = extractArg( argc, argv, "rewBEmpty" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> rewAEmpty;
        if( ! ss.good() || rewBEmpty <= 0 ) {
            throw std::invalid_argument("Invalid command line arg: rewBEmpty");
        }
    }

    arg = extractArg( argc, argv, "minStagn" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> minStagn;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || minStagn < 0 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: minStagn");
        }
    }

    arg = extractArg( argc, argv, "iniStagn" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> iniStagn;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || iniStagn < 0 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: iniStagn");
        }
    }

    arg = extractArg( argc, argv, "maxTime" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> maxTime;
        if( ! ss.good() || maxTime < 0 ) {
            throw std::invalid_argument("Invalid command line arg: maxTime");
        }
    }

    arg = extractArg( argc, argv, "maxLoops" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> maxLoops;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || maxLoops < 0 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: maxLoops");
        }
    }

    arg = extractArg( argc, argv, "haltFreq" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> haltFreq;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || haltFreq < 0 || haltFreq > 22 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: haltFreq");
        }
        haltFreq = static_cast<decltype(haltFreq)>(1) << haltFreq;
    }

    arg = extractArg( argc, argv, "saveFreq" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> saveFreq;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || saveFreq < 0 || saveFreq > 22 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: saveFreq");
        }
        saveFreq = static_cast<decltype(saveFreq)>(1) << saveFreq;
    }

    arg = extractArg( argc, argv, "crossMeth" , recognizedArg);
    if( arg ) {
        std::string buff;
        std::istringstream ss(arg);
        ss >> buff;
        std::transform( buff.begin() , buff.end() , buff.begin() , [](unsigned char c) -> unsigned char { return std::tolower(c); } );
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: crossMeth");
        }
        if( buff == "position" ) {
            crossMeth = ECM_POSITION;
        } else if( buff == "gens" ) {
            crossMeth = ECM_GENS;
        } else {
            std::string msg = "Invalid command line arg: crossMeth [";
            msg += buff;
            msg += "]";
            throw std::invalid_argument(msg);
        }
    }

    arg = extractArg( argc, argv, "sortItems" , recognizedArg);
    if( arg ) {
        std::string buff;
        std::istringstream ss(arg);
        ss >> buff;
        std::transform( buff.begin() , buff.end() , buff.begin() , [](unsigned char c) -> unsigned char { return std::tolower(c); } );
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: sortItems");
        }
        if( buff == "yes" || buff == "1" ) {
            sortItems = true;
        } else if( buff == "no" || buff == "not" || buff == "0" ) {
            sortItems = false;
        } else {
            std::string msg = "Invalid command line arg: sortItems [";
            msg += buff;
            msg += "]";
            throw std::invalid_argument(msg);
        }
    }

    arg = extractArg( argc, argv, "sortItems" , recognizedArg);
    if( arg ) {
        std::string buff;
        std::istringstream ss(arg);
        ss >> buff;
        std::transform( buff.begin() , buff.end() , buff.begin() , [](unsigned char c) -> unsigned char { return std::tolower(c); } );
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: sortItems");
        }
        if( buff == "yes" || buff == "1" ) {
            sortItems = true;
        } else if( buff == "no" || buff == "not" || buff == "0" ) {
            sortItems = false;
        } else {
            std::string msg = "Invalid command line arg: sortItems [";
            msg += buff;
            msg += "]";
            throw std::invalid_argument(msg);
        }
    }

    arg = extractArg( argc, argv, "dataDir" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> dataDir;
        if( ! ss.good() || dataDir.size() < 1 ) {
            throw std::invalid_argument("Invalid command line arg: dataDir");
        }
    }
    if( ! dirExists( dataDir ) ) {
        if( ! createDir( dataDir) ) {
            std::string msg = "The data dir [";
            msg += dataDir;
            msg += "] do not exists and cannot create it";
            throw std::invalid_argument( msg );
        }
    }

    arg = extractArg( argc, argv, "taskName" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> taskName;
        if( ! ss.good() || taskName.size() < 1 ) {
            throw std::invalid_argument("Invalid command line arg: taskName");
        }
    }

    arg = extractArg( argc, argv, "fromStdIn" , recognizedArg);
    if( arg ) {
        std::string buff;
        std::istringstream ss(arg);
        ss >> buff;
        std::transform( buff.begin() , buff.end() , buff.begin() , [](unsigned char c) -> unsigned char { return std::tolower(c); } );
        if( ! ss.good() ) {
            throw std::invalid_argument("Invalid command line arg: fromStdIn");
        }
        if( buff == "yes" || buff == "1" ) {
            fromStdIn = true;
        } else if( buff == "no" || buff == "not" || buff == "0" ) {
            fromStdIn = false;
        } else {
            std::string msg = "Invalid command line arg: fromStdIn [";
            msg += buff;
            msg += "]";
            throw std::invalid_argument(msg);
        }
    }

    arg = extractArg( argc, argv, "verbosity" , recognizedArg);
    if( arg ) {
        std::istringstream ss(arg);
        ss >> verbosity;
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( ! ss.good() || verbosity < 0 ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            throw std::invalid_argument("Invalid command line arg: verbosity");
        }
    }

    if( getFromStdIn() ) {
        items.read( std::cin , getVerbosity() , getSortItems() );
    } else {
        std::ifstream ifs( getDataPath() , std::ifstream::in );
        if( ! ifs.good() ) {
            std::string msg = "Cannot open data file [";
            msg += getDataPath();
            msg += "]";
            throw std::invalid_argument( msg );
        }
        items.read( std::cin , getVerbosity() , getSortItems() );
    }

}


void Params::showHelp() noexcept {

    std::cout << " --rndSeed=[uint] <1, 2^64-1> default: " << defRndSeed() << std::endl;
    std::cout << "    The seed of pseudo random number generator." << std::endl;
    std::cout << " The value zero indicates will be used std::random_device." << std::endl;
    std::cout << std::endl;

    std::cout << " --numberSpecs=[uint] <1, MAX_MEMORY> default: " << defNumberSpecs() << std::endl;
    std::cout << "    Default number of specimens." << std::endl;
    std::cout << std::endl;

    std::cout << " --pMutatnion=[float] <0, 1> default: " << defPMutatnion() << std::endl;
    std::cout << "    Probability of mutation." << std::endl;
    std::cout << std::endl;

    std::cout << " --pCross=[float] <0, 1> default: " << defPCross() << std::endl;
    std::cout << "    Probability of crosing specimens. The stagnation of the new specimen" << std::endl;
    std::cout << " created by crossing is equal average stagnation his of two parents." << std::endl;
    std::cout << std::endl;

    std::cout << " --pReplace=[float] <0, 1> default: " << defPReplace() << std::endl;
    std::cout << "    Probability of replace. The stagnation of the new specimen" << std::endl;
    std::cout << " created by replace is equal stagnation of the source specimen." << std::endl;
    std::cout << std::endl;

    std::cout << " --pNew=[float] <0, 1> default: " << defPNew() << std::endl;
    std::cout << "    Probability of create new, random specimen. The stagnation of " << std::endl;
    std::cout << " the new specimen created by new operator always is equal zero." << std::endl;
    std::cout << std::endl;

    std::cout << " --pBack=[float] <0, 1> default: " << defPNew() << std::endl;
    std::cout << "    Probability back the specimen to the last best solve from his copy." << std::endl;
    std::cout << std::endl;

    std::cout << " --stopCross=[uint] <0, 2^64-1> default: " << defStopCross() << std::endl;
    std::cout << "    When loops reached value x the crossing operation  will" << std::endl;
    std::cout << " be stop. Value zero indicate the crossing operation  continues" << std::endl;
    std::cout << " whole time execute program." << std::endl;
    std::cout << std::endl;

    std::cout << " --redunPenal=[float] <-INF,_INF> default: " << defRedunPenal() << std::endl;
    std::cout << "    The penalty for redundant items in the knapsacks." << std::endl;
    std::cout << " If redunPenal > 0 it will be rewarding for redundant items, not penal." << std::endl;
    std::cout << std::endl;

    std::cout << " --rewAEmpty=[float] <-INF,+INF> default: " << defRewAEmpty() << std::endl;
    std::cout << "    The reward [A] for the empty place in the knapsack by formula A*empty^B. " << std::endl;
    std::cout << " When A<0 this value is penalty and not is reward. The empty place in " << std::endl;
    std::cout << " backpack is harmful, but when B>1 the genetic algorithm put more items " << std::endl;
    std::cout << " to the one or few knapsacks - maybe even one or several backpacks will " << std::endl;
    std::cout << " be empty. When 0<B<1 the genetic algorithm try put the items evenly to " << std::endl;
    std::cout << " all knapsacks. " << std::endl;
    std::cout << std::endl;

    std::cout << " --rewBEmpty=[float] <0,+INF> default: " << defRewBEmpty() << std::endl;
    std::cout << "    The reward [B] for the empty place in the knapsack by formula A*empty^B." << std::endl;
    std::cout << std::endl;

    std::cout << " --minStagn=[uint] <0,2^64-1> default: " << defMinStagn() << std::endl;
    std::cout << "    Each specimen have to have the stagnation parameter more than minStagn to apply" << std::endl;
    std::cout << " operators: new, replace nad crossing. Otherwise  will be apply only mutation operator." << std::endl;
    std::cout << std::endl;

    std::cout << " --iniStagn=[uint] <0,2^64-1> default: " << defIniStagn() << std::endl;
    std::cout << "    The initial stagnation of the all specimens when program is begin." << std::endl;
    std::cout << std::endl;

    std::cout << " --maxTime=[uint] <0,2^32-1> default: " << defMaxTime() << std::endl;
    std::cout << "    The max time for whole run program. When is equal zero, the program is running" << std::endl;
    std::cout << " until the stop condition is true.." << std::endl;
    std::cout << std::endl;

    std::cout << " --maxLoops=[uint] <0,2^64-1> default: " << defMaxLoops() << std::endl;
    std::cout << "    The max number of the computations loops. When is equal zero, the program" << std::endl;
    std::cout << " is running to the end time or without end - when you have to send ctrl+c signal" << std::endl;
    std::cout << " in order to ending program." << std::endl;
    std::cout << std::endl;

    std::cout << " --haltFreq=[uint=2^N-1] <0,22> default: " << defHaltFreq() << std::endl;
    std::cout << "    The frequency of the probiting of the stop condition." << std::endl;
    std::cout << std::endl;

    std::cout << " --saveFreq=[uint=2^N-1] <0,22> default: " << defSaveFreq() << std::endl;
    std::cout << "    The frequency of save file." << std::endl;
    std::cout << std::endl;

    std::cout << " --crossMeth=[string] {position|gens} default: " << defCrossMeth() << std::endl;
    std::cout << "    The method of the crossing specimens." << std::endl;
    std::cout << std::endl;

    std::cout << " --sortItems=[string] true|false default: " << defSortItems() << std::endl;
    std::cout << "    Sort the items?" << std::endl;
    std::cout << std::endl;

    std::cout << " --accEvaluate=[float] <0,INF> default: " << defAccEvaluate() << std::endl;
    std::cout << "    The acceptable evaluate. The zero value" << std::endl;
    std::cout << " indicates run to stop condition." << std::endl;
    std::cout << std::endl;

    std::cout << " --dataDir=[string] default: " << defDataDir() << std::endl;
    std::cout << "    The directory with files data." << std::endl;
    std::cout << std::endl;

    std::cout << " --taskName=[string] default: " << defTaskName() << std::endl;
    std::cout << "    The task name will be used to name the files." << std::endl;
    std::cout << std::endl;

    std::cout << " --fromStdIn=[string] {true|false} default: " << defFromStdIn() << std::endl;
    std::cout << "    The path to file containing backpacks and items." << std::endl;
    std::cout << " If empty it read from stdin." << std::endl;
    std::cout << std::endl;

    std::cout << " --verbosity=[uint] <0,+INF> default: " << defVerbosity() << std::endl;
    std::cout << "    The verbosity." << std::endl;
    std::cout << "    verbosity >= 1 - show random seed." << std::endl;
    std::cout << "    verbosity >= 5 - show input information." << std::endl;
    std::cout << std::endl;

    std::cout << " --help " << std::endl;
    std::cout << "    Show this help" << std::endl;
}

