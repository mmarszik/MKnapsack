////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:21:20 CET
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

using TRnd = RndFib3a;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_3a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4066514869
1812893915
3534851474
3109044887
4264217481
3757052325
4294977872820730953

real	0m6.361s
user	0m6.338s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_3a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.25e+07  | 982869578|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.93578310|  PASSED  

real	0m1.710s
user	0m1.742s
sys	0m0.072s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_3a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4066514869
1812893915
3534851474
3109044887
4264217481
3757052325
4294977872820730953

real	0m5.802s
user	0m5.799s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_3a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.57e+07  |2650073799|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.30206087|  PASSED  

real	0m1.536s
user	0m1.536s
sys	0m0.121s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x84af3c61
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x84af3c61
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]Gap-16:B                 R=  -4.4  p =1-1.0e-3   unusual          
  ...and 116 test result(s) without anomalies

rng=RNG_stdin32, seed=0x84af3c61
length= 256 megabytes (2^28 bytes), time= 4.6 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x84af3c61
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  no anomalies in 132 test result(s)

rng=RNG_stdin32, seed=0x84af3c61
length= 1 gigabyte (2^30 bytes), time= 17.8 seconds
  no anomalies in 141 test result(s)

rng=RNG_stdin32, seed=0x84af3c61
length= 2 gigabytes (2^31 bytes), time= 34.5 seconds
  no anomalies in 148 test result(s)

rng=RNG_stdin32, seed=0x84af3c61
length= 4 gigabytes (2^32 bytes), time= 66.7 seconds
  no anomalies in 156 test result(s)

rng=RNG_stdin32, seed=0x84af3c61
length= 6.250 gigabytes (2^32.644 bytes), time= 104 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+0,13-0,T)                  R=  -7.0  p =1-1.7e-3   unusual          
  ...and 159 test result(s) without anomalies


real	1m44.456s
user	1m43.905s
sys	0m4.215s
*/
