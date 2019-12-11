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
/// @created on 2019-12-02 16:21:33 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token 0218cb32-b5d9-4a9d-9edc-9db60a894e2c                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////

#include "defs.h"

#ifdef TEST04_PROGRAM

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
    cultyp LOOPS = 20000000000ull;
    {
        TRnd rnd1(seed);
        TRnd rnd2(seed);
        ultyp sum = 0;
        auto start = std::chrono::system_clock::now();
        for( ultyp i=0 ; i<LOOPS ; i++ ) {
            sum += rnd1();
            sum += rnd2();
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Elapsed: " << elapsed.count() << std::endl;
        std::cout << "Sum: " << sum << std::endl;
    }
    {
        RndBase *rnd1 = new TRnd(seed);
        RndBase *rnd2 = new TRnd(seed);
        ultyp sum = 0;
        auto start = std::chrono::system_clock::now();
        for( ultyp i=0 ; i<LOOPS ; i++ ) {
            sum += rnd1->operator()();
            sum += rnd2->operator()();
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Elapsed: " << elapsed.count() << std::endl;
        std::cout << "Sum: " << sum << std::endl;
        delete rnd1;
        delete rnd2;
    }
    return 0;
}

#endif


