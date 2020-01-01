#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include <iomanip>
#include <climits>
#include <cstring>
#include <assert.h>

#include <MRndCPP/rnd.h>
#include <MRndCPP/prob.h>
#include <MRndCPP/buffs.h>


#define RNDBUFSIZE ((1<<14)-1)

typedef double ftyp;
constexpr ftyp EPSILON = std::numeric_limits<ftyp>::epsilon();

typedef const ftyp cftyp;
typedef std::uniform_int_distribution<int> TIntDist;
typedef long long ltyp;
typedef unsigned long long ultyp;
typedef const ltyp cltyp;
typedef const ultyp cultyp;

class MyException : public std::exception {
private:
    const std::string swhat;

public:
    MyException( const char *const swhat ) : swhat(swhat) {
    }

    virtual const char* what() const throw(){
        return swhat.c_str();
    }
};

struct Spec {
    std::vector<uint8_t> genotype;
    std::vector<uint8_t> cgenotype; // copy genotype
    ftyp eval;
    ftyp ceval;                 // copy eval
    ftyp weight;
    ftyp cweight;               // copy weight

    void store() {
        cgenotype = genotype;
        ceval     = eval;
        cweight   = weight;
    }

    void restore() {
        genotype   = cgenotype;
        eval       = ceval;
        weight     = cweight;
    }

};

static std::ostream& operator<<( std::ostream& dest, const Spec &spec ) {
    dest << std::setprecision(14) << spec.ceval << "; " << std::setprecision(14) << spec.cweight << " [";
    for( size_t i=0 ; i<spec.genotype.size() ; i++ ) {
        std::cout << (int)spec.cgenotype[i];
        if( i < spec.genotype.size() - 1 ) {
            std::cout << ",";
        }
    }
    dest << "]";
    return dest;
}

struct BpItem {
    ftyp weight;
    ftyp value;
};

static std::ostream& operator<<( std::ostream& dest, const BpItem &item ) {
    dest << std::setprecision(14) << item.value << " / " << std::setprecision(14) << item.weight << " == " << item.value / item.weight;
    return dest;
}

static bool cmpItem( const BpItem &a , const BpItem &b ) {
    return a.value / a.weight > b.value / b.weight;
}

static int getSeed() {
    std::cout << "Please input random seed (zero to random): ";
    int n;
    std::cin >> n;
    if( std::cin.fail() ) {
        throw MyException("invalid random seed");
    }
    if( n < 1 ) {
        n = (int)time(NULL);
    }
    return n;
}

static int getLoops() {
    std::cout << "Please input max loops (zero to inifinite): ";
    int n;
    std::cin >> n;
    if( std::cin.fail() || n < 0 ) {
        throw MyException("invalid max loops");
    }
    return n;
}

static int getSize() {
    std::cout << "Please input population's size: ";
    int n;
    std::cin >> n;
    if( std::cin.fail() || n < 1) {
        throw MyException("invalid populations size");
    }
    return n;
}

static std::vector<ftyp> getBackpacks() {
    std::vector<ftyp> backpacks;
    std::cout << "Please input number of backpacks: ";
    int n;
    std::cin >> n;
    if( std::cin.fail() || n < 1 ) {
        throw MyException("invalid number of backpacks");
    }
    for( int i=0 ; i<n ; i++ ) {
        std::cout << (i+1) << " please input capacity of backpack: ";
        ftyp c;
        std::cin >> c;
        if( std::cin.fail() || c <= 0 ) {
            throw MyException("invalid capacity of backpack");
        }
        backpacks.push_back( c );
    }
    return backpacks;
}

static float getMutation() {
    std::cout << "Please input probability of mutations <0.000,1.000>: ";
    ftyp n;
    std::cin >> n;
    if( std::cin.fail() || n > 1 || n < 0 ) {
        throw MyException("invalid probability of mutation");
    }
    return n;
}

static ftyp getBack() {
    std::cout << "Please input probability of back <0.000,1.000>: ";
    ftyp n;
    std::cin >> n;
    if( std::cin.fail() || n < 0 || n > 1 ) {
        throw MyException("invalid probability of back");
    }
    return n;
}

static ftyp getPenal() {
    std::cout << "Please input penal: ";
    ftyp n;
    std::cin >> n;
    if( std::cin.fail() || n < 0 ) {
        throw MyException("invalid penal");
    }
    return n;
}

static std::vector<BpItem> getItems() {
    std::vector<BpItem> items;
    std::cout << "Please insert number of items:";
    int n;
    std::cin >> n;
    if( std::cin.fail() || n < 1 ) {
        throw MyException("invalid number of items");
    }
    items.resize( n );

    for( int i=0 ; i<n ; i++ ) {
        BpItem bpItem;
        std::cout << "insert " << (i+1) << " weight: ";
        std::cin >> bpItem.weight;
        if( std::cin.fail() || bpItem.weight <= 0 ) {
            throw MyException("invalid weight");
        }
        std::cout << "insert " << (i+1) << " value: ";
        std::cin >> bpItem.value;
        if( std::cin.fail() || bpItem.value <= 0 ) {
            throw MyException("invalid value");
        }
        items[i] =  bpItem ;
    }
    std::sort(items.begin(),items.end(),cmpItem);
    for( size_t i=0 ; i<items.size() ; i++ ) {
        std::cout << (i+1) << " " << items[i] << std::endl;
    }
    std::cout << "Readed " << items.size() << " elements" << std::endl;
    return items;
}

static void evalSpec(
    Spec                      &spec,
    const std::vector<ftyp>   &_backpacks ,
    const std::vector<BpItem> &items ,
    cftyp                     penal ,
    std::vector<ftyp>         &tmpWeights
) {
    spec.eval   = 0;
    spec.weight = 0;
    std::fill( tmpWeights.begin() , tmpWeights.end() , 0 );
    cftyp *const backpacks = _backpacks.data();
    for( size_t i=0 ; i<spec.genotype.size() ; i++ ) {
        if( spec.genotype[i] == 0 ) {
            continue;
        }
        const int nr = spec.genotype[i] - 1;
        if( tmpWeights[nr] + items[i].weight > backpacks[nr] ) {
            spec.eval -= penal;
            continue;
        }
        tmpWeights[nr] += items[i].weight;
        spec.weight += items[i].weight;
        spec.eval += items[i].value;
    }
}

static void randSpec(
    Spec      &spec ,
    TRnd      &rnd ,
    const std::vector<BpItem> &items,
    const std::vector<ftyp> backpacks
) {
    spec.genotype.resize( items.size() );
    spec.cgenotype.resize( items.size() );
    for( size_t i=0 ; i<items.size() ; i++ ) {
        spec.genotype[i] = ( rnd() % ( backpacks.size() + 1 ) );
    }
}

static void mutationSpec(
    Spec                    &spec,
    TRndBuff                &rndGen ,
    TRndBuff                &rndAllel
) {
    const size_t gen = rndGen();
    int    value;
    do {
        value = rndAllel();
    } while( spec.genotype[ gen ] == value );
    spec.genotype[ gen ] = value;
}

static void cross2(
    const Spec &a,
    const Spec &b,
    Spec       &out,
    TRnd       &rnd
) {
    for( size_t i=0 ; i<a.genotype.size() ; i++ ) {
        if( rnd() & 1 ) {
            out.genotype[i] = a.genotype[i];
        } else {
            out.genotype[i] = b.genotype[i];
        }
    }
}

static void cross1(
    const Spec &a,
    const Spec &b,
    Spec       &out,
    TRndBuff   &rndCross
) {
    const size_t x = rndCross();
    for( size_t i=0 ; i<x ; i++ ) {
        out.genotype[i] = a.genotype[i];
    }
    for( size_t i=x ; i<a.genotype.size() ; i++ ) {
        out.genotype[i] = b.genotype[i];
    }
}

static ftyp mkAvg( const std::vector<Spec> &specs ) {
    ftyp sum = 0;
    for( size_t i=0 ; i<specs.size() ; i++ ) {
        sum += specs[i].ceval;
    }
    return sum / specs.size();
}

static ftyp mkStDev( const std::vector<Spec> &specs ) {
    std::vector<ftyp> stdev( specs[0].cgenotype.size() , 0 );
    std::vector<ftyp> avgs( specs[0].cgenotype.size() , 0 );
    for( size_t i=0 ; i<specs.size() ; i++ ) {
        for( size_t j=0 ; j<specs[i].cgenotype.size() ; j++ ) {
            avgs[j] += specs[i].cgenotype[j];
        }
    }
    for( size_t i=0 ; i<avgs.size() ; i++ ) {
        avgs[i] /= specs.size();
    }
    for( size_t i=0 ; i<specs.size() ; i++ ) {
        for( size_t j=0 ; j<specs[i].cgenotype.size() ; j++ ) {
            cftyp tmp = avgs[j] - specs[i].cgenotype[j];
            stdev[j] += tmp * tmp;
        }
    }
    ftyp sum = 0;
    for( size_t i=0 ; i<avgs.size() ; i++ ) {
        sum += sqrt( stdev[i] / specs.size() );
    }
    return sum / specs[0].cgenotype.size();
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    try {
        const int seed     = getSeed();
        std::cout << "seed = " << seed << std::endl;
        TRnd rnd( seed );
        const int loops    = getLoops();
        const int size     = getSize();
        TRndProb pMutation( rnd , getMutation() );
        TRndProb pBack( rnd , getBack() );
        cftyp penal        = getPenal();
        const std::vector<ftyp> backpacks = getBackpacks();
        const std::vector<BpItem> items = getItems();

        //TIntDist pDist(0 , size-1 );
        TRndBuff rndParent(rnd,0,size-1);
        TRndBuff rndGen(rnd,0,items.size()-1);
        TRndBuff rndAllel(rnd,0,backpacks.size());
        TRndBuff rndCross(rnd,1,items.size()-2);

        const time_t start = time(NULL);
        time_t showTime    = start;

        std::vector<Spec> specs( size );
        std::vector<ftyp> tmpWeights( backpacks.size() , 0 );

        int best = 0;
        ltyp improveStat[2] = {0,0};
        ltyp sumStat[2]     = {0,0};

        for( size_t i=0 ; i<specs.size() ; i++ ) {
            randSpec( specs[i] , rnd , items , backpacks );
            evalSpec( specs[i] , backpacks , items , penal , tmpWeights );
            specs[i].store();
            if( specs[best].eval < specs[i].eval ) {
                best = i;
            }
        }

        std::cout << (time(NULL)-start) << "s; best[0]: " << specs[ best ] << std::endl;
        std::cout << "avg: " << std::setprecision(14) << mkAvg(specs) << std::endl;

        for( int loop=1 ; loops == 0 || loop <= loops ; loop++ ) {

            for( int child=0 ; child<size ; child++ ) {
                int improveIdx;
                if( pMutation() ) {
                    improveIdx = 0;
                    mutationSpec( specs[child] , rndGen , rndAllel );
                } else {
                    improveIdx = 1;
                    int parent1, parent2;
                    do {
                        parent1 = rndParent();
                        parent2 = rndParent();
                    } while(parent1 == parent2 || parent1 == child || parent2 == child);
                    cross1( specs[parent1], specs[parent2], specs[child], rndCross );
                }
                evalSpec( specs[child] , backpacks , items , penal , tmpWeights );
                sumStat[improveIdx] ++ ;
                if( specs[child].eval < specs[child].ceval ) {
                    if( pBack() ) {
                        specs[child].restore();
                    }
                } else {
                    if( specs[child].eval > specs[child].ceval ) {
                        improveStat[improveIdx] ++ ;
                        if( specs[child].eval > specs[best].ceval ) {
                            best = child;
                            showTime = 0;
                        }
                    }
                    specs[child].store();
                }
            }
            if(
                showTime == 0
                    ||
                ( !(loop & 63) && time(NULL) - showTime >= 10 )
                    ||
                loop == loops
            ) {
                std::cout << (time(NULL)-start) << "s; best[" << loop << "]; " << specs[best] << std::endl;
                std::cout << "avg:   " << mkAvg(specs) << std::endl;
                std::cout << "stdev: " << mkStDev(specs) << std::endl;
                std::cout << "mutation inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[0] / (sumStat[0]+EPSILON)) << "% all: " << std::setw(11) << sumStat[0] << std::endl;
                std::cout << "cross:   inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[1] / (sumStat[1]+EPSILON)) << "% all: " << std::setw(11) << sumStat[1] << std::endl;
                showTime = time(NULL);
            }
        }
    }
    catch( std::exception &e ) {
        std::cout << "We have a problem: " << e.what() << std::endl;
    }
    return 0;
}
