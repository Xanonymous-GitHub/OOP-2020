#ifndef TEXT_H
#define TEXT_H
#include <vector>
typedef std::string s;
class Text {
public:
    s render() {
        return "<p style=\'" + this->color + this->fontSize + "\'>" + this->content + "</p>";
    }

    void setColor(s color) {
        this->color = "color:" + color + ";";
    }

    void setFontSize(s fontSize) {
        this->fontSize = "font-size:" + fontSize + ";";
    }

    void setText(s content) {
        this->content = content;
    }

private:
    s content = "";
    s color = "color:#000000;";
    s fontSize = "font-size:16px;";
};

#endif
