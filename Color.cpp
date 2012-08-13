#include "Color.h"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace skittle;

Color::Color(int red, int green, int blue) {
    setRed(red);setGreen(green);setBlue(blue);
}

bool Color::operator == (const Color other)
{
    return ( (r == other.r) && (g == other.g) && (b == other.b) );
}
Color Color::operator + (const Color other)
{
    return Color( min(255, r + other.r), min(255, g + other.g), min(255, b + other.b) );
}
Color Color::operator - (const Color other)
{
    return Color( max(0,(r - other.r)), max(0,(g - other.g)), max(0,(b - other.b)) );
}
Color Color::operator / (const int div)
{
    return Color( (int)(float(r)/div+.5), (int)(float(g)/div+.5), (int)(float(b)/div+.5) );
}
Color Color::operator * (const float mul)
{
    return Color( min(255, (int)(float(r)*mul+.5)), min(255, (int)(float(g)*mul+.5)), min(255, (int)(float(b)*mul+.5)) );
}

int Color::lightness()
{
    int a = max(r, g);
    return max( a, b);
}

void Color::setRed(int red){
    r = min(255,red);
}
void Color::setGreen(int green){
    g = min(255,green);
}
void Color::setBlue(int blue){
    b = min(255,blue);
}

int Color::getRed() const{
    return r;
}
int Color::getGreen() const{
    return g;
}
int Color::getBlue() const{
    return b;
}
