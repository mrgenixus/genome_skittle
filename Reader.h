#ifndef READER
#define READER

#include <stdlib.h>
#include <string>

using namespace std;

class Reader {    
    
public:
    struct Sequence  {
        string value;
        string name;
    }; 

    Reader(string filename = "\0");
    //~Reader();
    
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
