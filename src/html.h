#ifndef HTML_H
#define HTML_H

#include "image.h"
#include "text.h"
#include <cstring>
#include <fstream>
#include <vector>

typedef std::string s;
class Html {
public:
    void appendText(Text child) {
        this->texts += child.render();
    }

    void appendImage(Image child) {
        this->images += child.render();
    }

    s render() {
        return this->html_head + this->images + this->texts + this->html_end;
    }

    void outputHtml() {
        std::ofstream file;
        file.open("main.html");
        file << this->render();
        file.close();
    }

private:
    s texts;
    s images;
    const s html_head = "<HTML><body>";
    const s html_end = "</body></HTML>";
};

#endif
