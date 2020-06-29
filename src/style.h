#ifndef STYLE_H
#define STYLE_H

#include <string>

class Style
{
public:
    virtual std::string renderStyle() const = 0;
};

#endif
