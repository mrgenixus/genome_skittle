#include "Renderer.h"
#include "Interpreter.h"
#include "Color.h"
#include <QtOpenGL/QGLWidget>
#include <stdlib.h>

using namespace std;
using namespace skittle;

// main constructor
// should be called if your glWidget supports textures
/**
 * Renderer should setup a graph based on a colorlist and some other 
 * details.  We're kindof going to assume everyone else has either done 
 * their job or can live with the consequences.
 * 
 * 
 **/

Renderer::Renderer(Interpreter* abstractGraph){
    colors_ = abstractGraph;
    enableTextures_ = false;
}

bool Renderer::rebind(Interpreter* abstractGraph){
    if (abstractGraph != colors_){
        colors_ = abstractGraph;
        return true;
    }
    
    return false;
}

bool Renderer::refresh(){
    return false;
}

bool Renderer::render(){
    return refresh();
}
