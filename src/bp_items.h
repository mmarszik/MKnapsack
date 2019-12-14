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
/// @created on 2019-11-30 09:13:44 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token a5f9e093-a132-4533-869d-7c0768ca84c8                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

#include "defs.h"

class BpItem {
private:
    ftyp reward;   // The reward when item is in the one of backpacks.
    ftyp weight;   // The weight of the item.
    utyp number;   // The number of item.

public:
    BpItem() noexcept {
    }
    BpItem(cftyp reward, cftyp weight, cutyp number) noexcept: reward(reward), weight(weight), number(number) {
    }

    ftyp getReward() const noexcept { return reward; }
    ftyp getWeight() const noexcept { return weight; }
    utyp getNumber() const noexcept { return number; }

    static bool cmpItem( const BpItem &a , const BpItem &b ) noexcept {
        return a.reward / a.weight > b.reward / b.weight;
    }

};

class BpItems {
private:
    std::vector<BpItem> bpItems;
    const BpItem *atBegin;
    const BpItem *atEnd;

public:

    //Read info about all items from input stream.
    void read(
        std::istream &is,
        cityp verbosity,
        const bool sortItems
    ) noexcept(false);

    //Write info about all items from input stream.
    void write( std::ostream &os ) noexcept(false);

    const BpItem* begin() const noexcept {
        return atBegin;
    }

    const BpItem* end() const noexcept {
        return atEnd;
    }

};



