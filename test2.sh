for i in {1..1000}
do
   echo  "Test: $i"
   time ./mknapsack | PractRand/RNG_test stdin32 -tlmax 1000s
done

