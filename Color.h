#ifndef SKITTLE_COLOR
#define SKITTLE_COLOR

#include <iostream>

namespace skittle {

    class Color {

    public:
        Color():r(0), g(0), b(0) { };
        Color(int, int, int);

        void setRed(int);
        int getRed() const;
        void setGreen(int);
        int getGreen() const;
        void setBlue(int);
        int getBlue() const;

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
        //friend std::ostream& operator<<(std::ostream& os, const Color &c);
    };
    //std::ostream &operator<<(std::ostream &os, Color const &c);


}

inline std::ostream &operator<<(std::ostream &os, const skittle::Color &c)
{
    return os << c.getRed() << ' ' << c.getGreen() << ' ' << c.getBlue();
}

#endif
