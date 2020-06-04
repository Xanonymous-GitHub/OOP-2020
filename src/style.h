#ifndef STYLE_H
#define STYLE_H

#include <string>
using namespace std;

class Style {
public:
    virtual const string renderStyle() = 0;
};
//return "height:" + to_string(a) + "px;weight:" + to_string(b) + "px;";
#endif