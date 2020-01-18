#include "params.h"


void Params::init(int argc, char *argv[]) {
    MGen::Params::init( argc , argv );
}

void Params::showHelp() const {
    MGen::Params::showHelp();
}
