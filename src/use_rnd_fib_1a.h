////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:20:27 CET
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

using TRnd = RndFib1a;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_1a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4217143007
2263514851
3622271318
4017173772
731841040
1586642232
4294971933820452478

real	0m7.422s
user	0m7.284s
sys	0m0.076s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_1a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  2.94e+07  |3186357732|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.60973025|  PASSED  

real	0m1.783s
user	0m1.796s
sys	0m0.111s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_1a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
4217143007
2263514851
3622271318
4017173772
731841040
1586642232
4294971933820452478

real	0m5.945s
user	0m5.943s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_1a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.70e+07  |2589462177|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.90768960|  PASSED  

real	0m1.528s
user	0m1.579s
sys	0m0.080s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0xc7bd3688
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0xc7bd3688
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0xc7bd3688
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0xc7bd3688
length= 512 megabytes (2^29 bytes), time= 9.2 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-5,T)         R= +11.2  p =  1.4e-4   mildly suspicious
  ...and 131 test result(s) without anomalies

rng=RNG_stdin32, seed=0xc7bd3688
length= 1 gigabyte (2^30 bytes), time= 18.1 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-4,T)         R=  +8.1  p =  1.8e-3   unusual          
  ...and 140 test result(s) without anomalies

rng=RNG_stdin32, seed=0xc7bd3688
length= 2 gigabytes (2^31 bytes), time= 34.8 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-3,T)         R= +10.8  p =  6.3e-5   mildly suspicious
  [Low1/32]BCFN(2+2,13-4,T)         R=  +9.0  p =  7.3e-4   unusual          
  [Low1/32]DC6-9x1Bytes-1           R=  +6.3  p =  2.1e-3   unusual          
  ...and 145 test result(s) without anomalies

rng=RNG_stdin32, seed=0xc7bd3688
length= 4 gigabytes (2^32 bytes), time= 67.2 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-3,T)         R= +23.0  p =  1.1e-10   VERY SUSPICIOUS 
  [Low1/32]BCFN(2+2,13-3,T)         R= +13.0  p =  6.1e-6   suspicious       
  [Low1/32]DC6-9x1Bytes-1           R=  +5.5  p =  5.7e-3   unusual          
  ...and 153 test result(s) without anomalies

rng=RNG_stdin32, seed=0xc7bd3688
length= 6.000 gigabytes (2^32.585 bytes), time= 100 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-2,T)         R= +29.1  p =  1.7e-14    FAIL !         
  [Low1/32]BCFN(2+2,13-3,T)         R= +19.4  p =  5.8e-9    VERY SUSPICIOUS 
  [Low1/32]BCFN(2+3,13-3,T)         R= +13.8  p =  2.4e-6   suspicious       
  [Low1/32]DC6-9x1Bytes-1           R=  +7.8  p =  4.1e-4   mildly suspicious
  ...and 156 test result(s) without anomalies


real	1m40.808s
user	1m40.049s
sys	0m4.231s
*/
