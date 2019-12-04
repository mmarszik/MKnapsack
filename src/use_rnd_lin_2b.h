////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:40:18 CET
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

#include "rnd_lin.h"

using TRnd = RndLin2b;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_LIN_2b -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4081487542
2598378608
2001728541
3754126217
2651817580
3324873846
4294938331291636862

real	0m36.901s
user	0m36.868s
sys	0m0.016s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_LIN_2b -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.65e+07  |1911970825|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.41468559|  PASSED  

real	0m1.557s
user	0m1.853s
sys	0m0.036s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_LIN_2b -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4081487542
2598378608
2001728541
3754126217
2651817580
3324873846
4294938331291636862

real	0m36.278s
user	0m36.259s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_LIN_2b -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.82e+07  | 295971573|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.53534463|  PASSED  

real	0m1.531s
user	0m1.824s
sys	0m0.047s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x6316b88e
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x6316b88e
length= 128 megabytes (2^27 bytes), time= 2.5 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x6316b88e
length= 256 megabytes (2^28 bytes), time= 5.6 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x6316b88e
length= 512 megabytes (2^29 bytes), time= 11.0 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x6316b88e
length= 1 gigabyte (2^30 bytes), time= 21.5 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x6316b88e
length= 2 gigabytes (2^31 bytes), time= 41.8 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0x6316b88e
length= 4 gigabytes (2^32 bytes), time= 81.1 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0x6316b88e
length= 5.000 gigabytes (2^32.322 bytes), time= 101 seconds
  no anomalies in 159 test result(s)


real	1m41.740s
user	1m42.563s
sys	0m3.597s
*/
