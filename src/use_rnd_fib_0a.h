////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:19:37 CET
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

using TRnd = RndFib0a;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_0a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
3233202625
2328409647
3361551064
2495864169
3328962110
888761389
4295048276249409350

real	0m6.914s
user	0m6.887s
sys	0m0.012s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_0a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.53e+07  |2985258283|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.09737603|  PASSED  

real	0m1.540s
user	0m1.571s
sys	0m0.091s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_0a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
3233202625
2328409647
3361551064
2495864169
3328962110
888761389
4295048276249409350

real	0m6.586s
user	0m6.581s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_0a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.79e+07  |2347684909|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.21628845|  PASSED  

real	0m1.508s
user	0m1.587s
sys	0m0.050s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x5e274411
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x5e274411
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]Gap-16:B                 R=  -4.5  p =1-8.7e-4   unusual          
  ...and 116 test result(s) without anomalies

rng=RNG_stdin32, seed=0x5e274411
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x5e274411
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x5e274411
length= 1 gigabyte (2^30 bytes), time= 18.0 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x5e274411
length= 2 gigabytes (2^31 bytes), time= 34.6 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0x5e274411
length= 4 gigabytes (2^32 bytes), time= 66.8 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]DC6-9x1Bytes-1           R=  +6.9  p =  8.1e-4   mildly suspicious
  ...and 155 test result(s) without anomalies

rng=RNG_stdin32, seed=0x5e274411
length= 6.000 gigabytes (2^32.585 bytes), time= 100 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]DC6-9x1Bytes-1           R=  +8.9  p =  1.0e-4   suspicious       
  ...and 159 test result(s) without anomalies


real	1m40.773s
user	1m40.094s
sys	0m4.190s
*/
