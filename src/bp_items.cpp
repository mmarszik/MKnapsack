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
/// @created on 2019-11-30 09:43:10 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token bc0e60bb-8c2b-42d7-a686-df6ef3044aeb                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <sstream>
#include <m_verb_out.h>
#include <m_next_line.h>

#include "bp_items.h"
#include "def_verb.h"

void BpItems::read(std::istream &is, cityp verbosity, const bool sortItems) {
    std::istringstream ss;
    std::string line;
    VerbOut out(verbosity,VERB_HINT_INPUT);

    out << "Please input number of items:";

    line = nextLine( is );
    ss.str( line );
    size_t size;
    ss >> size;
    if( ss.fail() || line.size() < 1 || size < 1 ) {
        throw std::invalid_argument("Invalid number of items");
    }
    items.resize( size );
    for( size_t i=0 ; i<size ; i++ ) {
        ftyp weight, reward;

        out << "Please input (weight reward) of [" << (i+1) << "] item:";
        line = nextLine( is );
        ss.seekg(0);
        ss.str( line );
#ifdef MK_DEBUG
        std::cout << "Line: '" << line << "'" << std::endl;
#endif
        ss >> weight;
        ss >> reward;
        if( ss.fail() || line.size() < 1 || weight < EPSILON1 || reward < EPSILON1 ) {
            std::string msg = "Invalid item [";
            msg += std::to_string( i+1 );
            msg += "] (";
            msg += std::to_string(weight);
            msg += " ";
            msg += std::to_string(reward);
            msg += ")";
            throw std::invalid_argument( msg );
        }
        items[i] = BpItem( reward, weight );
    }

    if( sortItems ) {
        std::sort( items.begin() , items.end() , BpItem::cmpItem );
    }

#ifdef MK_DEBUG
    for( size_t i=0 ; i<items.size() ; i++ ) {
        std::cout << items[i].getWeight() << " " << items[i].getReward() << std::endl;
    }
#endif

}
