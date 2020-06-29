#ifndef FONTSIZE_H
#define FONTSIZE_H

#include "./style.h"

using namespace std;

class FontSize : public Style
{
private:
    int fontSize;

public:
    FontSize() : fontSize(16) {}
    FontSize(int fontSize) : fontSize(fontSize) {}
    string renderStyle() const override
    {
        return "font-size:" + to_string(fontSize) + "px;";
    }
};

#endif
