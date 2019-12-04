////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on pon, 2 gru 2019, 23:59:04 CET
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

