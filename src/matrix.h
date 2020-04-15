#ifndef MATRIX_H
#define MATRIX_H
#include "math_vector.h"

class Matrix {
public:
    Matrix(Matrix const &);
    Matrix(MathVector, int, int);
    ~Matrix();
    double at(int, int) const;
    void rowReduction();
    void backSubstitution();
    MathVector gaussianElimination();

private:
    int _row, _column;
    MathVector *_mathvectors;
};

#endif
