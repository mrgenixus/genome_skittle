#include "Reader.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>

Reader::Reader(string filename) {
    
    progress = 0;
    
    if ( filename.empty() ){
        done = true;
        genome = new Sequence;
        genome->value.clear();
        genome->name.clear();
    } else {
        done = false;
        //read file
        genome = readNewFile(filename);
    }
    
}

Reader::Sequence* Reader::readNewFile(string filename){
    
    Sequence* fileSequence = new Sequence;
    fileSequence->value.clear();
    fileSequence->name.clear();
    if( ! filename.empty() )
    {
        cerr << string("File: ").append(filename) << endl;
        
        //initialize sequence 
        fileSequence->name = trimFilename(filename);
        
        fileSequence->value = string(">");
        
        std::ifstream wordfile;
        wordfile.clear();
        wordfile.open( filename.c_str(), ifstream::in | ifstream::binary );
        if (wordfile.fail()) {
            cerr << "Could not Read the File. File not exist or access error" << endl;
        }
        else {
            
            //initialize file
            
            wordfile.seekg (0, ios::end);
            int bytesInFile = wordfile.tellg();
            wordfile.seekg(0, ios::beg);
            //read
            
            int start = 0;
            int readBytes = 0;
            int bytesLeft = bytesInFile - start;
            while( start < (bytesLeft - 1) && ! wordfile.fail() ){
                readBytes = min(BlockSize, bytesLeft);
                if(start == 0) wordfile.ignore(500,'\n');
                vector<char> temp(readBytes, '\n');
                wordfile.read(&temp[0], readBytes);
                
                char curr;
                for( int i = 0; i < readBytes; ++i) {
                    curr = temp[i];
                    if( !( curr == '\n' || curr == '\r' ) ) {
                        fileSequence->value.push_back(char(toupper(curr)));
                    }
                }
                if (start != 0 && bytesInFile != 0) setProgress( 100 / ( bytesInFile * start ));
                else setProgress(0);

                start = wordfile.tellg();
                bytesLeft = bytesInFile - start;
            }
            cerr << "File Read Complete" << endl;
            setComplete();
            setProgress(0);
            
            
            //close up
            wordfile.close();
            return fileSequence;
        }
    }
    return 0;
}

string Reader::trimFilename(string path) {
    int startI = path.find_last_of('/');
    int endI = path.size();
    int sizeI = endI - startI;
    return path.substr(startI + 1, sizeI -1);
}

void Reader::setProgress(int percent){
    progress = percent;
}

void Reader::setComplete(){
    done = true;
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

const Reader::Sequence* Reader::seq(string filename){
    return genome = readNewFile(filename);
}

