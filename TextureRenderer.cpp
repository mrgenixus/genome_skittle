#include "TextureRenderer.h"
#include "Interpreter.h"
#include "Color.h"
#include <QtOpenGL>
#include <stdlib.h>

/**
 * Renderer should setup a graph based on a colorlist and some other 
 * details.  We're kindof going to assume everyone else has either done 
 * their job or can live with the consequences.
 * 
 **/

TextureRenderer::TextureRenderer(Interpreter* abstractGraph) :
    Renderer::Renderer(abstractGraph) {
    enableTextures_ = getMaxTextureSize() > 0;
}

bool TextureRenderer::refresh(){
    
    int max_size = getMaxTextureSize();
    
    //pad the end with white pixels, background color //or lets don't until we understand why.
    //~ for(int i = 0; i <= width; ++i)
        //~ pixels.push_back( Color(128,128,128) );

    width_ = colors->getWith();
    height_ = colors->getPx()->size() / width_;

    if(enableTextures_)
    {
        //determine the size of the texture canvas
        int canvas_width = width_ / max_size + 1; //AKA ciel();
        canvas_width = min((maxSaneWidth / max_size + 1),canvas_width);

        int canvas_height = height_ / max_size + 1;
        createEmptyTiles(canvas_width, canvas_height, max_size);

        vector<Color>* pixels = colors->getPx();
        for(vector<Color>::size_type i = 0; i < pixels->size(); i++)
        {
            //this is specifically using the 'operator [] (int)' method defined by Interpreter.
            Color c1 = colors[i];

            tile_matrix::size_type x = (i % width_) / max_size; //(horizontal Index)
            tile_matrix::size_type y = (i / width_) / max_size; //(vertical Index)

            if (x >= canvas_.size() || y >= canvas_.size()) continue;

            vector<unsigned char>& current = canvas_[x][y].data_;
            current.push_back(c1.getRed());
            current.push_back(c1.getGreen());
            current.push_back(c1.getBlue());
        }
        
        for(unsigned int x = 0; x < canvas.size(); ++x)
        {
            for(unsigned int y = 0; y < canvas[x].size(); ++y)
            {
                loadTexture(canvas[x][y]);//tex_ids.push_back(
                canvas[x][y].data.clear();//the data has been loaded into the graphics card
            }
        }
    }
}

void TextureRenderer::createEmptyTiles(int canvas_width, int canvas_height)
{
    int max_size = getMaxTextureSize();

    //load pixels to canvases;
    for(int x = 0; x < canvas_width ; ++x) {
        canvas_.push_back(vector<Tile>());
        for(int y = 0; y < canvas_height; ++y) {
            Tile t;
            t.width_ = min(width_ - (x * max_size), max_size);
            t.height_ = min(height_ - (y * max_size), max_size);
            canvas_[x].push_back(t);
        }
    }
}

TextureRenderer::~TextureRenderer()
{
    for(unsigned int x = 0; x < canvas_.size(); ++x)
        for(unsigned int y = 0; y < canvas_[x].size(); ++y)
            canvas_[x][y].data_.clear();//the data has been loaded into the graphics card
}

GLuint TextureRenderer::loadTexture(textureTile& tile)
{
	glGenTextures( 1, &tile.tex_id );//TODO: could we store this in tile?
    glBindTexture (GL_TEXTURE_2D, tex_id);
    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//GL_NEAREST
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);               
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, tile.width, tile.height, 0, GL_RGB, GL_UNSIGNED_BYTE, &tile.data[0]);
    
    return tile.tex_id;
}

int TextureRenderer::getMaxTextureSize(){
    static int max_size = 0;
    if (0 == max_size){        
        glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_size);
        max_size = min(0,max_size);
    }
    return max_size;
}
