////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:21:41 CET
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

#include <random>

using TRnd = std::knuth_b;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_KNUTH_B -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
414632433
529571054
23691585
633705974
277539866
1155212522
2147477490070430930

real	0m35.935s
user	0m35.867s
sys	0m0.028s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_KNUTH_B -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.58e+07  |3892013017|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.24515659|  PASSED  

real	0m1.665s
user	0m1.875s
sys	0m0.090s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_KNUTH_B -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
414632433
529571054
23691585
633705974
277539866
1155212522
2147477490070430930

real	0m34.499s
user	0m34.469s
sys	0m0.020s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_KNUTH_B -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.81e+07  |1829820726|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.51340150|  PASSED  

real	0m1.510s
user	0m1.760s
sys	0m0.051s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x7562041b
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x7562041b
length= 128 megabytes (2^27 bytes), time= 2.5 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+0,13-3,T)                  R=+207196 p = 0           FAIL !!!!!!!!  
  BCFN(2+1,13-3,T)                  R=+211616 p = 0           FAIL !!!!!!!!  
  BCFN(2+2,13-3,T)                  R=+210539 p = 0           FAIL !!!!!!!!  
  BCFN(2+3,13-3,T)                  R=+206256 p = 0           FAIL !!!!!!!!  
  BCFN(2+4,13-4,T)                  R=+248724 p = 0           FAIL !!!!!!!!  
  BCFN(2+5,13-5,T)                  R=+280856 p = 0           FAIL !!!!!!!!  
  BCFN(2+6,13-5,T)                  R=+227642 p = 0           FAIL !!!!!!!!  
  BCFN(2+7,13-6,T)                  R=+194982 p = 0           FAIL !!!!!!!!  
  BCFN(2+8,13-6,T)                  R=+111974 p = 0           FAIL !!!!!!!!  
  BCFN(2+9,13-7,T)                  R=+69242  p = 0           FAIL !!!!!!!!  
  BCFN(2+10,13-8,T)                 R=+41033  p = 0           FAIL !!!!!!!!  
  BCFN(2+11,13-8,T)                 R=+20468  p =  1e-5195    FAIL !!!!!!!!  
  BCFN(2+12,13-9,T)                 R=+11745  p =  3e-2640    FAIL !!!!!!!!  
  BCFN(2+13,13-9,T)                 R= +5857  p =  4e-1317    FAIL !!!!!!!!  
  DC6-9x1Bytes-1                    R=+21769  p = 0           FAIL !!!!!!!!  
  Gap-16:A                          R= +9764  p =  1e-8325    FAIL !!!!!!!!  
  Gap-16:B                          R=+48346  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(1,14-0)              R=+34307  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(2,14-0)              R=+17135  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(3,14-1)              R=+12135  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(4,14-2)              R= +8573  p =  1e-7497    FAIL !!!!!!!!  
  FPF-14+6/16:(5,14-2)              R= +4298  p =  2e-3758    FAIL !!!!!!!!  
  FPF-14+6/16:(6,14-3)              R= +3032  p =  1e-2657    FAIL !!!!!!!!  
  FPF-14+6/16:(7,14-4)              R= +2142  p =  2e-1750    FAIL !!!!!!!!  
  FPF-14+6/16:(8,14-5)              R= +1530  p =  1e-1268    FAIL !!!!!!!!  
  FPF-14+6/16:(9,14-5)              R=+750.4  p =  5.9e-622   FAIL !!!!!!!   
  FPF-14+6/16:(10,14-6)             R=+538.6  p =  3.1e-412   FAIL !!!!!!!   
  FPF-14+6/16:(11,14-7)             R=+383.7  p =  3.1e-305   FAIL !!!!!!    
  FPF-14+6/16:(12,14-8)             R=+269.5  p =  6.0e-194   FAIL !!!!!!    
  FPF-14+6/16:(13,14-8)             R=+124.9  p =  6.7e-90    FAIL !!!!!     
  FPF-14+6/16:(14,14-9)             R= +92.2  p =  2.2e-58    FAIL !!!!      
  FPF-14+6/16:all                   R=+33136  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:all2                  R=+407330823 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:cross                 R= +74.1  p =  1.0e-62    FAIL !!!!      
  BRank(12):128(4)                  R= +29.5  p~=  1.8e-16    FAIL !         
  BRank(12):256(4)                  R=+137.8  p~=  4.0e-74    FAIL !!!!      
  BRank(12):384(1)                  R=+152.8  p~=  5.1e-47    FAIL !!!       
  BRank(12):512(2)                  R=+337.8  p~=  1.0e-102   FAIL !!!!!     
  BRank(12):768(1)                  R=+411.1  p~=  8.8e-125   FAIL !!!!!     
  BRank(12):1K(2)                   R=+824.9  p~=  2.3e-249   FAIL !!!!!!    
  BRank(12):1536(1)                 R=+927.7  p~=  2.6e-280   FAIL !!!!!!    
  ...and 76 test result(s) without anomalies


real	0m3.080s
user	0m3.030s
sys	0m0.155s
*/
