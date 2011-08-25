#ifndef SKITTLE_READER
#define SKITTLE_READER

#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

class Reader {    
    
public:

    Reader(string filename);
    ~Reader();
    
    Reader& operator>>(string&);
    static const int BlockSize = 500000;
    
    bool eof();
    bool is_complete();
    void setComplete();
    void setIncomplete();
        
    int getProgress();
    void setProgress(int);

protected:

    streamsize fileSize;
    
private:

    int progress;
    bool done;
    ifstream wordFile;
    
};

#endif
