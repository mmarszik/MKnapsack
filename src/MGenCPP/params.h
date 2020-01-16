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

#include "grnd.h"
#include <string>

namespace MGen {

class Params {
private:
    TULONG  rndSeed;         // The seed of pseudo random number generator. The value zero indicates will be used std::random_device.
    TUINT   numberSpecs;     // The number of specimens.
    TUINT   numberParents;   // The number of parents.
    TUINT   swapParents;     // The number of swap parents (weak sorting)
    TFLOAT  pMutation;       // Probability of mutation.
    TFLOAT  pCross;          // Probability of crossing specimen.
    TFLOAT  pBack;           // Probability back to the diploidy.
    TFLOAT  pBests;          // Probability work only best fraction.

    TUINT   numberBests;     // The size of the sortable fraction of the bests specimens from whole population.

    TULONG  maxLoops;        // The max loop for computation.

protected:
    bool        help;        // Show help?
    std::string error;

private:
    void setDefaults();

protected:
    void setError(const std::string &error);

public:
    void init(int argc, char *argv[]);
    void showHelp() const;

public:
    bool isHelp() const { return help; }
    TULONG getSeed() const { return rndSeed; }
    TUINT getNumberSpecs() const { return numberSpecs; }
    TUINT getNumberBests() const { return numberBests; }
    TUINT getNumberParents() const { return numberParents; }
    TUINT getSwapParents() const { return swapParents; }
    TULONG getMaxLoops() const { return maxLoops; }
    TFLOAT getPMutation() const { return pMutation; }
    TFLOAT getPCross() const { return pCross; }
    TFLOAT getPBack() const { return pBack; }
    TFLOAT getPBests() const { return pBests; }

};


}