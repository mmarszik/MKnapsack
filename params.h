////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:14:22 CET
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

#pragma once

#include <ctime>
#include <string>

#include "defs.h"
#include "backpacks.h"
#include "bp_items.h"


//MM: The available crosses methods.
enum ECrossMethod {
    EC_POSITION,
    EC_GENS,
};

class Params {
private:
    ultyp  rndSeed         =  0;               // The seed of pseudo random number generator. The value zero indicates will be used std::random_device.
    utyp   numberSpecs     =  256;             // Default number of specimens.
    ftyp   pMutatnion      =  0.999900;        // Probability of mutation.
    ftyp   pReplace        =  0.000001;        // Probability of replace.
    ftyp   pNew            =  0.000001;        // Probability of create new, random specimen.
    ftyp   unNPenal        = -0.000001;        // The penalty for redundant items.
    ftyp   rewAEmpty       = +0.000001;        // The reward [A] for the empty place in the knapsack by formula A*empty^B.
    ftyp   rewBEmpty       = +0.000001;        // The reward [B] for the empty place in the knapsack by formula A*empty^B.
    ultyp  minStagn        =  100000;          // The minimal stagnation.
    ultyp  iniStagn        =  100000;          // The initial stagnation.
    time_t maxTime         =  0;               // The max time for computatnion.
    ultyp  maxLoops        =  0;               // The max loop for computatnion.
    utyp   haltFreq        =  0xFFF;           // The frequency of the probiting of the stop condition.
    utyp   saveFreq        =  0xFFFF;          // The frequency of save file.
    ECrossMethod crossMeth =  EC_POSITION;     // The method of the crossing specimens.
    bool   sortItems       =  true;            // Sort the items?
    ftyp   accEvaluate     =  0;               // The acceptable evaluate.
    std::string dataDir    =  "./data/";       // The directory with files data.
    std::string taskName   =  "";              // The task name will be used to name the files.
    bool   fromStdIn       =  true;            // The path to file containing backpacks and items. If empty it read from stdin.
    ityp   verbosity       =  1;               // The verbosity.
    bool   help            =  false;           // Show help?

    Backpacks backpacks;
    BpItems   items;


public:
    Params(int argc, char *argv[]) noexcept(false);

    bool isHelp() const noexcept { return help; }
    void showHelp() const noexcept;

};

