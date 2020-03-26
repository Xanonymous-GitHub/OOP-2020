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
        /*
            All websites are a collection of files in folders. 
            Loading a page is essentially picking out the file out want to display and the browser then loading it. 
            If you point out the exact file, then you wouldn't need the "index" page, 
            but in order to make it easier, the standards "W3C"set decided that if a file wasn't mentioned, 
            the server should look for either index or default. Those are the two options.
            "Index" literally means a list of items in a book so it made a good parallel and has become the more popular option by far.
            
            Hope you can fix it next time ~ 

                    Best Regards, Xanonymous.
        */
        file.open("main.html"); // Should not use illegal file name.
        file << this->render();
        file.close();
    }

private:

    /*
        Although html files are accustomed to using lowercase tags, 
        uppercase tags will not cause browsers to display errors, 
        but mixed case is not recommended, 
        because this will lead to confusing file layout and unclear structure.

        Hope you can fix it next time ~ 

                Best Regards, Xanonymous.
    */

    std::vector <Text> tags ;
    const std::string html_head = "<HTML><body>";
    const std::string html_end = "</body></HTML>";
};

#endif
