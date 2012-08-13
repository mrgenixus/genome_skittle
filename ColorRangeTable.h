#ifndef COLORRANGETABLE_H
#define COLORRANGETABLE_H
#include "ColorTable.h"
#include "Color.h"
#include <stdlib.h>

namespace skittle {

    class ColorRangeTable : public ColorTable
    {

    public:
        typedef std::pair<int,int> Range;

        ColorRangeTable();
        Color getColor(int rangevalue, Range);


    };

}
#endif // COLORRANGETABLE_H
