#ifndef TEXT_H
#define TEXT_H

#define $s(x) string(x)

#include "tag.h"
#include <string>
using namespace std;

class Text : public Tag {
private:
    string content;
    string color;
    string fontSize;
    void initValues() {
        content = "";
        color = "#000000";
        fontSize = "16px";
    }

public:
    Text() : Tag() {
        initValues();
    }

    Text(string id) : Tag(id) {
        initValues();
    }

    string render() const override {
        if (content.empty()) {
            return $s("<p></p>");
        }
        string inlineStyle = "";
        inlineStyle += "color:" + color + ";";
        inlineStyle += "font-size:" + fontSize + ";";
        return $s("<p") + $s(" id='") + $s(getId()) + $s("' style='") + $s(inlineStyle) + $s("'>") + $s(content) + $s("</p>");
    }

    void setColor(string color) {
        this->color = color;
    }

    void setFontSize(string fontSize) {
        this->fontSize = fontSize;
    }

    void setText(string content) {
        this->content = content;
    }
};

#endif
