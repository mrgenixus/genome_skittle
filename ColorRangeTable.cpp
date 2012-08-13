#include "ColorRangeTable.h"
#include "assert.h"

using namespace skittle;

ColorRangeTable::ColorRangeTable() : ColorTable()
{
}

Color ColorRangeTable::getColor(int rangevalue, Range colorrange = std::make_pair(0,100) ) {
    int range = colorrange.second - colorrange.first;
    assert(range > 0); // dont divide by zero!
    return ColorTable::getColor(int(float(float(rangevalue)/float(range) * 26)));
}
