#ifndef SKITTLE_TEXTURE_RENDERER
#define SKITTLE_TEXTURE_RENDERER

#include <vector>
#include <QtOpenGL>
#include "Color.h"
#include "Renderer.h"

namespace skittle {

class Interpreter;

class TextureRenderer : public Renderer {
    
    struct Tile {
        GLuint tex_id;
        int width_;
        int height_;
        std::vector<unsigned char> data_;
    };    
    
    typedef std::vector< std::vector<Tile> > tile_matrix;
    tile_matrix canvas_;
    
    void createEmptyTiles(int canvas_width, int canvas_height);
    GLuint loadTexture(Tile&);    

    //This will require a GL call:
    int getMaxTextureSize();
    
    //this is the default renderer function, called by render
    bool refresh();

public:
    TextureRenderer(Interpreter* );
    ~TextureRenderer();
};

}

#endif
