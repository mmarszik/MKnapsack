////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:44:21 CET
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

#include "rnd_mlin.h"

const MArray<ultyp, 16> RndMLin::A = {47419241ull, 12102661ull, 13794173ull, 21584377ull, 15157847ull, 10621591ull, 14256043ull, 18723209ull, 22706731ull, 22326617ull, 12112703ull, 16092161ull, 18569329ull, 12439723ull, 31530523ull, 14090221ull};
const MArray<ultyp, 16> RndMLin::B = {15425444914155312697ull, 14096522162449405717ull, 15139298917997085001ull, 10591700710506094177ull, 10518945472650288103ull, 16104502190471396477ull, 17659737197056618361ull, 13989857496617634559ull, 10332662733093870833ull, 14995112524401473201ull, 13964140567185167767ull, 12902612179013087771ull, 17993561092619302769ull, 14589499923442078381ull, 16682475420714780749ull, 15499846147571735143ull};
