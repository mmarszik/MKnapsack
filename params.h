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
    ECM_POSITION,
    ECM_GENS,
};

class Params {
private:
    ultyp  rndSeed;         // The seed of pseudo random number generator. The value zero indicates will be used std::random_device.
    utyp   numberSpecs;     // Default number of specimens.
    ftyp   pMutatnion;      // Probability of mutation.
    ftyp   pCross;          // Probability of crossing specimen.
    ftyp   pReplace;        // Probability of replace.
    ftyp   pNew;            // Probability of create new, random specimen.
    ftyp   pBack;           // Probability back to the diploidy.
    ultyp  stopCross;       // When loops reached value x the crossing operation  will be stop. Value zero indicate the crossing operation  continues whole time execute program.
    ftyp   redunPenal;      // The penalty for redundant items.
    ftyp   rewAEmpty;       // The reward [A] for the empty place in the knapsack by formula A*empty^B.
    ftyp   rewBEmpty;       // The reward [B] for the empty place in the knapsack by formula A*empty^B.
    ultyp  minStagn;        // The minimal stagnation.
    ultyp  iniStagn;        // The initial stagnation.
    time_t maxTime;         // The max time for computatnion.
    ultyp  maxLoops;        // The max loop for computatnion.
    utyp   haltFreq;        // The frequency of the probiting of the stop condition.
    utyp   saveFreq;        // The frequency of save file.
    ECrossMethod crossMeth; // The method of the crossing specimens.
    bool   sortItems;       // Sort the items?
    ftyp   accEvaluate;     // The acceptable evaluate.
    std::string dataDir;    // The directory with files data.
    std::string taskName;   // The task name will be used to name the files.
    bool   fromStdIn;       // The path to file containing backpacks and items. If empty it read from stdin.
    utyp   verbosity;       // The verbosity.
    bool   help;            // Show help?

    Backpacks backpacks;
    BpItems   items;

private:
    void setDefaults() noexcept(false);

public:
    Params(int argc, char *argv[]) noexcept(false);
    bool isHelp() const noexcept { return help; }
    static void showHelp() noexcept;

};

