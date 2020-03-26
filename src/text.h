#ifndef TEXT_H
#define TEXT_H

#include <cstring>

class Text {

public:
    std::string render() {
        return "<p>" + this->content + "</p>";
    }

    void setText(std::string content) {
        this->content = content;
    }

private:
    std::string content = "";
};

#endif
