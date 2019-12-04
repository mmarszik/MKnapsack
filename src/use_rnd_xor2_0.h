////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:42:34 CET
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

#include "rnd_xor2.h"
#include "rnd_mlin.h"

using TRnd = RndXor2<RndMLin,5039,5153>;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_XOR2_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2945246887
3148472406
132787248
553583649
1936233892
519926911
4295706095383292653

real	0m3.118s
user	0m3.117s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_XOR2_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.51e+07  |4093564418|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.17049185|  PASSED  

real	0m1.549s
user	0m1.598s
sys	0m0.066s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_XOR2_0 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2945246887
3148472406
132787248
553583649
1936233892
519926911
4295706095383292653

real	0m3.243s
user	0m3.238s
sys	0m0.004s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_XOR2_0 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.87e+07  | 364491685|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.11211465|  PASSED  

real	0m1.525s
user	0m1.568s
sys	0m0.069s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0xb24f64d8
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0xb24f64d8
length= 128 megabytes (2^27 bytes), time= 2.0 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+0,13-3,T)                  R= +18.9  p =  9.5e-9    VERY SUSPICIOUS 
  DC6-9x1Bytes-1                    R=+167.8  p =  1.1e-102   FAIL !!!!!     
  Gap-16:A                          R=+246.8  p =  5.8e-210   FAIL !!!!!!    
  Gap-16:B                          R= +81.9  p =  1.2e-65    FAIL !!!!      
  FPF-14+6/16:(0,14-0)              R= +57.4  p =  1.0e-52    FAIL !!!!      
  FPF-14+6/16:(1,14-0)              R= +55.6  p =  4.3e-51    FAIL !!!!      
  FPF-14+6/16:(2,14-0)              R= +58.0  p =  2.4e-53    FAIL !!!!      
  FPF-14+6/16:(3,14-1)              R= +40.5  p =  1.2e-35    FAIL !!!       
  FPF-14+6/16:(4,14-2)              R= +29.2  p =  2.7e-25    FAIL !!        
  FPF-14+6/16:(5,14-2)              R= +29.6  p =  1.0e-25    FAIL !!        
  FPF-14+6/16:(6,14-3)              R= +22.9  p =  7.5e-20    FAIL !         
  FPF-14+6/16:(7,14-4)              R= +14.9  p =  4.3e-12   VERY SUSPICIOUS 
  FPF-14+6/16:(8,14-5)              R=  +8.2  p =  1.1e-6   mildly suspicious
  FPF-14+6/16:(9,14-5)              R= +13.6  p =  3.7e-11   VERY SUSPICIOUS 
  FPF-14+6/16:all                   R=+119.2  p =  2.5e-111   FAIL !!!!!     
  FPF-14+6/16:all2                  R= +3058  p =  2e-1143    FAIL !!!!!!!!  
  [Low8/32]DC6-9x1Bytes-1           R=+137.0  p =  2.0e-91    FAIL !!!!!     
  [Low8/32]Gap-16:A                 R= +28.3  p =  9.1e-23    FAIL !!        
  [Low8/32]Gap-16:B                 R=  +5.6  p =  1.2e-4   mildly suspicious
  [Low1/32]DC6-9x1Bytes-1           R= +11.7  p =  2.3e-6   very suspicious  
  [Low1/32]Gap-16:A                 R= +34.2  p =  4.1e-27    FAIL !!        
  [Low1/32]Gap-16:B                 R=  +7.1  p =  1.4e-5   suspicious       
  ...and 95 test result(s) without anomalies


real	0m2.633s
user	0m2.598s
sys	0m0.102s
*/
