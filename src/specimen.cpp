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
#include <algorithm>
#include <MiscCPP/m_next_line.h>

#include "specimen.h"
#include "params.h"


void Specimen::evaluate(
    const MGenParams &params
) noexcept {
    std::vector<TMGEN_FLOAT> weights(0, genotype.size() );
    cftyp *const backpacks    = params.getBackpacks().begin();
    const BpItem *const items = params.getBpItems().begin();
    eval   = 0;
    weight = 0;
    std::fill( weights.begin() , weights.end() , 0 );
    for( size_t i=0 ; i<genotype.size() ; i++ ) {
        if( genotype[i] == 0 ) {
            continue;
        }
        const TGEN nr = genotype[i] - 1;
        if( weights[nr] + items[i].getWeight() > backpacks[nr] ) {
            eval -= params.getRedunPenal();
            continue;
        }
        weights[nr] += items[i].getWeight();
        weight      += items[i].getWeight();
        eval        += items[i].getReward();
    }
}

void Specimen::random(
    const MGenParams &params
) noexcept {
    stagnation = 0;
    genotype.resize( params.getBpItems().size() );
    for( size_t i=0 ; i<genotype.size() ; i++ ) {
        genotype[i] = rnd();
    }
    evaluate( params );
    store();
}

void Specimen::toString( std::string &str ) const noexcept {
    str.clear();
    std::ostringstream ss( str );
    ss << std::setprecision(14) << ceval      << " ";
    ss << std::setprecision(14) << cweight    << " ";
    ss << std::setprecision( 0) << stagnation << " ";
    for( size_t i=0 ; i<cgenotype.size() ; i++ ) {
        ss << static_cast<unsigned int>(cgenotype[i]) << " ";
    }
    ss << "\n";
    ss.flush();
}

void Specimen::fromString(
    const std::string &str,
    cutyp cntItems,
    cutyp cntBackpacks
) noexcept(false) {
    std::istringstream ss( str );
    ss >> ceval;
    if( !ss.good() ) {
        throw std::invalid_argument("Can not read ceval");
    }
    ss >> cweight;
    if( !ss.good() ) {
        throw std::invalid_argument("Can not read cweight");
    }
    ss >> stagnation;
    if( !ss.good() ) {
        throw std::invalid_argument("Can not read stagnation");
    }
    cgenotype.resize( cntItems );
    for( size_t i=0 ; i<cgenotype.size() ; i++ ) {
        ss >> cgenotype[i];
        if( !ss.good() ) {
            throw std::invalid_argument("Can not read cgenotype");
        }
#pragma GCC diagnostic ignored "-Wtype-limits"
        if( cgenotype[i] < 0 || cgenotype[i] > cntBackpacks ) {
#pragma GCC diagnostic warning "-Wtype-limits"
            std::string msg = "Cgenotype has invalid value: [";
            msg += std::to_string(cgenotype[i]);
            msg += "]";
            throw std::invalid_argument( msg );
        }
    }
    restore();
}


void Specimen::write(
    std::ostream                &os,
    const std::vector<Specimen> &specs
) {
    for( size_t i=0 ; i<specs.size() ; i++ ) {
        std::string str;
        specs[i].toString( str );
        os << str << std::endl;
    }
    os.flush();
}


std::vector<Specimen> Specimen::read(
    std::istream  &is,
    cutyp         cntItems,
    cutyp         cntBackpacks
) {
    std::vector<Specimen> specs;
    std::string str;
    while( ( str = nextLine(is) ).size() > 0 ) {
        Specimen spec;
        spec.fromString( str , cntItems , cntBackpacks );
        specs.push_back( spec );
    }
    std::sort( specs.begin() , specs.end() , Specimen::cmp );
    return specs;
}


