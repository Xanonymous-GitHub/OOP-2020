#ifndef COLOR_H
#define COLOR_H

#include "style.h"

#include <string>
using namespace std;
class Color : public Style
{
private:
    string color;

public:
    Color() : color("#000000") {}
    Color(string color) : color(color) {}
    string renderStyle() const override
    {
        return "color:" + color + ";";
    }
};

#endif
