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

#include "MGenCPP/params.h"
#include "MGenCPP/genotype.h"

#define RNDBUFSIZE ((1<<14)-1)

typedef double ftyp;
constexpr ftyp EPSILON = std::numeric_limits<ftyp>::epsilon();

typedef const ftyp cftyp;
//typedef std::uniform_int_distribution<int> TIntDist;
typedef long long ltyp;
typedef unsigned long long ultyp;
typedef const ltyp cltyp;
typedef const ultyp cultyp;
typedef unsigned int utyp;
typedef const utyp cutyp;


using namespace MGen;


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
//    utyp stagnation;

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

    bool operator < (const Spec& other) const {
        return ceval > other.ceval;
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
    Params params;
    params.init( argc , argv );
    if( params.isHelp() ) {
        params.showHelp();
        return -1;
    }
    try {
        std::cout << "seed = " << params.getSeed() << std::endl;
        TRnd random( params.getSeed() );
        GRnd rnd( random );
        const int loops           = params.getMaxLoops();
        const int numberSpecs     = params.getNumberSpecs();
        rnd.init( params.getPMutation(), params.getPBack(), params.getPBests() );
        cftyp penal               = getPenal();
        const std::vector<ftyp> backpacks = getBackpacks();
        const std::vector<BpItem> items = getItems();

        TRndBuff rndParent(random, 0, params.getNumberParents()-1 );
        TRndBuff rndSpec(random, 0, params.getNumberSpecs()-1 );
        TRndBuff rndGen(random,0,items.size()-1);
        TRndBuff rndAllel(random,0,backpacks.size());
        TRndBuff rndCross(random,1,items.size()-2);

        const time_t start = time(NULL);
        time_t showTime    = start;

        std::vector<Spec> specs( numberSpecs );
        std::vector<ftyp> tmpWeights( backpacks.size() , 0 );

        ltyp improveStat[2] = {0, 0};
        ltyp sumStat[2]     = {0, 0};

        CUINT swapParents =
            params.getNumberParents() < params.getNumberSpecs()
        ?
            params.getSwapParents()
        :
            0;

        for( TUINT i=0 ; i<specs.size() ; i++ ) {
            randSpec( specs[i] , random , items , backpacks );
            evalSpec( specs[i] , backpacks , items , penal , tmpWeights );
            specs[i].store();
        }

        {
            TUINT best = 0;
            for( TUINT i=1 ; i<specs.size() ; i++ ) {
                if( specs[i].ceval > specs[best].ceval ) {
                    best = i;
                }
            }
            std::swap( specs[0] , specs[best] );
        }

        std::cout << (time(NULL)-start) << "s; best[0]: " << specs[ 0 ] << std::endl;
        std::cout << "avg: " << std::setprecision(14) << mkAvg(specs) << std::endl;

        for( int loop=1 ; loops == 0 || loop <= loops ; loop++ ) {

            const int maxChild = rnd.isBests() ? params.getNumberBests() : params.getNumberSpecs();

            for( int child=0 ; child<maxChild; child++ ) {
                int improveIdx;
                if( rnd.isMutation() ) {
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
                    if( rnd.isBack() ) {
                        specs[child].restore();
                    }
                } else {
                    if( specs[child].eval > specs[child].ceval ) {
                        improveStat[improveIdx] ++ ;
                        specs[child].store();
                        if( specs[child].ceval > specs[0].ceval ) {
                            std::swap( specs[child] , specs[0] );
                            showTime = 0;
                        } else if( child == 0 ) {
                            showTime = 0;
                        }
                    } else {
                        specs[child].store();
                    }
                }
            }

            for( TUINT i=0 ; i<swapParents ; i++ ) {
                TUINT i1 = rndSpec();
                TUINT i2 = rndSpec();
                if( i1 > i2 ) {
                    std::swap(i1,i2);
                }
                if( specs[i1].ceval < specs[i2].ceval ) {
                    std::swap( specs[i1] , specs[i2] );
                }
            }

            if(
                showTime == 0
                    ||
                ( !(loop & 63) && time(NULL) - showTime >= 10 )
                    ||
                loop == loops
            ) {
                std::cout << (time(NULL)-start) << "s; best[" << loop << "]; " << specs[0] << std::endl;
                std::cout << "avg:   " << mkAvg(specs) << std::endl;
                std::cout << "stdev: " << mkStDev(specs) << std::endl;
                std::cout << "mutation inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[0] / (sumStat[0]+EPSILON)) << "% all: " << std::setw(11) << sumStat[0] << std::endl;
                std::cout << "cross:   inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[1] / (sumStat[1]+EPSILON)) << "% all: " << std::setw(11) << sumStat[1] << std::endl;
//                std::cout << "replace: inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[2] / (sumStat[2]+EPSILON)) << "% all: " << std::setw(11) << sumStat[2] << std::endl;
                showTime = time(NULL);
            }
        }
    }
    catch( std::exception &e ) {
        std::cout << "We have a problem: " << e.what() << std::endl;
    }
    return 0;
}

/*
int main(int argc, char *argv[]) {
    Params params;
    params.init( argc , argv );
    if( params.isHelp() ) {
        params.showHelp();
        return -1;
    }
    try {
        std::cout << "seed = " << params.getSeed() << std::endl;
        TRnd random( params.getSeed() );
        GRnd rnd( random );
        const int loops           = params.getMaxLoops();
        const int numberSpecs     = params.getNumberSpecs();
        rnd.init( params.getPMutation(), params.getPBack(), params.getPBests() );
        cftyp penal               = getPenal();
        const std::vector<ftyp> backpacks = getBackpacks();
        const std::vector<BpItem> items = getItems();

        TRndBuff rndParent(random, 0, params.getNumberParents()-1 );
        TRndBuff rndGen(random,0,items.size()-1);
        TRndBuff rndAllel(random,0,backpacks.size());
        TRndBuff rndCross(random,1,items.size()-2);

        const time_t start = time(NULL);
        time_t showTime    = start;

        std::vector<Spec> specs( numberSpecs );
        std::vector<ftyp> tmpWeights( backpacks.size() , 0 );

        ltyp improveStat[2] = {0,0};
        ltyp sumStat[2]     = {0,0};

        CUINT swapParents =
            params.getNumberParents() > params.getNumberBests() // The best specimens are always sorted, swap is not necessary.
        &&
            params.getNumberParents() < params.getNumberSpecs()
        ?
            params.getSwapParents()
        :
            0;


        CUINT lastBest = params.getNumberBests() - 1;
        for( TUINT i=0 ; i<specs.size() ; i++ ) {
            randSpec( specs[i] , random , items , backpacks );
            evalSpec( specs[i] , backpacks , items , penal , tmpWeights );
            specs[i].store();
            if( i > lastBest ) {
                if( specs[i].eval < specs[lastBest].eval ) {
                    continue;
                }
                std::swap( specs[i] , specs[lastBest] );
            }
            size_t sortStart = i > lastBest ? lastBest : i;
            while( sortStart > 0 && specs[sortStart-1].eval < specs[sortStart].eval ) {
                std::swap( specs[sortStart-1], specs[sortStart] );
                sortStart--;
            }
        }

        std::cout << (time(NULL)-start) << "s; best[0]: " << specs[ 0 ] << std::endl;
        std::cout << "avg: " << std::setprecision(14) << mkAvg(specs) << std::endl;

        for( int loop=1 ; loops == 0 || loop <= loops ; loop++ ) {

            const int maxChild = rnd.isBests() ? params.getNumberBests() : params.getNumberSpecs();

            for( int child=0 ; child<maxChild; child++ ) {
                int improveIdx;
                if( rnd.isMutation() ) {
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
                    if( rnd.isBack() ) {
                        specs[child].restore();
                    }
                } else {
                    if( specs[child].eval > specs[child].ceval ) {
                        improveStat[improveIdx] ++ ;
                        specs[child].store();
                        if( child > lastBest && specs[child].ceval > specs[lastBest].ceval ) {
                            std::swap( specs[child] , specs[lastBest] );
                        }
                        size_t sortStart = child > lastBest ? lastBest : child;
                        while( sortStart > 0 && specs[sortStart-1].ceval < specs[sortStart].ceval ) {
                            std::swap( specs[sortStart-1], specs[sortStart] );
                            sortStart--;
                        }
                        if( sortStart == 0 ) {
                            showTime = 0;
                        }
                    } else {
                        specs[child].store();
                    }
                }
            }

            for( TUINT i=0 ; i<swapParents ; i++ ) {
                TUINT i1 = random.range( params.getNumberBests()   , params.getNumberParents() - 1 );
                TUINT i2 = random.range( params.getNumberParents() , params.getNumberSpecs() - 1   );
                if( specs[i1].ceval < specs[i2].ceval ) {
                    std::swap( specs[i1] , specs[i2] );
                }
            }

            if(
                showTime == 0
                    ||
                ( !(loop & 63) && time(NULL) - showTime >= 10 )
                    ||
                loop == loops
            ) {
                std::cout << (time(NULL)-start) << "s; best[" << loop << "]; " << specs[0] << std::endl;
                std::cout << "avg:   " << mkAvg(specs) << std::endl;
                std::cout << "stdev: " << mkStDev(specs) << std::endl;
                std::cout << "mutation inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[0] / (sumStat[0]+EPSILON)) << "% all: " << std::setw(11) << sumStat[0] << std::endl;
                std::cout << "cross:   inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[1] / (sumStat[1]+EPSILON)) << "% all: " << std::setw(11) << sumStat[1] << std::endl;
//                std::cout << "replace: inc:" << std::setw(13) << std::setprecision(7) << (100.0 * improveStat[2] / (sumStat[2]+EPSILON)) << "% all: " << std::setw(11) << sumStat[2] << std::endl;
                showTime = time(NULL);
            }
        }
    }
    catch( std::exception &e ) {
        std::cout << "We have a problem: " << e.what() << std::endl;
    }
    return 0;
}
*/
