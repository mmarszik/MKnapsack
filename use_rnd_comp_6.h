////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:18:30 CET
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
#include "rnd_fib.h"

using TRnd = RndComp< RndFib2a, RndFib3a, 9 >;

/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_COMP_6 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1871541365
3259764588
258764547
23779551
2346585856
1841442965
4294988645538604930

real	0m9.810s
user	0m9.796s
sys	0m0.008s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_COMP_6 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.27e+07  | 486752164|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.49034540|  PASSED  

real	0m1.649s
user	0m1.744s
sys	0m0.077s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_COMP_6 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1871541365
3259764588
258764547
23779551
2346585856
1841442965
4294988645538604930

real	0m9.347s
user	0m9.347s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_COMP_6 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.45e+07  |2053236375|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.44897892|  PASSED  

real	0m1.534s
user	0m1.644s
sys	0m0.075s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x5c882640
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x5c882640
length= 128 megabytes (2^27 bytes), time= 2.2 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x5c882640
length= 256 megabytes (2^28 bytes), time= 4.9 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x5c882640
length= 512 megabytes (2^29 bytes), time= 9.6 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x5c882640
length= 1 gigabyte (2^30 bytes), time= 18.7 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x5c882640
length= 2 gigabytes (2^31 bytes), time= 36.1 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0x5c882640
length= 4 gigabytes (2^32 bytes), time= 69.8 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+2,13-3,T)         R=  +8.2  p =  1.1e-3   unusual          
  ...and 155 test result(s) without anomalies

rng=RNG_stdin32, seed=0x5c882640
length= 5.750 gigabytes (2^32.524 bytes), time= 100 seconds
  Test Name                         Raw       Processed     Evaluation
  FPF-14+6/16:all                   R=  -4.1  p =1-1.4e-3   unusual          
  [Low1/32]BCFN(2+2,13-3,T)         R=  +9.3  p =  3.2e-4   unusual          
  ...and 158 test result(s) without anomalies


real	1m40.832s
user	1m40.292s
sys	0m4.350s
*/
