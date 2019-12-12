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
/// @created on 2019-12-12 23:32:40 CET                               //
/// @author MMarszik (Mariusz Marszalkowski sqnett.com)               //
/// @email mmarszik@gmail.com                                         //
/// @package MKnapsack                                                //
/// @token fdd7467d-c432-436f-824b-91f0a74e03d2                       //
/// @brief:                                                           //
///                                                                   //
////////////////////////////////////////////////////////////////////////


#include "defs.h"

#ifdef SANDBOX02_PROGRAM

#include <iostream>
#include <sstream>

int main() {
    std::string str;
    std::istringstream ss;
    double x, y;

    std::getline( std::cin , str );
    std::cout << "String: '" << str << "'" << std::endl;
    ss.str( str );
    ss >> x >> y;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::getline( std::cin , str );
    std::cout << "String: '" << str << "'" << std::endl;
    ss.str( str );
    ss.seekg(0);
    ss >> x >> y;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}

#endif


