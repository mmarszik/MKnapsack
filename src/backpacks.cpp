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

#include <MiscCPP/m_verb_out.h>
#include <MiscCPP/m_next_line.h>

#include "backpacks.h"
#include "def_verb.h"

void Backpacks::read(std::istream &is, cityp verbosity) noexcept(false) {
    std::istringstream ss;
    std::string line;
    VerbOut verbOut(verbosity,VERB_HINT_INPUT);

    verbOut << "Pleas input number of backpacks:";

    line = nextLine( is );
    ss.str( line );
    size_t size;
    ss >> size;
    if( is.fail() || ss.fail() || line.size() < 1 || size < 1 || size >= MLimits<TGEN>::max() ) {
        throw std::invalid_argument("Invalid number of backpacks");
    }

    backpacks.resize( size );

    for( size_t i=0 ; i<size ; i++ ) {

        verbOut << "Please input size of [" << (i+1) << "] backpack:";

        line = nextLine( is );
        ss.seekg( 0 );
        ss.str( line );
        ss >> backpacks[ i ];
        if( is.fail() || ss.fail() || line.size() < 1 || backpacks[i] < EPSILON1 ) {
            std::string msg = "Invalid size of [";
            msg += std::to_string(i+1);
            msg += "] backpack [";
            msg += std::to_string( backpacks[i] );
            msg += "]";
            throw std::invalid_argument( msg );
        }
    }
#ifdef MK_DEBUG
    for( size_t i=0 ; i<backpacks.size() ; i++ ) {
        std::cout << backpacks[i] << std::endl;
    }
#endif
    atBegin = &backpacks.front();
    atEnd   = atBegin + size;
}


void Backpacks::write(std::ostream &os) {
    os << "# Number of backpacks" << std::endl;
    os << backpacks.size() << std::endl;
    os << "# List of backpacks" << std::endl;
    for( size_t i=0 ; i<backpacks.size() ; i++ ) {
        os << backpacks[i] << std::endl;
    }
    os << "# End list of backpacks" << std::endl;
    os.flush();
}
