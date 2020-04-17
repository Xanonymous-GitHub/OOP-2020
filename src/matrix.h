#ifndef MATRIX_H
#define MATRIX_H
#include "math_vector.h"

class Matrix {
public:
    Matrix(Matrix const &);
    Matrix(MathVector[], int, int);
    ~Matrix();
    double at(int, int) const;
    void rowReduction();
    void backSubstitution();
    MathVector gaussianElimination();
    MathVector getAllContent();

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
    int currentRow = 0;
    for (int j = 0; j < _column - 1; j++) {
        if (!_mathvectors[currentRow][j]) {
            for (int i = currentRow + 1; i < _row; i++) {
                if (_mathvectors[i][j]) {
                    swapMathVectorByPositions(currentRow, i);
                    break;
                }
            }
        }
        if (!_mathvectors[currentRow][j]) {
            continue;
        }
        if (_mathvectors[currentRow][j] != 1) {
            _mathvectors[currentRow] = _mathvectors[currentRow].scale(1 / _mathvectors[currentRow][j]);
        }
        for (int i = currentRow + 1; i < _row; i++) {
            if (_mathvectors[i][j]) {
                _mathvectors[i] = _mathvectors[i] + _mathvectors[j].scale(-_mathvectors[i][j]);
            }
        }
        if (at(currentRow + 1, j + 1)) {
            currentRow++;
        }
    }
    if (_mathvectors[_row - 1][_row - 1] != 1 && _mathvectors[_row - 1][_row - 1]) {
        _mathvectors[_row - 1] = _mathvectors[_row - 1].scale(1 / _mathvectors[_row - 1][_row - 1]);
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
    return getAllContent();
}

MathVector Matrix::getAllContent() {
    MathVector result(_row);
    for (int i = 0; i < _row; i++) {
        result[i] = at(i + 1, _column);
    }
    return result;
}

void Matrix::validError() {
    for (int i = 0; i < _row; i++) {
        double rowTotal = 0;
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
        for (int i = 0; i < _row; i++) {
            _mathvectors[i] = MathVector();
        }
    } else {
        for (int i = 0; i < _row; i++) {
            _mathvectors[i] = mathvectors[i];
        }
    }
}

#endif