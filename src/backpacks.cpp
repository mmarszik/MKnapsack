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
/// @created on 2019-11-30 09:06:42 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 2ecb09bc-b78f-443b-9c03-c129ae5ff1f3                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////


#include <stdexcept>
#include <sstream>

#include "backpacks.h"
#include "verbout.h"
#include "def_verb.h"
#include "next_line.h"

void Backpacks::read(std::istream &is, cityp verbosity) noexcept(false) {
    std::istringstream ss;
    std::string line;
    VerbOut out(verbosity,VERB_HINT_INPUT);

    out << "Pleas input number of backpacks:";

    line = nextLine( is );
    ss.str( line );
    size_t size;
    ss >> size;
    if( !is.good() || !ss.good() || line.size() < 1 || size < 1 ) {
        throw std::invalid_argument("Invalid number of backpacks");
    }

    backpack.resize( size );

    for( size_t i=0 ; i<size ; i++ ) {

        out << "Please input size of [" << (i+1) << "] backpack:";

        line = nextLine( is );
        ss.str( line );
        ss >> backpack[i];
        if( !is.good() || !ss.good() || line.size() < 1 || backpack[i] <= 0 ) {
            throw std::invalid_argument("Invalid size of backpack");
        }
    }
    _begin = backpack.data();
    _end = _begin + size;
}
