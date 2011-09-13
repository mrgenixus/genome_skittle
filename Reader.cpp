#include "Reader.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace skittle;

Reader::Reader(string filename) {
    
    progress = 0;
    done = false;
    fileSize = 0;
    wordFile.clear();

    if (!filename.empty()) {
        clog << "File: " << filename << endl;

        wordFile.open(filename.c_str(), ifstream::in | ifstream::binary);

        if (wordFile.fail()) {
            cerr << "Could not Read the File. File not exist or access error" << endl;
        } else {
            wordFile.seekg(0, ios::end);
            fileSize = wordFile.tellg();
            wordFile.seekg(0, ios::beg);
            wordFile.ignore(500, '\n');
        }
    }
}

Reader::~Reader() {

    wordFile.close();
}

Reader& Reader::operator>>(string& sequence) {

    string buffer(BlockSize,'\0');
    wordFile.read(&buffer[0], BlockSize);
    setProgress(min(progress,int(wordFile.tellg())));

    char *s = &buffer[0];
    while (*s != '\0' ) {
        sequence.push_back(char(toupper(*s)));
        ++s;
    }

    if (progress == fileSize) {
        setComplete();
    }
    return *this;
}

bool Reader::eof() {

    return wordFile.fail() || wordFile.eof();
}

void Reader::setProgress(int percent){
    progress = percent;
}

void Reader::setComplete(){
    done = true;
    setProgress(0);
}

void Reader::setIncomplete(){
    done = true;
}

bool Reader::is_complete(){
    return done;
}

int Reader::getProgress(){
    return progress;
}
