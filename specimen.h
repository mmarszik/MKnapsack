////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on pon, 2 gru 2019, 23:58:49 CET
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

#include <vector>

#include "defs.h"
#include "rnd.h"

class Specimen {
public:
    using TGENOTYPE = std::vector<TGEN>;

private:
    TGENOTYPE genotype;   // genotype
    ftyp      eval;       // eval
    ftyp      weight;     // weight of all knapsacks
    ultyp     stagnation; // stagnation

private:
    TGENOTYPE cgenotype;  // copy genotype
    ftyp      ceval;      // copy eval
    ftyp      cweight;    // copy weight
    ultyp     cstagnation;// copy stagnation

public:
    void store() {
        cgenotype   = genotype;
        ceval       = eval;
        cweight     = weight;
        cstagnation = stagnation;
    }
    void restore() {
        genotype   = cgenotype;
        eval       = ceval;
        weight     = cweight;
        stagnation = cstagnation;
    }
    std::string toString() const {
//        std::ostringstream out;
//        out << std::setprecision(14) << spec.ceval << ", " << std::setprecision(14) << spec.cweight << " [";
//        for( size_t i=0 ; i<spec.genotype.size() ; i++ ) {
//            std::cout << (int)spec.cgenotype[i];
//            if( i < spec.genotype.size() - 1 ) {
//                std::cout << ",";
//            }
//        }
//        out << "]";
//        return out.;
    }

};