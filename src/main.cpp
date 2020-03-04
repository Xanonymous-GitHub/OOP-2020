#include "dot.h"
#include <iostream>
int main() {
    double u[2] = {1, 0};
    double v[2] = {1, 1};
    double result = dot(u, 2, v, 2);
    std::cout << result << std::endl;
    return 0;
}
