#include "../src/matrix.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
    double d1[] = {4,4,0,28};
    double d2[] = {4,5,1,37};
    double d3[] = {16,20,8,168};
    MathVector m1(d1, 4), m2(d2, 4), m3(d3, 4);
    MathVector *ms = new MathVector[3];

    ms[0] = m1;
    ms[1] = m2;
    ms[2] = m3;
    // Matrix m(ms, 4, 5);
    Matrix m(ms, 3, 4);

    MathVector ans = m.gaussianElimination();

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << endl;
    }

    // Matrix M(m, 4, 5);
    // MathVector ans = M.gaussianElimination();
    // cout << m1[0] << endl;
    delete[] ms;
    return 0;
}