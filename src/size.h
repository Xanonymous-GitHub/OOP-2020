#ifndef SIZE_H
#define SIZE_H

#include "./style.h"

class Size : public Style
{
private:
    int height, weight;

public:
    Size() : height(0), weight(0) {}
    Size(int height) : height(height), weight(0) {}
    Size(int height, int weight) : height(height), weight(weight) {}
    string renderStyle() const override
    {
        return "height:" + to_string(height) + "px;weight:" + to_string(weight) + "px;";
    }
};

#endif
