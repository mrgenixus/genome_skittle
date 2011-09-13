#ifndef SKITTLE_RENDERER
#define SKITTLE_RENDERER

#include <vector>
#include "Color.h"

namespace skittle {

class Interpreter;

class Renderer {
    

protected:     
    int width_;
    int height_;
    bool enableTextures_;
    Interpreter* colors_;
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

}

#endif
