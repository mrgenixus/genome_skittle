#include "PointerRenderer.h"
#include "Interpreter.h"
#include "Color.h"
#include <stdlib.h>

// main constructor
// should be called if your glWidget supports textures
/**
 * Renderer should setup a graph based on a colorlist and some other 
 * details.  We're kindof going to assume everyone else has either done 
 * their job or can live with the consequences.
 * 
 * 
 **/

PointRenderer::PointRenderer(Interpreter* abstractGraph){
    Renderer::Renderer();
}


bool Renderer::refresh(){
    //draw some points based on colors_ ... I dunno, just some points, OK?
    return false;
}
