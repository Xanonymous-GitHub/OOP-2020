#ifndef HTML_H
#define HTML_H

#include "text.h"
#include <cstring>
#include <fstream>
#include <vector>

class Html {
public:
    void appendChild(Text child) {
        tags.push_back(child);
    }

    std::string render() {
        std::string result = "";
        result += html_head;
        for (int i = 0; i < this->tags.size(); i++) {
            result += tags[i].render();
        }
        result += html_end;
        return result;
    }

    void outputHtml() {
        std::ofstream file;
        // the main html file's name should be 'index.html', it's rule!
        file.open("main.html"); // Should not use illegal file name.
        file << this->render();
        file.close();
    }

private:
    std::vector <Text> tags ;
    const std::string html_head = "<html><body>";
    const std::string html_end = "</body></html>";
};

#endif
