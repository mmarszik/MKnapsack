////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:14:11 CET
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

#include "defs.h"

#ifdef USING_STD_ARRAY

#include <array>

template<typename T,utyp SIZE>
using MArray = std::array<T,SIZE>;

#else

//template<typename T,utyp SIZE>
//using MArray = T[SIZE];


#include <cstdlib>
#include <initializer_list>
#include <algorithm>

template<typename T,utyp SIZE>
class MArray {
private:
    T t[SIZE];

public:
    MArray(){}
    MArray( const std::initializer_list<T> &_t ) {
        if( _t.size() != SIZE ) {
            abort();
        }
        std::copy(_t.begin(), _t.end(), t);
    }
    inline T& operator[] (cutyp i) {
        if( i >= SIZE ) abort();
        return t[i];
    }
    inline const T& operator[] (cutyp i) const {
        if( i >= SIZE ) abort();
        return t[i];
    }
    void fill(const T v) {
        for( utyp i=0 ; i<SIZE ; i++ ) {
            t[i] = v;
        }
    }
    inline utyp size() const {
        return SIZE;
    }
};

#endif

