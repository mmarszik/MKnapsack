////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:19:51 CET
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

using TRnd = RndFib1;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_1 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2772671560
1230292352
3182881147
2748660412
3615175996
2860307554
4294968812687182211

real	0m5.419s
user	0m5.418s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_1 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.92e+07  |1330649558|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.85146190|  PASSED  

real	0m1.520s
user	0m1.555s
sys	0m0.086s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_1 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2772671560
1230292352
3182881147
2748660412
3615175996
2860307554
4294968812687182211

real	0m5.391s
user	0m5.390s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_1 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.35e+07  |2188895277|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.22047162|  PASSED  

real	0m1.565s
user	0m1.603s
sys	0m0.081s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x15051da4
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x15051da4
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  Test Name                         Raw       Processed     Evaluation
  DC6-9x1Bytes-1                    R=  -4.7  p =1-2.3e-3   unusual          
  [Low8/32]BCFN(2+2,13-5,T)         R=  +9.3  p =  8.1e-4   unusual          
  ...and 115 test result(s) without anomalies

rng=RNG_stdin32, seed=0x15051da4
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]BCFN(2+2,13-4,T)         R= +18.5  p =  4.9e-8   very suspicious  
  [Low8/32]DC6-9x1Bytes-1           R=  +5.7  p =  5.1e-3   unusual          
  ...and 122 test result(s) without anomalies

rng=RNG_stdin32, seed=0x15051da4
length= 512 megabytes (2^29 bytes), time= 9.3 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]BCFN(2+2,13-3,T)         R= +33.1  p =  1.9e-15    FAIL !         
  [Low8/32]BCFN(2+3,13-3,T)         R=  +8.9  p =  5.0e-4   unusual          
  [Low1/32]BCFN(2+0,13-5,T)         R= +10.4  p =  3.0e-4   mildly suspicious
  ...and 129 test result(s) without anomalies


real	0m9.937s
user	0m9.772s
sys	0m0.468s
*/
