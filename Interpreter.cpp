#include "Interpreter.h"
#include <map>

Interpreter::Interpreter(string* _seq, int width, int start, int scale, int display_size){
    pxList = new vector<Color>;
    update(width, start, scale, display_size, _seq);
}
Interpreter::Interpreter(params input){
    Interpreter(input.seq, input.width, input.start, input.scale, input.display_size);
}
Interpreter::~Interpreter(){
    delete pxList;
}

int Interpreter::getWidth(){ return cached_width;};
int Interpreter::getStart(){ return cached_start;};
int Interpreter::getScale(){ return cached_scale;};
int Interpreter::getDisplaySize(){return cached_display_size;};

//update method
bool Interpreter::update(int width, int start, int scale, int display_size, string* _seq){
    seq = _seq;
    cached_width = width;
    cached_start = start;
    cached_scale = scale;
    cached_display_size = display_size;
    calculate();
    return true;
}
bool Interpreter::update(params input){
    return update(input.width, input.start, input.scale, input.display_size, input.seq);
}
//length accessor
size_t Interpreter::getPxLenght(){
    return pxList->size();
}
size_t Interpreter::size(){ 
    return getPxLenght();
}

//index accessors
const Color Interpreter::operator[] (int index) { 
	return getPxAt(index); 
};

const Color Interpreter::at(int index){ return getPxAt(index); };
const Color Interpreter::getPxAt(int index){
    if (index < int(pxList->size())) {
        return Color((*pxList)[index]); 
    }
    return Color(0,0,0);
}

//vector accessor (efficient/immutable)
const vector<Color>* Interpreter::getPx(){ return pxList;};

//vector accessor (innefficient/Mutable copy);
vector<Color> Interpreter::copyPX() {
    return vector<Color>(*pxList);
}

void Interpreter::calculate(){ //do nothing
    
}
    
