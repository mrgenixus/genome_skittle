#ifndef SKITTLE_RENDERER
#define SKITTLE_RENDERER

#include <vector>
#include "Color.h"

using namespace std;

class Interpreter;

class Renderer {
    
    int width_;
    int height_;
    bool enableTextures_;
    Interpreter* colors_;

protected:     
    virtual bool refresh();

public:
    //initialization;
    Renderer(Interpreter* );
    bool rebind(Interpreter* );
    
    //information
    bool texturesEnabled(){ return enableTextures_; };
    
    //action
    bool render();
    
    static const int maxSaneWidth = 4000;
    
};

#endif
