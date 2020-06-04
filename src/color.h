#ifndef COLOR_H
#define COLOR_H

#include "./style.h"

class Color : public Style {
private:
    string color;

public:
    Color() : color("#000000") {}
    Color(string color) : color(color) {}
    string const renderStyle() override {
        return "color:" + color + ";";
    }
};

#endif