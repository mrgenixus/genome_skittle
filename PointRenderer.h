#ifndef SKITTLE_POINT_RENDERER
#define SKITTLE_POINT_RENDERER

#include <vector>
#include "Color.h"
#include "Renderer.h"

using namespace std;

class Interpreter;

class PointRenderer : public Renderer {

private:     
    bool refresh();

public:
    //initialization;
    PointRenderer(Interpreter* );
};

#endif
