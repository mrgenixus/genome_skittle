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
    Color getColor(char nucleotide);
};

}

#endif // COLORTABLE_H
