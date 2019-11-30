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

#include "params.h"


static ultyp defRndSeed() noexcept {
    return 0;
}
static utyp defNumberSpecs() noexcept {
    return 256;
}
static ftyp defPMutatnion() noexcept {
    return 0.999900;
}
static ftyp defPReplace() noexcept {
    return 0.000001;
}
static ftyp defPNew() noexcept {
    return 0.000001;
}
static ftyp defUnNPenal() noexcept {
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


static char* extractArg( int argc , char *argv[] , const char *arg ) noexcept {
    for( int i=1 ; i<argc ; i++ ) {
        int off = 0;
        if( argv[i][0] == '-' )
            off++;
        if( off && argv[i][1] == '-' )
            off++;
        if( strncasecmp( argv[i]+off , arg , strlen(arg) ) == 0 ) {
            off += strlen(arg);
            return argv[i]+off;
        }
    }
    return NULL;
}

void Params::setDefaults() noexcept(false) {
    rndSeed     = defRndSeed();
    numberSpecs = defNumberSpecs();
    pMutatnion  = defPMutatnion();
    pReplace    = defPReplace();
    pNew        = defPNew();
    if( fabs( 1.0 - pMutatnion + pReplace + pNew ) > EPSILON0 ) {
        throw std::invalid_argument("Invalid sum of the probabiliteis pMutatnion + pReplace + pNew ");
    }
    unNPenal  = defUnNPenal();
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


Params::Params(int argc, char *argv[]) noexcept(false) {
    char *arg;

    if( arg = extractArg( argc, argv, "help") ) {
        if( ! arg[0] ) {
            help = true;
            return;
        }
    }

}


void Params::showHelp() noexcept {
    std::cout << "--rndSeed=[uint] <1, 2^64-1> default: " << defRndSeed() << std::endl;
    std::cout << "    The seed of pseudo random number generator. The seed of pseudo random number generator. The value zero indicates will be used std::random_device." << std::endl;
    std::cout << std::endl;
    std::cout << "--numberSpecs=[uint] <1, MAX_MEMORY> default: " << defNumberSpecs() << std::endl;
    std::cout << "    Default number of specimens." << std::endl;
    std::cout << std::endl;
    std::cout << "--pMutatnion=[float] <0, 1> default: " << defPMutatnion() << std::endl;
    std::cout << "    Probability of mutation." << std::endl;
    std::cout << std::endl;
    std::cout << "--pReplace=[float] <0, 1> default: " << defPReplace() << std::endl;
    std::cout << "    Probability of replace." << std::endl;
    std::cout << std::endl;
    std::cout << "--pNew=[float] <0, 1> default: " << defPNew() << std::endl;
    std::cout << "    Probability of create new, random specimen." << std::endl;
    std::cout << std::endl;
    std::cout << "--unNPenal=[float] <0,INF> default: " << defUnNPenal() << std::endl;
    std::cout << "    The penalty for redundant items." << std::endl;
    std::cout << std::endl;
    std::cout << "--rewAEmpty=[float] <0,INF> default: " << defRewAEmpty() << std::endl;
    std::cout << "    The reward [A] for the empty place in the knapsack by formula A*empty^B." << std::endl;
    std::cout << std::endl;
    std::cout << "--rewBEmpty=[float] <0,16> default: " << defRewBEmpty() << std::endl;
    std::cout << "    The reward [B] for the empty place in the knapsack by formula A*empty^B." << std::endl;
    std::cout << std::endl;
    std::cout << "--minStagn=[uint] <0,2^64-1> default: " << defMinStagn() << std::endl;
    std::cout << "    The minimal stagnation." << std::endl;
    std::cout << std::endl;
    std::cout << "--iniStagn=[uint] <0,2^64-1> default: " << defIniStagn() << std::endl;
    std::cout << "    The initial stagnation." << std::endl;
    std::cout << std::endl;
    std::cout << "--maxTime=[uint] <0,2^32-1> default: " << defMaxTime() << std::endl;
    std::cout << "    The max time for computatnion." << std::endl;
    std::cout << std::endl;
    std::cout << "--maxLoops=[uint] <0,2^64-1> default: " << defMaxLoops() << std::endl;
    std::cout << "    The max loop for computatnion." << std::endl;
    std::cout << std::endl;
    std::cout << "--haltFreq=[uint=2^N-1] <0,2^20-1> default: " << defHaltFreq() << std::endl;
    std::cout << "    The frequency of the probiting of the stop condition." << std::endl;
    std::cout << std::endl;
    std::cout << "--saveFreq=[uint=2^N-1] <0,2^20-1> default: " << defSaveFreq() << std::endl;
    std::cout << "    The frequency of save file." << std::endl;
    std::cout << std::endl;
    std::cout << "--crossMeth=[string] {position|gens} default: " << defCrossMeth() << std::endl;
    std::cout << "    The method of the crossing specimens." << std::endl;
    std::cout << std::endl;
    std::cout << "--sortItems=[string] true|false default: " << defSortItems() << std::endl;
    std::cout << "    Sort the items?" << std::endl;
    std::cout << std::endl;
    std::cout << "--accEvaluate=[float] <0,INF> default: " << defAccEvaluate() << std::endl;
    std::cout << "    The acceptable evaluate. The zero value indicates run to stop condition." << std::endl;
    std::cout << std::endl;
    std::cout << "--dataDir=[string] default: " << defDataDir() << std::endl;
    std::cout << "    The directory with files data." << std::endl;
    std::cout << std::endl;
    std::cout << "--taskName=[string] default: " << defTaskName() << std::endl;
    std::cout << "    The task name will be used to name the files." << std::endl;
    std::cout << std::endl;
    std::cout << "--fromStdIn=[string] {true|false} default: " << defFromStdIn() << std::endl;
    std::cout << "    The path to file containing backpacks and items. If empty it read from stdin." << std::endl;
    std::cout << std::endl;
    std::cout << "--verbosity=[uint] <0,32> default: " << defVerbosity() << std::endl;
    std::cout << "    The verbosity." << std::endl;
    std::cout << std::endl;
    std::cout << "--help " << std::endl;
    std::cout << "    Show this help" << std::endl;
}

