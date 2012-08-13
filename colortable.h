#ifndef COLORTABLE_H
#define COLORTABLE_H

#include <map>
#include "Color.h"

namespace skittle {

class ColorTable
{
    std::map<int, Color> currentColors;
public:
    ColorTable();
    Color getColor(int index);
    Color getColor(char nucleotide);
    Color mapColor(int index, Color c);
};

}

#endif // COLORTABLE_H
