#ifndef MATRIX_H
#define MATRIX_H
#include "iostream"
#include "math_vector.h"
using namespace std;

class Matrix {
public:
    Matrix(Matrix const &);
    Matrix(MathVector[], int, int);
    ~Matrix();
    double at(int, int) const;
    void rowReduction();
    void backSubstitution();
    MathVector gaussianElimination();

private:
    void initialize(MathVector *, int, int);
    void swapMathVectorByPositions(int, int);
    void validError();
    int _row, _column;
    MathVector *_mathvectors;
};

Matrix::Matrix(Matrix const &matrix) {
    initialize(matrix._mathvectors, matrix._row, matrix._column);
}

Matrix::Matrix(MathVector *mathvector, int row, int column) {
    for (int i = 0; i < row; i++) {
        if (mathvector[i].dimension() != column) {
            throw("");
        }
    }
    initialize(mathvector, row, column);
}

Matrix::~Matrix() {
    if (_mathvectors) {
        delete[] _mathvectors;
    }
}

double Matrix::at(int row, int column) const {
    return _mathvectors[row - 1][column - 1];
}

void Matrix::rowReduction() {
    for (int j = 0; j < _column - 1; j++) {
        if (!_mathvectors[j][j]) {
            for (int i = j + 1; i < _row; i++) {
                if (_mathvectors[i][j]) {
                    swapMathVectorByPositions(j, i);
                    break;
                }
            }
        }
        if (_mathvectors[j][j] != 1) {
            _mathvectors[j] = _mathvectors[j].scale(1 / _mathvectors[j][j]);
        }
        for (int i = j + 1; i < _row; i++) {
            if (_mathvectors[i][j]) {
                _mathvectors[i] = _mathvectors[i] + _mathvectors[j].scale(-_mathvectors[i][j]);
            }
        }
    }
    if (_mathvectors[_row][_row] != 1) {
        _mathvectors[_row] = _mathvectors[_row].scale(1 / _mathvectors[_row][_row]);
    }
}

void Matrix::backSubstitution() {
    for (int i = 0; i < _row; i++) {
        for (int j = i + 1; j < _column - 1; j++) {
            if (_mathvectors[i][j]) {
                _mathvectors[i] = _mathvectors[i] + _mathvectors[j].scale(-_mathvectors[i][j]);
            }
        }
    }
}

MathVector Matrix::gaussianElimination() {
    rowReduction();
    validError();
    backSubstitution();
    MathVector result(_row);
    for (int i = 0; i < _row; i++) {
        result[i] = at(i + 1, _column);
    }
    return result;
}

void Matrix::validError() {
    double rowTotal = 0;
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _column - 1; j++) {
            rowTotal += at(i + 1, j + 1);
        }
        if (!rowTotal) {
            throw("");
        }
    }
}

void Matrix::swapMathVectorByPositions(int i, int j) {
    MathVector tmpVector(_mathvectors[i]);
    _mathvectors[i] = _mathvectors[j];
    _mathvectors[j] = tmpVector;
}

void Matrix::initialize(MathVector *mathvectors, int row, int column) {
    _mathvectors = new MathVector[row];
    _row = row;
    _column = column;
    if (!mathvectors) {
        for (int i = 0; i < _column; i++) {
            _mathvectors[i] = MathVector();
        }
    } else {
        for (int i = 0; i < _column; i++) {
            _mathvectors[i] = mathvectors[i];
        }
    }
}

#endif