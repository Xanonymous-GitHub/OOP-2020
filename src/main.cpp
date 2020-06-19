#include "util.h"

#include <iostream>
#include <vector>

int main(int argc, char **argv) {

    // // handle argument exception
    // if (argc < 5) {
    //     std::cout << "Usage:" << std::endl;
    //     std::cout << "\tgeo ${input_file} ${output_file} ${compare_target} ${order}" << std::endl;
    //     std::cout << "Options:" << std::endl;
    //     std::cout << "\t${compare_target} can be either \"area\" "
    //                  "or \"perimeter\""
    //               << std::endl;
    //     std::cout << "\t${order} can be either \"inc\" or \"dec\"" << std::endl;
    //     return -1;
    // }

    // // translate input arguments
    // std::string inputFile = argv[1];
    // std::string outputFile = argv[2];
    // std::string compare = argv[3];
    // std::string order = argv[4];

    // get a list of shape from a given text file
    // std::vector<Shape *> shapes = handleInput(inputFile);
    std::vector<Shape *> shapes = handleInput("shape_data_3");

    // // sort these shapes by given conditions
    // std::vector<Shape *> sortedShapes = handleSort(shapes, compare, order);

    // // finally, output the sorted shapes to a text file
    // handleOutput(outputFile, sortedShapes);

    return 0;
}
