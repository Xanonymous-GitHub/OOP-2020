#include "defines.h"
#include "p.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv, char **env) {
    $(long)
    c1, c2;
    long c1_data[] = {4, 3, 0, 1};
    long c2_data[] = {-1, 2, -3, -4};
    c1.$mount(c1_data);
    c2.$mount(c2_data);
    P p1(c1);
    P p2(c2);
    p2 = p1;
    show p2.get_poly() nl;
    show(p1 + p2).get_poly() nl;
    return 0;
}