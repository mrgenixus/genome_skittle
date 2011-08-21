#ifndef SKITTLE_COLOR
#define SKITTLE_COLOR

class Color {

public:
    Color(int r, int g, int b);
    
    void setRed(int r);
    int getRed();
    void setGreen(int g);
    int getGreen();
    void setBlue(int b);
    int getBlue();
    
    color operator == (const color other);
    color operator + (const color other);
    color operator - (const color other);
    color operator / (const color other);
    color operator * (const color other);
    int lightness();
    
private:
    int r;
    int g;
    int b;
}
#endif
