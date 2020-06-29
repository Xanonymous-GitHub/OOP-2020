#ifndef HTML_H
#define HTML_H

#include "tag.h"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Html
{
private:
    vector<Tag *> tags;
    const string html_head = "<HTML><body>";
    const string html_end = "</body></HTML>";

public:
    void appendTag(Tag *child)
    {
        tags.push_back(child);
    }

    string render()
    {
        string result = "";
        result += html_head;
        for (auto tag : tags)
        {
            result += tag->render();
        }
        result += html_end;
        return result;
    }

    void outputHtml()
    {
        ofstream file;
        file.open("main.html");
        file << this->render();
        file.close();
    }
};

#endif
