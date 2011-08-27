#ifndef SKITTLE_RENDERER
#define SKITTLE_RENDERER

#include <vector>
#include "Color.h"

using namespace std;

struct Tile {
    int width_;
    int height_;
    vector<unsigned char> data_;
};

class Renderer {

    int width_;
    int height_;
    vector< vector<Tile> > canvas_;
    vector<Color> colors_;
    bool useTextures_;
    void createEmptyTiles(int canvas_width, int canvas_height, int max_size);

public:
    Renderer();
    Renderer(vector<Color> pixels, int width);
    Renderer(vector<Color> pixels, int width, int max_size);
    ~Renderer();
    static const int maxSaneWidth = 4000;
};

#endif
