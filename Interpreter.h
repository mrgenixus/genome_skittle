#ifndef SKITTLE_INTERPRETER
#define SKITTLE_INTERPRETER

#include <vector>
#include <string>
#include "Color.h"

namespace skittle {

class Interpreter {

protected:
    virtual void calculate();
    std::vector<Color>* pxList;
    
    std::string* seq;
    
    int cached_width;
    int cached_start;
    int cached_scale;
    int cached_display_size;
    
public:

    struct params {
        std::string* seq;
        int width;
        int start;
        int scale;
        int display_size;
    };
    
    Interpreter(std::string* _seq, int width, int start, int scale, int display_size);
    Interpreter(params);
    ~Interpreter();
    
    //update method
    bool update(int, int, int, int, std::string* seq = 0);
    bool update(params);
    
    int getWidth();
    int getStart();
    int getScale();
    int getDisplaySize();

    //length accessor
    size_t getPxLength();
    size_t size();
    
    //index accessors
    const Color operator[] (int);
    const Color at(int);
    const Color getPxAt(int);
    
    //vector accessor (efficient/immutable)
    const std::vector<Color>* getPx();
    
    //vector accessor (innefficient/Mutable copy); //we should probably not allow this: it copies a ton of memory.
    std::vector<Color> copyPX();
};

}

#endif
