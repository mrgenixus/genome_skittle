#include "PointRenderer.h"
#include "Interpreter.h"
#include "Color.h"
#include <stdlib.h>

using namespace std;
using namespace skittle;

// main constructor
// should be called if your glWidget supports textures
PointRenderer::PointRenderer(Interpreter* abstractGraph) :
    Renderer::Renderer(abstractGraph) 
{
    
}

bool PointRenderer::refresh() {
    //draw some points based on colors_ ... I dunno, just some points, OK?
    return false;
}
