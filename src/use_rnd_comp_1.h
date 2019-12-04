////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:17:31 CET
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

#include "rnd_comp.h"
#include "rnd_sim_lin.h"

using TRnd = RndComp<RndSimLin01,RndSimLin03,10>;

/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_COMP_1 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1585682339
2494875974
1870629489
3954548876
3038153523
1357523021
4294804113599460716

real	0m10.562s
user	0m10.548s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_COMP_1 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.29e+07  | 479135559|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.10683065|  PASSED  

real	0m1.559s
user	0m1.623s
sys	0m0.092s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_COMP_1 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1585682339
2494875974
1870629489
3954548876
3038153523
1357523021
4294804113599460716

real	0m9.979s
user	0m9.971s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_COMP_1 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.82e+07  |2198056711|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.70288651|  PASSED  

real	0m1.517s
user	0m1.575s
sys	0m0.095s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0xb48378a3
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0xb48378a3
length= 128 megabytes (2^27 bytes), time= 2.2 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0xb48378a3
length= 256 megabytes (2^28 bytes), time= 4.8 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]Gap-16:A                 R=  +5.1  p =  7.5e-4   unusual          
  ...and 123 test result(s) without anomalies

rng=RNG_stdin32, seed=0xb48378a3
length= 512 megabytes (2^29 bytes), time= 9.5 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0xb48378a3
length= 1 gigabyte (2^30 bytes), time= 18.5 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0xb48378a3
length= 2 gigabytes (2^31 bytes), time= 35.8 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0xb48378a3
length= 4 gigabytes (2^32 bytes), time= 69.1 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0xb48378a3
length= 6.000 gigabytes (2^32.585 bytes), time= 104 seconds
  no anomalies in 160 test result(s)


real	1m44.356s
user	1m43.628s
sys	0m4.534s
*/
