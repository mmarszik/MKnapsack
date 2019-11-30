////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:42:25 CET
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

#include "rnd_skip_lin.h"

using TRnd = RndSkipLin2b;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SKIP_LIN_2b -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
878713968
123488888
3326016157
2631003783
2609393688
3629582358
4294963195293194679

real	1m38.938s
user	1m38.841s
sys	0m0.024s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SKIP_LIN_2b -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  1.91e+07  |  93162057|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.47807386|  PASSED  

real	0m1.863s
user	0m2.327s
sys	0m0.058s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SKIP_LIN_2b -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
878713968
123488888
3326016157
2631003783
2609393688
3629582358
4294963195293194679

real	1m37.961s
user	1m37.873s
sys	0m0.052s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SKIP_LIN_2b -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  1.92e+07  | 250201195|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.54283662|  PASSED  

real	0m1.796s
user	0m2.261s
sys	0m0.045s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x64f78f19
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x64f78f19
length= 128 megabytes (2^27 bytes), time= 3.5 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x64f78f19
length= 256 megabytes (2^28 bytes), time= 7.5 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x64f78f19
length= 512 megabytes (2^29 bytes), time= 15.0 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x64f78f19
length= 1 gigabyte (2^30 bytes), time= 29.6 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x64f78f19
length= 2 gigabytes (2^31 bytes), time= 57.9 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0x64f78f19
length= 3.500 gigabytes (2^31.807 bytes), time= 102 seconds
  no anomalies in 153 test result(s)


real	1m42.824s
user	1m45.660s
sys	0m3.027s
*/
