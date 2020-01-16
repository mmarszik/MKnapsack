g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_MT19937_64 -DUSE_RND_BUFF_1 -DUSE_RND_F_BUFF_1 -DUSE_RND_PROB_0 -I../vendor/ ../vendor/MGenCPP/*.cpp ../src/*.cpp ../vendor/MRndCPP/*.cpp ../vendor/MiscCPP/m_args.cpp -o MKnapsack


for row in {1..40}
do
args=$(cat args | head -n$row | tail -n1)
echo $args

echo "$row ---------------------------------------------" >> results.txt
echo           >> results.txt   
echo $args     >> results.txt
echo           >> results.txt

r=2357109337
{
time (
for i in {1..1000}
do
    r=$(( (r*103867+824723)%2000000000 ))
    cat data.txt | ./MKnapsack --rndSeed=$r $args  | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=sprintf("%f",$3); } END {print sum/1000}' >> results.txt; } 2>> results.txt

#cat results.txt | less +G

done