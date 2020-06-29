#include <iostream>
#include <fstream>
#include "html.h"
#include "text.h"
#include "image.h"
#include "color.h"
#include "size.h"
#include "color.h"
#include "fontsize.h"
#include "position.h"
#include "util.h"

using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    // handle argument exception
    if (argc < 4)
    {
        return -1;
    }

    // translate input arguments
    std::string inputFile = argv[1];
    std::string columnIndex = argv[2];
    std::string order = argv[3];

    Html html;
    html.appendTag(&tableFromFile(inputFile));
    html.outputHtml();
    return 0;
}
