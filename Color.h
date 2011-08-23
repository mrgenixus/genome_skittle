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
#endif
