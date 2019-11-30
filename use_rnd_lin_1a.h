////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:39:47 CET
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

using TRnd = RndLin1a;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_LIN_1a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2285045470
3732216744
1642583650
4144565644
2925228966
3831314224
4295032697256764416

real	0m6.370s
user	0m6.370s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_LIN_1a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.28e+07  |1747963395|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.00000000|  FAILED  

real	0m1.756s
user	0m1.757s
sys	0m0.089s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_LIN_1a -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
2285045470
3732216744
1642583650
4144565644
2925228966
3831314224
4295032697256764416

real	0m6.065s
user	0m6.064s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_LIN_1a -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.94e+07  |2092334673|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.00000000|  FAILED  

real	0m1.625s
user	0m1.672s
sys	0m0.078s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x854296ea
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x854296ea
length= 256 megabytes (2^28 bytes), time= 3.6 seconds
  Test Name                         Raw       Processed     Evaluation
  BCFN(2+0,13-2,T)                  R=+276781 p = 0           FAIL !!!!!!!!  
  BCFN(2+1,13-2,T)                  R=+281279 p = 0           FAIL !!!!!!!!  
  BCFN(2+2,13-3,T)                  R=+102468 p = 0           FAIL !!!!!!!!  
  BCFN(2+3,13-3,T)                  R=+113474 p = 0           FAIL !!!!!!!!  
  BCFN(2+4,13-3,T)                  R=+105594 p = 0           FAIL !!!!!!!!  
  BCFN(2+5,13-4,T)                  R=+74651  p = 0           FAIL !!!!!!!!  
  BCFN(2+6,13-5,T)                  R=+39515  p = 0           FAIL !!!!!!!!  
  BCFN(2+7,13-5,T)                  R=+48422  p = 0           FAIL !!!!!!!!  
  BCFN(2+8,13-6,T)                  R=+48945  p = 0           FAIL !!!!!!!!  
  BCFN(2+9,13-6,T)                  R=+26732  p =  3e-9155    FAIL !!!!!!!!  
  BCFN(2+10,13-7,T)                 R=+17429  p =  5e-5243    FAIL !!!!!!!!  
  BCFN(2+11,13-8,T)                 R=+10189  p =  7e-2587    FAIL !!!!!!!!  
  BCFN(2+12,13-8,T)                 R= +9183  p =  2e-2331    FAIL !!!!!!!!  
  BCFN(2+13,13-9,T)                 R= +5852  p =  4e-1316    FAIL !!!!!!!!  
  BCFN(2+14,13-9,T)                 R= +4382  p =  1.1e-985   FAIL !!!!!!!   
  DC6-9x1Bytes-1                    R=+771982 p = 0           FAIL !!!!!!!!  
  Gap-16:A                          R=+7323645 p = 0           FAIL !!!!!!!!  
  Gap-16:B                          R=+27088757 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(0,14-0)              R=-128.0  p =1-2.4e-117   FAIL !!!!!     
  FPF-14+6/16:(1,14-0)              R=-128.0  p =1-2.4e-117   FAIL !!!!!     
  FPF-14+6/16:(2,14-0)              R=+181582 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(3,14-0)              R=+181582 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(4,14-1)              R=+128402 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(5,14-2)              R=+90799  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(6,14-2)              R=+68083  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(7,14-3)              R=+48148  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(8,14-4)              R=+34054  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(9,14-5)              R=+24092  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(10,14-5)             R=+16054  p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:(11,14-6)             R=+11363  p =  1e-8695    FAIL !!!!!!!!  
  FPF-14+6/16:(12,14-7)             R= +8051  p =  4e-6407    FAIL !!!!!!!!  
  FPF-14+6/16:(13,14-8)             R= +5715  p =  1e-4112    FAIL !!!!!!!!  
  FPF-14+6/16:(14,14-8)             R= +3569  p =  2e-2568    FAIL !!!!!!!!  
  FPF-14+6/16:(15,14-9)             R= +2544  p =  3e-1602    FAIL !!!!!!!!  
  FPF-14+6/16:(16,14-10)            R= +2928  p =  1e-1558    FAIL !!!!!!!!  
  FPF-14+6/16:all                   R=+247380 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:all2                  R=+23737368589 p = 0           FAIL !!!!!!!!  
  FPF-14+6/16:cross                 R=+434.8  p =  3.3e-366   FAIL !!!!!!!   
  BRank(12):128(4)                  R= +1942  p~=  1e-1033    FAIL !!!!!!!!  
  BRank(12):256(4)                  R= +5386  p~=  2e-2865    FAIL !!!!!!!!  
  BRank(12):384(1)                  R= +3834  p~=  3e-1155    FAIL !!!!!!!!  
  BRank(12):512(2)                  R= +9562  p~=  1e-2879    FAIL !!!!!!!!  
  BRank(12):768(1)                  R= +9862  p~=  1e-2969    FAIL !!!!!!!!  
  BRank(12):1K(2)                   R=+23232  p~=  1e-6994    FAIL !!!!!!!!  
  BRank(12):1536(1)                 R=+23983  p~=  9e-7221    FAIL !!!!!!!!  
  BRank(12):2K(1)                   R=+38493  p~= 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+0,13-3,T)         R=+3522264 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+1,13-3,T)         R=+3138999 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+2,13-4,T)         R=+2087780 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+3,13-4,T)         R=+1076274 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+4,13-5,T)         R=+691826 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+5,13-5,T)         R=+351162 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+6,13-6,T)         R=+220019 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+7,13-6,T)         R=+110827 p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+8,13-7,T)         R=+67788  p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+9,13-8,T)         R=+40408  p = 0           FAIL !!!!!!!!  
  [Low8/32]BCFN(2+10,13-8,T)        R=+20247  p =  2e-5139    FAIL !!!!!!!!  
  [Low8/32]BCFN(2+11,13-9,T)        R=+11655  p =  4e-2620    FAIL !!!!!!!!  
  [Low8/32]BCFN(2+12,13-9,T)        R= +5825  p =  5e-1310    FAIL !!!!!!!!  
  [Low8/32]DC6-9x1Bytes-1           R=+2028686 p = 0           FAIL !!!!!!!!  
  [Low8/32]Gap-16:A                 R=+1943829 p = 0           FAIL !!!!!!!!  
  [Low8/32]Gap-16:B                 R=+8554071 p = 0           FAIL !!!!!!!!  
  [Low8/32]FPF-14+6/16:(0,14-0)     R=+2907230 p = 0           FAIL !!!!!!!!  
  [Low8/32]FPF-14+6/16:all          R=+3270650 p = 0           FAIL !!!!!!!!  
  [Low8/32]FPF-14+6/16:cross        R=+7545940 p = 0           FAIL !!!!!!!!  
  [Low8/32]BRank(12):128(4)         R= +5085  p~=  4e-2705    FAIL !!!!!!!!  
  [Low8/32]BRank(12):256(2)         R= +7553  p~=  1e-2274    FAIL !!!!!!!!  
  [Low8/32]BRank(12):384(1)         R= +8053  p~=  2e-2425    FAIL !!!!!!!!  
  [Low8/32]BRank(12):512(2)         R=+15377  p~=  5e-4630    FAIL !!!!!!!!  
  [Low8/32]BRank(12):768(1)         R=+16363  p~=  1e-4926    FAIL !!!!!!!!  
  [Low8/32]BRank(12):1K(1)          R=+21917  p~=  1e-6598    FAIL !!!!!!!!  
  [Low1/32]BCFN(2+0,13-5,T)         R=+1181228 p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+1,13-5,T)         R=+628706 p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+2,13-6,T)         R=+407139 p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+3,13-6,T)         R=+209877 p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+4,13-6,T)         R=+107204 p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+5,13-7,T)         R=+66218  p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+6,13-8,T)         R=+39745  p = 0           FAIL !!!!!!!!  
  [Low1/32]BCFN(2+7,13-8,T)         R=+20012  p =  8e-5080    FAIL !!!!!!!!  
  [Low1/32]BCFN(2+8,13-9,T)         R=+11560  p =  1e-2598    FAIL !!!!!!!!  
  [Low1/32]BCFN(2+9,13-9,T)         R= +5791  p =  2e-1302    FAIL !!!!!!!!  
  [Low1/32]DC6-9x1Bytes-1           R=+868131 p = 0           FAIL !!!!!!!!  
  [Low1/32]Gap-16:A                 R=+354161 p = 0           FAIL !!!!!!!!  
  [Low1/32]Gap-16:B                 R=+1690856 p = 0           FAIL !!!!!!!!  
  [Low1/32]FPF-14+6/16:(0,14-2)     R=+1090294 p = 0           FAIL !!!!!!!!  
  [Low1/32]FPF-14+6/16:all          R=+1181158 p = 0           FAIL !!!!!!!!  
  [Low1/32]FPF-14+6/16:cross        R=+1027871 p = 0           FAIL !!!!!!!!  
  [Low1/32]BRank(12):128(2)         R= +3717  p~=  5e-1120    FAIL !!!!!!!!  
  [Low1/32]BRank(12):256(2)         R= +7614  p~=  4e-2293    FAIL !!!!!!!!  
  [Low1/32]BRank(12):384(1)         R= +8139  p~=  3e-2451    FAIL !!!!!!!!  
  [Low1/32]BRank(12):512(1)         R=+10895  p~=  1e-3280    FAIL !!!!!!!!  


real	0m4.203s
user	0m4.102s
sys	0m0.227s
*/
