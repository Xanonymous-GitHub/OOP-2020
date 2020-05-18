#include "../src/polygon.h"
#include "../src/vector.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
    // double
    //     d1[] = {1, 2, 3, 4, 5, 6},
    //     d2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    // Vector v1(d1, 6), v2(d2, 7);
    // for (int i = 0; i < 6; i++) {
    //     cout << i + 1 << " -> " << v1.at(i + 1) << endl;
    // }
    // for (int i = 0; i < 7; i++) {
    //     cout << (i + 1) * 1.1 << " -> " << v2.at(i + 1) << endl;
    // }

    // double
    //     d1[] = {1, 2, 3, 4, 5, 6},
    //     d2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7},
    //     d3[] = {-1, -2, -3, -4, -5, -6};
    // Vector v3(d1, 6), v4(d2, 7), v5(d3, 6);
    // Vector v3PlusV5 = v5+ v3;
    // for (int i = 0; i < 6; i++) {
    //     cout << 0 << " -> " << v3PlusV5.at(i + 1) << endl;
    // }

    // double d1[] = {3, 4}, d2[] = {7, 24};
    // Vector v9(d1, 2), v10(d2, 2);
    // cout << 5 << " -> " << v9.length() << endl;
    // cout << 25 << " -> " << v10.length() << endl;
    double d1[] = {3, 4}, d2[] = {7, 24};
    Vector v11(d1, 2), v12(d2, 2);
    cout << 0.359707 << " -> " << v11.angle(v12) << endl;
    double d3[] = {5, 12}, d4[] = {9, 40};
    Vector v14(d3, 2), v13(d4, 2);
    cout << 0.173477 << " -> " << v13.angle(v14) << endl;
    return 0;
}