////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:20:38 CET
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

using TRnd = RndFib2;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_2 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1604262765
3422254557
378000469
1617572592
4148197001
84671980
4295035468693037909

real	0m5.959s
user	0m5.933s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_2 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  2.39e+07  |3114706417|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.14013592|  PASSED  

real	0m1.839s
user	0m1.791s
sys	0m0.131s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_2 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1604262765
3422254557
378000469
1617572592
4148197001
84671980
4295035468693037909

real	0m5.210s
user	0m5.203s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_2 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.50e+07  |1534281438|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.98975811|  PASSED  

real	0m1.551s
user	0m1.599s
sys	0m0.074s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x9be33fce
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x9be33fce
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x9be33fce
length= 256 megabytes (2^28 bytes), time= 4.6 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x9be33fce
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x9be33fce
length= 1 gigabyte (2^30 bytes), time= 17.9 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x9be33fce
length= 2 gigabytes (2^31 bytes), time= 34.5 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0x9be33fce
length= 4 gigabytes (2^32 bytes), time= 66.4 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+7,13-3,T)                  R=  -8.6  p =1-5.7e-5   unusual          
  [Low1/32]BCFN(2+2,13-3,T)         R=  +7.7  p =  1.9e-3   unusual          
  ...and 154 test result(s) without anomalies

rng=RNG_stdin32, seed=0x9be33fce
length= 6.250 gigabytes (2^32.644 bytes), time= 103 seconds
  no anomalies in 160 test result(s)


real	1m44.028s
user	1m43.114s
sys	0m4.416s
*/
