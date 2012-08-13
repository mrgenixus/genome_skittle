#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "Reader.h"
//#include "NucleotideInterpreter.h"
#include "TextureRenderer.h"
#include "PointRenderer.h"
#include "ColorTable.h"
#include "Color.h"


using namespace std;
using namespace skittle;
typedef string adv_seq;

int displayFile(string filename){
	
	adv_seq sequence;
    int width = 250;
    int start = 1;
    int scale = 1; 
    int lines = 250; //or height?
    int display_size = width * lines;
    
	Reader *myreader = new Reader(filename);

	while (!myreader->eof()) *myreader >> sequence;

	cerr <<"(" << sequence.size() << ")" << sequence << endl;
    
    //Interpreter* graph1 = new NucleotideInterpreter(&sequence, width, start, scale, display_size);
    
    //TextureRenderer* viewPort = new TextureRenderer();
    //viewport->addGraph(graph1);
    
    return 0;
}




int main(int argc, char *argv[]) {

    //if (argc > 1) return displayFile(argv[1]);
    ColorTable *ct = new ColorTable;

    cout << "A: " << ct->getColor('A') << endl;
    cout << "B: " << ct->getColor('B') << endl;
    cout << "C: " << ct->getColor('C') << endl;
    ct->mapColor('B',Color(0,0,5000));
    cout << "A: " << ct->getColor('A') << endl;
    cout << "B: " << ct->getColor('B') << endl;
    cout << "C: " << ct->getColor('C') << endl;\

    return 0;
}
