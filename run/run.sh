echo '---------------------------------------------' >> results.txt
cat data.txt | head -n5 >> results.txt
echo '-------' >> results.txt

g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_MT19937_64 -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..100}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=sprintf("%f",$3) } END {print sum/100}' >> results.txt; } 2>> results.txt
rm _data.txt

exit

g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_WYHASH64_0 -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/2000}' >> results.txt; } 2>> results.txt
rm _data.txt


g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_WYHASH64M_0 -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/2000}' >> results.txt; } 2>> results.txt
rm _data.txt



g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_RANLUX_48 -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/2000}' >> results.txt; } 2>> results.txt
rm _data.txt



g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_MLIN_0 -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/2000}' >> results.txt; } 2>> results.txt
rm _data.txt



g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_LIN_2c -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/2000}' >> results.txt; } 2>> results.txt
rm _data.txt



g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_FIB_3a -DUSE_RND_BUFF_1a -DUSE_RND_F_BUFF_1a -DUSE_RND_PROB_0 -I../vendor/ ../src/*.cpp ../vendor/MRndCPP/*.cpp  -o MKnapsack

r=713493784
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ./MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/2000}' >> results.txt; } 2>> results.txt
rm _data.txt


