////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:20:49 CET
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

#include "rnd_fib.h"

using TRnd = RndFib2a;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_2a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
3655671857
3112833665
594534808
1954924846
3080878651
1703364130
4294927693445672644

real	0m6.243s
user	0m6.238s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_2a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.37e+07  |3226942375|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.87294303|  PASSED  

real	0m1.641s
user	0m1.651s
sys	0m0.108s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_2a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
3655671857
3112833665
594534808
1954924846
3080878651
1703364130
4294927693445672644

real	0m5.853s
user	0m5.853s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_2a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.66e+07  |4060550353|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.86737275|  PASSED  

real	0m1.521s
user	0m1.552s
sys	0m0.095s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x582fc479
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x582fc479
length= 128 megabytes (2^27 bytes), time= 2.0 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+2,13-6,T)         R= +13.3  p =  5.4e-5   mildly suspicious
  ...and 116 test result(s) without anomalies

rng=RNG_stdin32, seed=0x582fc479
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+2,13-6,T)         R= +29.6  p =  1.4e-10   VERY SUSPICIOUS 
  ...and 123 test result(s) without anomalies

rng=RNG_stdin32, seed=0x582fc479
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+2,13-5,T)         R= +54.4  p =  1.7e-21    FAIL !!        
  [Low1/32]BCFN(2+3,13-5,T)         R=  +9.6  p =  6.1e-4   unusual          
  ...and 130 test result(s) without anomalies


real	0m9.783s
user	0m9.707s
sys	0m0.368s
*/
