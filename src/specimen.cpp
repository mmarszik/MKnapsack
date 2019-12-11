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
/// @created on 2019-12-02 23:59:04 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 9112a7fa-80dc-43ba-a8d3-8fa5d683e702                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "specimen.h"
#include "next_line.h"

void Specimen::save( std::ostream &out ) const {
    out << std::setprecision(14) << ceval      << " ";
    out << std::setprecision(14) << cweight    << " ";
    out << std::setprecision( 0) << stagnation << " ";
    for( size_t i=0 ; i<cgenotype.size() ; i++ ) {
        out << (int)spec.cgenotype[i] << " ";
    }
    out << "\n";
}

void Specimen::read(
    std::istream &is,
    cutyp  cntItems,
    cutyp  cntBackpacks
) {
    std::istringstream ss;
    std::string line;
    line = nextLine( is );
    if( !is.good() || line.size() < 1 ) {
        throw std::invalid_argument("Cannot read");
    }

    ss.str( line );
    ss >> ceval;
    if( !is.good() || !ss.good() || line.size() < 1 ) {

    }
    is >> cweight;
    is >> stagnation;
    for( size_t i=0 ; i<cgenotype.size() ; i++ ) {
        out << (int)spec.cgenotype[i] << " ";
    }
}

