////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Genetic Algorithm to Multi-Knapsack Problem
///
/// Created on sob, 30 lis 2019, 09:41:51 CET
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

#include "rnd_sim_lin.h"

using TRnd = RndSimLin02;
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_02 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1889262655
331459241
3829589973
902451912
3434156384
458466171
4294973935371160060

real	0m3.043s
user	0m3.042s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_02 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.94e+07  |3026802783|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.84701874|  PASSED  

real	0m1.496s
user	0m1.519s
sys	0m0.077s
*/
/* TEST00
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_02 -DTEST00_PROGRAM *.cpp -o mknapsack 
time ./mknapsack 
1889262655
331459241
3829589973
902451912
3434156384
458466171
4294973935371160060

real	0m3.036s
user	0m3.035s
sys	0m0.000s
*/
/* TEST01
c++ -std=c++11 -O3 -DUSE_RND_SIM_LIN_02 -DTEST01_PROGRAM *.cpp -o mknapsack
time ./mknapsack | dieharder -g200 -a -k2 
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |rands/second|   Seed   |
stdin_input_raw|  3.56e+07  | 318601405|
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.99687884|   WEAK   

real	0m1.540s
user	0m1.547s
sys	0m0.086s
*/
/* TEST01
time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 100s 
RNG_test using PractRand version 0.93
RNG = RNG_stdin32, seed = 0x5d9a533f
test set = normal, folding = standard (32 bit)

rng=RNG_stdin32, seed=0x5d9a533f
length= 128 megabytes (2^27 bytes), time= 2.0 seconds
  no anomalies in 117 test result(s)

rng=RNG_stdin32, seed=0x5d9a533f
length= 256 megabytes (2^28 bytes), time= 4.5 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low1/32]FPF-14+6/16:all2         R=  +7.0  p =  4.3e-4   unusual          
  ...and 123 test result(s) without anomalies

rng=RNG_stdin32, seed=0x5d9a533f
length= 512 megabytes (2^29 bytes), time= 9.0 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]Gap-16:A                 R=  +4.4  p =  2.9e-3   unusual          
  [Low1/32]BCFN(2+2,13-5,T)         R=  -6.2  p =1-1.0e-3   unusual          
  [Low1/32]FPF-14+6/16:(1,14-2)     R=  +6.8  p =  1.1e-5   unusual          
  [Low1/32]FPF-14+6/16:all          R=  +9.4  p =  2.9e-8   very suspicious  
  [Low1/32]FPF-14+6/16:all2         R= +13.1  p =  2.9e-6   suspicious       
  ...and 127 test result(s) without anomalies

rng=RNG_stdin32, seed=0x5d9a533f
length= 1 gigabyte (2^30 bytes), time= 17.3 seconds
  Test Name                         Raw       Processed     Evaluation
  [Low8/32]Gap-16:A                 R=  +4.4  p =  2.8e-3   unusual          
  [Low1/32]FPF-14+6/16:(0,14-0)     R=  +8.9  p =  8.4e-8   suspicious       
  [Low1/32]FPF-14+6/16:(1,14-1)     R=  +7.7  p =  1.3e-6   mildly suspicious
  [Low1/32]FPF-14+6/16:(3,14-2)     R= +10.2  p =  1.1e-8   very suspicious  
  [Low1/32]FPF-14+6/16:all          R= +17.8  p =  3.3e-16    FAIL !         
  [Low1/32]FPF-14+6/16:all2         R= +48.7  p =  6.9e-19    FAIL !         
  ...and 135 test result(s) without anomalies


real	0m17.933s
user	0m17.702s
sys	0m0.753s
*/
