////////////////////////////////////////////////////////////////////////
///                                                                   //
/// The genetic Algorithm to solve Problem Multi-Knapsack.            //
///                                                                   //
/// It is file containing source code of genetic algorithm to solve   //
/// multi-knapsack problem. It turned out that the genetic algorithm  //
/// very well solves the multi-backpack problem.                      //
///                                                                   //
/// The file is share on the open source licence, but unlike GPL,     //
/// MIT, BSD, APACHE, L-GPL, etc, it is NOT standard and NOT          //
/// liberary licence of the open source. By downloading and reading   //
/// this file, you conclude a contract with me. Namely, if you        //
/// understand that my source code can be improved (for example:      //
/// speed up, better algorithms, better implementatnions, better      //
/// parametrs, fixed bugs, etc), you need to present me everything    //
/// in very detail. You can only download, read and compile this      //
/// project only on the your personal computer. You can run the       //
/// executable file and solve any problem, but only on the your own   //
/// personal computer. You can see what the genetic alghorithm work   //
/// in any practical multi-knapsack problem. However you can not use  //
/// results of this program in the business applications. You also    //
/// can NOT modifi, reshare, redistribuate binary or text version     //
/// this or other file from whole project. You can not use whole      //
/// file or fews lines from the file in your or others projects. If   //
/// you need the other or commercial licence please send to me email. //
///                                                                   //
////////////////////////////////////////////////////////////////////////
///                                                                   //
/// @created on 2019-11-30 09:14:22 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 20568ad3-53a4-4f66-ab34-56a3280081d4                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

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

    // The below method build path to the data file containing
    // description of knapsacks and items.
    std::string getDataPath() const noexcept;

    // The below method build path to the data file containing
    // any number of specimens.
    std::string getSpecsPath() const noexcept;


public:
    ultyp getRndSeed() const noexcept {
        return rndSeed;
    }
    utyp getNumberSpecs() const noexcept {
        return numberSpecs;
    }
    ftyp getPMutatnion() const noexcept {
        return pMutatnion;
    }
    ftyp getPCross() const noexcept {
        return pCross;
    }
    ftyp getPReplace() const noexcept {
        return pReplace;
    }
    ftyp getPNew() const noexcept {
        return pNew;
    }
    ftyp getPBack() const noexcept {
        return pBack;
    }
    ultyp getStopCross() const noexcept {
        return stopCross;
    }
    ftyp getRedunPenal() const noexcept {
        return redunPenal;
    }
    ftyp getRewAEmpty() const noexcept {
        return rewAEmpty;
    }
    ftyp getRewBEmpty() const noexcept {
        return rewBEmpty;
    }
    ultyp getMinStagn() const noexcept {
        return minStagn;
    }
    ultyp getIniStagn() const noexcept {
        return iniStagn;
    }
    time_t getMaxTime() const noexcept {
        return maxTime;
    }
    ultyp getMaxLoops() const noexcept {
        return maxLoops;
    }
    utyp getHaltFreq() const noexcept {
        return haltFreq;
    }
    utyp getSaveFreq() const noexcept {
        return saveFreq;
    }
    ECrossMethod getCrossMeth() const noexcept {
        return crossMeth;
    }
    bool getSortItems() const noexcept {
        return sortItems;
    }
    ftyp getAccEvaluate() const noexcept {
        return accEvaluate;
    }
    std::string getDataDir() const noexcept {
        return dataDir;
    }
    std::string getTaskName() const noexcept {
        return taskName;
    }
    bool getFromStdIn() const noexcept {
        return fromStdIn;
    }
    utyp getVerbosity() const noexcept {
        return verbosity;
    }
    bool getHelp() const noexcept {
        return help;
    }

public:
    Params() noexcept {}
    Params(int argc, char *argv[]) noexcept(false);
    bool isHelp() const noexcept { return help; }
    static void showHelp() noexcept;

};

