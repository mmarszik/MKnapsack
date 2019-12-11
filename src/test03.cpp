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
/// @created on 2019-11-30 09:45:43 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 6651763c-e327-4e42-8a80-e0d14dc423fa                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#include "defs.h"

#ifdef TEST03_PROGRAM

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

#include "rnd.h"

int main(int argc, char *argv[]) {
    std::random_device rd;
    ultyp seed = 0;
    for( utyp i=0 ; i<4 ; i++ ) {
        seed = ( seed << 8 ) | ( rd() & 0xFF );
    }
    cutyp min = 3;
    cutyp max = 200;
    cutyp LOOPS = 0xFFFFFFFFu;
    {
        TRnd rnd(seed);
        ultyp sum = 0;
        auto start = std::chrono::system_clock::now();
        for( utyp i=0 ; i<LOOPS ; i++ ) {
            sum += rnd() % (max-min+1) + min;
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Elapsed: " << elapsed.count() << std::endl;
        std::cout << "Sum: " << sum << std::endl;
    }
    {
        ultyp sum = 0;
        TRnd rnd(seed);
        TRndBuff<min,max> rndB(rnd);
        auto start = std::chrono::system_clock::now();
        for( utyp i=0 ; i<LOOPS ; i++ ) {
            sum += rndB();
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Elapsed: " << elapsed.count() << std::endl;
        std::cout << "Sum: " << sum << std::endl;
    }
    return 0;
}

#endif

