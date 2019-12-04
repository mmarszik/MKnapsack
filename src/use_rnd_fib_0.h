////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:18:52 CET
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

using TRnd = RndFib0;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
753734251
3857031821
745688813
662591381
2862306613
3243338222
4294880584189149868

real	0m6.007s
user	0m5.985s
sys	0m0.008s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.69e+07  |  76594875|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.85486353|  PASSED  

real	0m1.675s
user	0m1.719s
sys	0m0.086s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_FIB_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
753734251
3857031821
745688813
662591381
2862306613
3243338222
4294880584189149868

real	0m5.781s
user	0m5.780s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_FIB_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.81e+07  |3527086115|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.82116727|  PASSED  

real	0m1.517s
user	0m1.535s
sys	0m0.112s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x32df236a
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x32df236a
length= 128 megabytes (2^27 bytes), time= 2.1 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x32df236a
length= 256 megabytes (2^28 bytes), time= 4.7 seconds
  no anomalies in 124 test result(s)

rng=RNG_stdin32, seed=0x32df236a
length= 512 megabytes (2^29 bytes), time= 9.3 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-5,T)         R= +17.2  p =  6.6e-7   very suspicious  
  [Low1/32]DC6-9x1Bytes-1           R=  +5.6  p =  6.9e-3   unusual          
  ...and 130 test result(s) without anomalies

rng=RNG_stdin32, seed=0x32df236a
length= 1 gigabyte (2^30 bytes), time= 18.0 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]BCFN(2+0,13-4,T)         R= +24.5  p =  1.1e-10   VERY SUSPICIOUS 
  [Low1/32]BCFN(2+2,13-5,T)         R=  +8.7  p =  1.5e-3   unusual          
  [Low1/32]DC6-9x1Bytes-1           R= +11.3  p =  7.9e-7   very suspicious  
  ...and 138 test result(s) without anomalies

rng=RNG_stdin32, seed=0x32df236a
length= 2 gigabytes (2^31 bytes), time= 34.8 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]BCFN(2+1,13-1,T)         R= +19.6  p =  5.4e-10   VERY SUSPICIOUS 
  [Low8/32]BCFN(2+2,13-2,T)         R=  +8.2  p =  8.4e-4   unusual          
  [Low1/32]BCFN(2+0,13-3,T)         R= +38.5  p =  5.0e-18    FAIL !         
  [Low1/32]DC6-9x1Bytes-1           R= +18.4  p =  4.4e-11    FAIL           
  ...and 144 test result(s) without anomalies


real	0m35.494s
user	0m35.184s
sys	0m1.498s
*/
