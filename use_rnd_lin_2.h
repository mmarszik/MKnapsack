////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:39:58 CET
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

using TRnd = RndLin2;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_LIN_2 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
3497841202
67965748
527131255
182892387
247477018
3100051826
4294841257269238130

real	0m12.465s
user	0m12.453s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_LIN_2 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.50e+07  |1704645451|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.32824235|  PASSED  

real	0m1.577s
user	0m1.684s
sys	0m0.036s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_LIN_2 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
3497841202
67965748
527131255
182892387
247477018
3100051826
4294841257269238130

real	0m12.172s
user	0m12.169s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_LIN_2 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.25e+07  |2172239745|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.15544655|  PASSED  

real	0m1.568s
user	0m1.634s
sys	0m0.084s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x4b9cf2bc
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 128 megabytes (2^27 bytes), time= 2.2 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]BCFN(2+0,13-4,T)         R=  -6.6  p =1-8.4e-4   unusual          
  ...and 116 test result(s) without anomalies

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 256 megabytes (2^28 bytes), time= 4.9 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 512 megabytes (2^29 bytes), time= 9.6 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 1 gigabyte (2^30 bytes), time= 18.7 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 2 gigabytes (2^31 bytes), time= 36.3 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+3,13-4,T)         R=  +9.5  p =  4.3e-4   unusual          
  ...and 147 test result(s) without anomalies

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 4 gigabytes (2^32 bytes), time= 70.0 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0x4b9cf2bc
length= 5.750 gigabytes (2^32.524 bytes), time= 101 seconds
  no anomalies in 160 test result(s)


real	1m41.339s
user	1m40.896s
sys	0m4.083s
*/
