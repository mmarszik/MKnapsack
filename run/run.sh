echo '---------------------------------------------' >> results.txt
cat data.txt | head -n5 >> results.txt
echo '-------' >> results.txt
r=334312323
{
time (
for i in {1..100}
do
    r=$(( (r*103867+103837)%2000000000 ))
    echo $r > "_data.txt"
    cat data.txt >> "_data.txt"    
    cat _data.txt | ../release/MKnapsack | tail -n5 | head -n1
done
) | awk -F';' '{ sum+=$3 } END {print sum/100}' >> results.txt; } 2>> results.txt
rm _data.txt
cat results.txt | less
