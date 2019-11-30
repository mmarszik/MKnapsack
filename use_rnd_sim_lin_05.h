////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:42:07 CET
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

#include "rnd_sim_lin.h"

using TRnd = RndSimLin05;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_05 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1552699492
2056328044
89866511
772063203
2030206109
1276786880
4294904446241197395

real	0m4.473s
user	0m4.472s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_05 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.66e+07  |2508323456|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.89104550|  PASSED  

real	0m1.576s
user	0m1.621s
sys	0m0.071s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_05 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1552699492
2056328044
89866511
772063203
2030206109
1276786880
4294904446241197395

real	0m4.394s
user	0m4.389s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_05 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.74e+07  |2864375332|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.64098282|  PASSED  

real	0m1.512s
user	0m1.542s
sys	0m0.076s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0xbc62d9e4
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 512 megabytes (2^29 bytes), time= 9.1 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 1 gigabyte (2^30 bytes), time= 17.7 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 2 gigabytes (2^31 bytes), time= 33.9 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 4 gigabytes (2^32 bytes), time= 65.2 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0xbc62d9e4
length= 6.250 gigabytes (2^32.644 bytes), time= 102 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+3,13-3,T)         R=  +8.7  p =  6.3e-4   unusual          
  ...and 159 test result(s) without anomalies


real	1m42.803s
user	1m41.885s
sys	0m4.354s
*/
