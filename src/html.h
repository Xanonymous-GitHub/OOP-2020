#ifndef HTML_H
#define HTML_H

#include "text.h"
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;
class Html {
private:
    vector<Text> tags;
    const string html_head = "<HTML><body>";
    const string html_end = "</body></HTML>";

public:
    void appendChild(Text child) {
    }

    string render() {
    }

    void outputHtml() {
        ofstream file;
        // the main html file's name should be 'index.html', it's rule!
        file.open("main.html");
        file << this->render();
        file.close();
    }
};

#endif
