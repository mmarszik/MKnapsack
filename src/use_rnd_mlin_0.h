////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:40:51 CET
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

#include "rnd_mlin.h"

using TRnd = RndMLin;

/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_MLIN_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4047791457
2956040780
2354895468
615566559
509964485
1074584509
4294986094170084852

real	0m5.752s
user	0m5.747s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_MLIN_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.63e+07  |3533611936|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.30958926|  PASSED  

real	0m1.557s
user	0m1.603s
sys	0m0.086s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_MLIN_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4047791457
2956040780
2354895468
615566559
509964485
1074584509
4294986094170084852

real	0m5.202s
user	0m5.192s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_MLIN_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.73e+07  |1804837287|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.19185960|  PASSED  

real	0m1.518s
user	0m1.554s
sys	0m0.088s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0xf9b914e5
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0xf9b914e5
length= 128 megabytes (2^27 bytes), time= 2.0 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0xf9b914e5
length= 256 megabytes (2^28 bytes), time= 4.6 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0xf9b914e5
length= 512 megabytes (2^29 bytes), time= 9.0 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0xf9b914e5
length= 1 gigabyte (2^30 bytes), time= 17.5 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0xf9b914e5
length= 2 gigabytes (2^31 bytes), time= 33.7 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+5,13-2,T)                  R=  -7.9  p =1-2.7e-4   unusual          
  ...and 147 test result(s) without anomalies

rng=RNG_stdin32, seed=0xf9b914e5
length= 4 gigabytes (2^32 bytes), time= 65.1 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0xf9b914e5
length= 6.250 gigabytes (2^32.644 bytes), time= 101 seconds
  no anomalies in 160 test result(s)


real	1m41.793s
user	1m41.062s
sys	0m4.273s
*/
