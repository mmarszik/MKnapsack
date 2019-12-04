////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:41:21 CET
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

#include "rnd_sfib.h"

using TRnd = RndSFib0;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SFIB_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1709448209
2412023039
3605789886
2820342608
3057952285
1386997744
4294925997034534133

real	0m5.928s
user	0m5.904s
sys	0m0.012s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SFIB_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.29e+07  |1215728716|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.59857846|  PASSED  

real	0m1.711s
user	0m1.717s
sys	0m0.103s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SFIB_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1709448209
2412023039
3605789886
2820342608
3057952285
1386997744
4294925997034534133

real	0m5.265s
user	0m5.264s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SFIB_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.68e+07  | 718883396|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.93243259|  PASSED  

real	0m1.526s
user	0m1.578s
sys	0m0.065s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x620ae357
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x620ae357
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x620ae357
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x620ae357
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x620ae357
length= 1 gigabyte (2^30 bytes), time= 18.0 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x620ae357
length= 2 gigabytes (2^31 bytes), time= 34.7 seconds
  Test Name                         Raw       Processed     Evaluation
  DC6-9x1Bytes-1                    R=  -4.7  p =1-3.0e-3   unusual          
  ...and 147 test result(s) without anomalies

rng=RNG_stdin32, seed=0x620ae357
length= 4 gigabytes (2^32 bytes), time= 67.0 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0x620ae357
length= 6.000 gigabytes (2^32.585 bytes), time= 100 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]DC6-9x1Bytes-1           R=  -3.6  p = 0.989     unusual          
  ...and 159 test result(s) without anomalies


real	1m40.986s
user	1m40.332s
sys	0m4.185s
*/
