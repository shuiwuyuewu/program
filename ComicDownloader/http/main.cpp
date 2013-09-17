#include "http.h"
#include <iostream>

int main(int argc, char *argv[]){
    HTTP hp;

    hp.parser(argv[1]);
    #ifdef DEBUG
    hp.show();
    #endif
}
