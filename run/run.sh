if [ ! -f MKnapsack ]; then
echo "compile"
g++ -std=c++14 -O3 -march=native -mtune=native -DUSE_RND_MT19937_64 -DUSE_RND_BUFF_1 -DUSE_RND_F_BUFF_1 -DUSE_RND_PROB_0 -I../vendor/ ../vendor/MGenCPP/*.cpp ../src/*.cpp ../vendor/MRndCPP/*.cpp ../vendor/MiscCPP/m_args.cpp -o MKnapsack
fi

row=$1
while [ $row -le 2000 ]
do
args=$(cat args | head -n$row | tail -n1)
echo "$row - $args"

echo "$row ---------------------------------------------" >> results_$1.txt
echo           >> results_$1.txt   
echo $args     >> results_$1.txt
echo           >> results_$1.txt

r=876349874
{
time (
for i in {1..2000}
do
    r=$(( (r*103867+824723)%2000000000 ))
    cat data.txt | ./MKnapsack --rndSeed=$r $args  | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=sprintf("%f",$3); } END {print sum/2000}' >> results_$1.txt; } 2>> results_$1.txt

row=$((row+4))
done

#cat results.txt | less +G
#cat results.txt | tail -n1800 | awk -F';' "begin{i=0}{i++; if(i==5)print $1; if(i==9)i=0;}" | sort
