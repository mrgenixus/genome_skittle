#include "Renderer.h"
#include "Color.h"

// main constructor
// should be called if your glWidget supports textures
Renderer::Renderer(vector<Color> pixels, int width, int max_size)
{
    useTextures_ = false;
    colors_ = vector<Color>(pixels);
    //pad the end with white pixels, background color
    for(int i = 0; i <= width; ++i)
        pixels.push_back( Color(128,128,128) );

    width_ = width;
    height_ = pixels.size() / width_;

    if(max_size > 0)
    {
        useTextures_ = true;

        //determine the size of the texture canvas
        int canvas_width = width_ / max_size + 1; //AKA ciel();
        //cout << "Initial Canvas Width:  " << canvas_width;
        canvas_width = min((maxSaneWidth / max_size + 1),canvas_width);
        //cout << " Sanity Checked:  " << canvas_width << endl;


        int canvas_height = height_ / max_size + 1;
        createEmptyTiles(canvas_width, canvas_height, max_size);


        for(vector<Color>::size_type i = 0; i < pixels.size(); i++)
        {

            Color c1 = pixels[i];

            vector< vector<Tile> >::size_type x = (i % width_) / max_size; //(horizontal Index)
            vector< vector<Tile> >::size_type y = (i / width_) / max_size; //(vertical Index)

            if (x >= canvas_.size() || y >= canvas_.size()) continue;

            vector<unsigned char>& current = canvas_[x][y].data_;
            current.push_back(c1.getRed());
            current.push_back(c1.getGreen());
            current.push_back(c1.getBlue());
        }
/* this needs to go somewhere else
        for(unsigned int x = 0; x < canvas.size(); ++x)
        {
            for(unsigned int y = 0; y < canvas[x].size(); ++y)
            {
                loadTexture(canvas[x][y]);//tex_ids.push_back(
                canvas[x][y].data.clear();//the data has been loaded into the graphics card
            }
        }
*/
    }
}

Renderer::Renderer(vector<Color> pixels, int width) { }

void Renderer::createEmptyTiles(int canvas_width, int canvas_height, int max_size)
{

    for(int x = 0; x < canvas_width ; ++x)//populate canvas
    {
        canvas_.push_back(vector<Tile>());
        for(int y = 0; y < canvas_height; ++y)
        {
            Tile t;
            t.width_ = min(width_ - (x * max_size), max_size);
            t.height_ = min(height_ - (y * max_size), max_size);
            canvas_[x].push_back(t);
        }
    }
}

Renderer::~Renderer()
{
    for(unsigned int x = 0; x < canvas_.size(); ++x)
        for(unsigned int y = 0; y < canvas_[x].size(); ++y)
            canvas_[x][y].data_.clear();//the data has been loaded into the graphics card
/*
    for(unsigned int i = 0; i < canvas.size(); ++i)
        for(unsigned int k = 0; k < canvas[i].size(); ++k)
            glDeleteTextures(1, &canvas[i][k].tex_id );
*/
}
