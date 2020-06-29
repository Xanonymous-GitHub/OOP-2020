#ifndef IMAGE_H
#define IMAGE_H

#define $s(x) string(x)

#include "./style.h"
#include "tag.h"
#include <string>

using namespace std;

class Image : public Tag
{
private:
    string imageSrc;
    string top;
    string left;
    string inlineStyle;
    void initValues()
    {
        imageSrc = "";
        top = "0px";
        left = "0px";
    }

public:
    Image() : Tag() { initValues(); }

    Image(string id) : Tag(id) { initValues(); }

    string render() const override
    {
        return $s("<img") + $s(" id='") + $s(getId()) + $s("' src='") +
               $s(imageSrc) + $s("' style='") + inlineStyle + $s("'/>");
    }

    void setPosition(string top, string left)
    {
        this->top = top;
        this->left = left;
    }

    void setSrc(string imageSrc) { this->imageSrc = imageSrc; }

    void addStyle(Style *style)
    {
        inlineStyle += style->renderStyle();
    }
};

#endif
