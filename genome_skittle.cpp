#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "Reader.h"

using namespace std;
using namespace skittle;

int main(int argc, char *argv[]) {

    string sequence;
    if (argc > 1) {
        string filename = argv[1];
        Reader *myreader = new Reader(filename);

        while (!myreader->eof()) *myreader >> sequence;
        
        cout <<"(" << sequence.size() << ")" << sequence << endl;
    }
}
