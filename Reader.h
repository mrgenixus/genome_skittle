#ifndef SKITTLE_READER
#define SKITTLE_READER

#include <stdlib.h>
#include <string>

#include "Sequence.h"

using namespace std;

class Reader {    
    
public:

    Reader(string filename = "\0");
    
    const Sequence* seq(string filename = "\0");
    static const int BlockSize = 5000000;
    
    Sequence* readNewFile(string);
    
    bool is_complete();
    void setComplete();
    void setIncomplete();
        
    int getProgress();
    void setProgress(int);
    
private:

    
    int progress;
    Sequence* genome; 
    bool done;
    
    string trimFilename(string);
    
};

#endif
