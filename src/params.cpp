#include "params.h"

void Params::init(const DefParams &defP, int argc, char *argv[]) {
    MGen::Params::init( defP, argc , argv );
}

void Params::showHelp(const DefParams &defP) const {
    MGen::Params::showHelp(defP);
}
