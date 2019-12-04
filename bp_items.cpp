////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:43:10 CET
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

#include <algorithm>

#include "bp_items.h"
#include "verbout.h"
#include "def_verb.h"

void BpItems::read(std::istream &is, cityp verbosity, const bool sortItems) {
    VerbOut out(verbosity,VERB_HINT_INPUT);
    out << "Please input number of items:";
    size_t number;
    is >> number;
    if( ! is.good() || number < 1 ) {
        throw std::invalid_argument("Invalid number of items");
    }
    items.resize( number );
    for( size_t i=0 ; i<number ; i++ ) {
        ftyp weight, reward;

        out << "Please input weight of [" << (i+1) << "] item:";
        is >> weight;
        if( ! is.good() || weight < EPSILON0 ) {
            throw std::invalid_argument("Invalid weight of item");
        }

        out << "Please input reward of [" << (i+1) << "] item:";
        is >> reward;
        if( ! is.good() || reward < EPSILON0 ) {
            throw std::invalid_argument("Invalid reward of item");
        }

        items[i] = BpItem( reward, weight );
    }

    if( sortItems ) {
        std::sort( items.begin() , items.end() , BpItem::cmpItem );
    }

}
