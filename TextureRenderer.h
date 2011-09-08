#ifndef SKITTLE_TEXTURE_RENDERER
#define SKITTLE_TEXTURE_RENDERER

#include <vector>
#include "Color.h"
#include "Renderer.h"

using namespace std;

class Interpreter;

class TextureRenderer : public Renderer {
    
    struct Tile {
        GLuint tex_id;
        int width_;
        int height_;
        vector<unsigned char> data_;
    };    
    
    typedef vector< vector<Tile> > tile_matrix;
    tile_matrix canvas_;
    
    void createEmptyTiles(int canvas_width, int canvas_height, int max_size);
    
    //This will require a GL call:
    int getMaxTextureSize();
    
    //this is the default renderer function, called by render
    bool refresh();

public:
    TextureRenderer(Interpreter* );
    ~TextureRenderer();
};

#endif
