////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:13:44 CET
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

#include <new>
#include <vector>

#include "defs.h"

class BpItem {
private:
    cftyp reward;   // The reward when item is in the one of backpacks.
    cftyp weight;   // The weight of the item.

public:
    BpItem(cftyp reward, cftyp weight) noexcept: reward(reward), weight(weight) {
    }

    void operator=(const BpItem &other) noexcept {
        new(this)BpItem(other.getReward(),other.getWeight());
    }

    ftyp getReward() const  noexcept { return reward; }

    ftyp getWeight() const  noexcept { return weight; }

    static bool cmpItem( const BpItem &a , const BpItem &b )  noexcept {
        return a.reward / a.weight > b.reward / b.weight;
    }

};

class BpItems {
private:
    std::vector<BpItem> items;

public:
    //Read info about all items from input stream.
    void read(
        std::istream &is,
        cityp verbosity
    ) noexcept(false);
};

















