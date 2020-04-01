#ifndef HTML_H
#define HTML_H

#include "image.h"
#include "text.h"

#include <cstring>
#include <fstream>
#include <vector>

class Html {
public:
    void appendText(Text child) {
    }

    void appendImage(Image child) {
    }

    std::string render() {
    }

    void outputHtml() {
        std::ofstream file;
        file.open("main.html");
        file << this->render();
        file.close();
    }

private:
    std::vector<Text> texts;
    std::vector<Image> images;
    const std::string html_head = "<HTML><body>";
    const std::string html_end = "</body></HTML>";
};

#endif
