#ifndef SKITTLE_COLOR
#define SKITTLE_COLOR

namespace skittle {

class Color {

public:
    Color():r(0), g(0), b(0) { };
    Color(int, int, int);
    
    void setRed(int);
    int getRed();
    void setGreen(int);
    int getGreen();
    void setBlue(int);
    int getBlue();
    
    bool operator == (const Color);
    Color operator + (const Color);
    Color operator - (const Color);
    Color operator / (const int);
    Color operator * (const float);
    int lightness();
    
private:
    int r;
    int g;
    int b;
};

}

#endif
