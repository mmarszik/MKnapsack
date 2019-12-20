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
/// @created on 2019-12-03 23:58:49 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 014fec8f-d1f5-4851-9ccf-203d22603092                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

#include <MRndCPP/rnd.h>
#include <MGenCPP/m_gen_spec.h>

#include "defs.h"

class MGenParams;

using TGEN = unsigned char;

class Specimen : public MGenSpec<TGEN> {
private:
    ftyp      weight;     // weight of all knapsacks
    ftyp      cweight;    // copy weight

public:
    inline void store() noexcept {
        MGenSpec::store();
        cweight    = weight;
    }

    inline void restore() noexcept {
        MGenSpec::restore();
        weight     = cweight;
    }

    void evaluate(
        const MGenParams &params
    ) noexcept;

    void random(
        const MGenParams &params
    ) noexcept;

    void toString(
        std::string &str
    ) const noexcept;

    void fromString(
        const std::string &str,
        cutyp cntItems,
        cutyp cntBackpacks
    ) noexcept(false);

    static void write(
        std::ostream &os,
        const std::vector<Specimen> &specs
    );

    static std::vector<Specimen> read(
        std::istream &is,
        cutyp cntItems,
        cutyp cntBackpacks
    );

    static bool cmp( const Specimen &a ,const Specimen &b) {
        return a.getEval() > b.getEval();
    }
};


