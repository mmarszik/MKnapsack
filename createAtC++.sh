d=$(date "+%F %T %Z")
r=$(uuidgen)
if [ "$1" == "" ]; then
s='TR'
else
s=$1
fi

function echo70()
{
    echo $1 | fold -s -w 65 | awk '{ print "/// " $0;}' | awk '{ printf "%s", $0; for( i=length($0) ; i<70 ; i++ ) { printf " "; } print "//"; }'
}

lic1="The genetic Algorithm to solve Problem Multi-Knapsack."
lic2="It is file containing source code of genetic algorithm to solve multi-knapsack problem. It turned out that the genetic algorithm very well solves the multi-backpack problem."
lic3="The file is share on the open source licence, but unlike GPL, MIT, BSD, APACHE, L-GPL, etc, it is NOT standard and NOT liberary licence of the open source. By downloading and reading this file, you conclude a contract with me. Namely, if you understand that my source code can be improved (for example: speed up, better algorithms, better implementatnions, better parametrs, fixed bugs, etc), you need to present me everything in very detail. You can only download, read and compile this project only on the your personal computer. You can run the executable file and solve any problem, but only on the your own personal computer. You can see what the genetic alghorithm work in any practical multi-knapsack problem. However you can not use results of this program in the business applications. You also can NOT modifi, reshare, redistribuate binary or text version this or other file from whole project. You can not use whole file or fews lines from the file in your or others projects. If you need the other or commercial licence please send to me email."


echo "////////////////////////////////////////////////////////////////////////"
echo70
echo70 "$lic1"
echo70
echo70 "$lic2"
echo70
echo70 "$lic3"
echo70
echo "////////////////////////////////////////////////////////////////////////"
echo70
echo70 "@created on $d"
echo70 "@author MMarszik (Mariusz Marszalkowski sqnett.com)"
echo70 "@email mmarszik@gmail.com"
echo70 "@package MKnapsack"
echo70 "@token $r"
echo70 "@brief: "
echo70
echo "////////////////////////////////////////////////////////////////////////"
