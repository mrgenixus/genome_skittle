
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

#include "Reader.h";

int main(int argc, char *argv[]){
    Reader* myReader = new Reader();
    char* myFile;
    Reader::Sequence* sequence;
    if (argc > 1) {
        myFile = argv[1];
        sequence = myReader->readNewFile(myFile);
        cout << sequence->name << "(" << sequence->value.size() << "): " << sequence->value << endl;
    }
}
