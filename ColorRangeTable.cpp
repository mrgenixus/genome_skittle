#include "ColorRangeTable.h"
#include "assert.h"

using namespace skittle;

ColorRangeTable::ColorRangeTable() : ColorTable()
{
}

Color ColorRangeTable::getColor(int rangevalue, int colorrange = 100) {
    assert(colorrange > 0); // dont divide by zero!
    return ColorTable::getColor(int(float(float(rangevalue)/float(colorrange) * 26)));
}
