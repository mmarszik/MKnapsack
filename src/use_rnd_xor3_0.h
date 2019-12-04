////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:42:42 CET
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

#include "rnd_xor3.h"
#include "rnd_mlin.h"

using TRnd = RndXor3<RndMLin, 3607, 3613, 3617>;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_XOR3_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2860295208
2651868681
4124792717
71049020
153255624
261019509
4294953853142971002

real	0m3.457s
user	0m3.456s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_XOR3_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.76e+07  |2574738568|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.58727791|  PASSED  

real	0m1.523s
user	0m1.541s
sys	0m0.090s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_XOR3_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2860295208
2651868681
4124792717
71049020
153255624
261019509
4294953853142971002

real	0m3.560s
user	0m3.559s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_XOR3_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.94e+07  |1059906028|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.74925935|  PASSED  

real	0m1.501s
user	0m1.572s
sys	0m0.058s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0xdb99e148
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0xdb99e148
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0xdb99e148
length= 256 megabytes (2^28 bytes), time= 4.6 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0xdb99e148
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  Test Name                         Raw       Processed     Evaluation
  DC6-9x1Bytes-1                    R=  +6.2  p =  2.1e-3   unusual          
  [Low8/32]Gap-16:A                 R=  -4.0  p =1-9.1e-4   unusual          
  ...and 130 test result(s) without anomalies

rng=RNG_stdin32, seed=0xdb99e148
length= 1 gigabyte (2^30 bytes), time= 17.8 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0xdb99e148
length= 2 gigabytes (2^31 bytes), time= 34.1 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]Gap-16:B                 R=  +4.7  p =  5.3e-4   unusual          
  ...and 147 test result(s) without anomalies

rng=RNG_stdin32, seed=0xdb99e148
length= 4 gigabytes (2^32 bytes), time= 65.5 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0xdb99e148
length= 6.000 gigabytes (2^32.585 bytes), time= 101 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]Gap-16:B                 R=  +4.8  p =  4.9e-4   unusual          
  ...and 159 test result(s) without anomalies


real	1m41.419s
user	1m40.473s
sys	0m4.201s
*/
