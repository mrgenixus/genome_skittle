#ifndef COLORRANGETABLE_H
#define COLORRANGETABLE_H
#include "ColorTable.h"
#include "Color.h"

namespace skittle {

    class ColorRangeTable : public ColorTable
    {
    public:
        ColorRangeTable();
        Color getColor(int rangevalue, int colorrange);
    };

}
#endif // COLORRANGETABLE_H
