#ifndef MATRIX_H
#define MATRIX_H
#include "math_vector.h"

class Matrix {
public:
    Matrix(Matrix const &);
    Matrix(MathVector *, int, int);
    ~Matrix();
    double at(int, int) const;
    void rowReduction();
    void backSubstitution();
    MathVector gaussianElimination();

private:
    void initialize(MathVector *, int, int);
    void swapMathVectorByPositions(int, int);
    int _row, _column;
    MathVector *_mathvectors;
};

Matrix::Matrix(Matrix const &matrix) {
    initialize(matrix._mathvectors, matrix._row, matrix._column);
}

Matrix::Matrix(MathVector *mathvector, int row, int column) {
    initialize(mathvector, row, column);
}

Matrix::~Matrix() {
    if (_mathvectors) {
        delete[] _mathvectors;
    }
}

double Matrix::at(int row, int column) const {
    return _mathvectors[row][column];
}

void Matrix::rowReduction() {
    int currentRow = 0;
    for (int j = 0; j < _column; j++) {
        bool zeroColumn = true;
        for (int i = currentRow; i < _row; i++) {
            if (!_mathvectors[i][j]) {
                continue;
            }
            if (i != currentRow) {
                swapMathVectorByPositions(i, currentRow);
            }
            zeroColumn = false;
            _mathvectors[currentRow].scale(1 / _mathvectors[currentRow][j]);
            break;
        }
        if (zeroColumn) {
            continue;
        }
        for (int i = currentRow + 1; i < _row; i++) {
            if (_mathvectors[i][j]) {
                if (_mathvectors[i][j] > 0) {
                    _mathvectors[i].scale(-1.0);
                }
                _mathvectors[i] = _mathvectors[i] + _mathvectors[currentRow].scale(_mathvectors[currentRow][j]);
            }
        }
        currentRow++;
    }
}

void Matrix::backSubstitution() {
    int currentRow = _row - 1;
    for (int j = _column - 1; j >= 0; j--) {
        bool zeroColumn = true;
        for (int i = currentRow; i >=0; i--) {
            if (!_mathvectors[i][j]) {
                continue;
            }
            if (i != currentRow) {
                swapMathVectorByPositions(i, currentRow);
            }
            zeroColumn = false;
            _mathvectors[currentRow].scale(1 / _mathvectors[currentRow][j]);
            break;
        }
        if (zeroColumn) {
            continue;
        }
        for (int i = currentRow + 1; i < _row; i++) {
            if (_mathvectors[i][j]) {
                if (_mathvectors[i][j] > 0) {
                    _mathvectors[i].scale(-1.0);
                }
                _mathvectors[i] = _mathvectors[i] + _mathvectors[currentRow].scale(_mathvectors[currentRow][j]);
            }
        }
        currentRow++;
    }
}

MathVector Matrix::gaussianElimination() {
}

void Matrix::swapMathVectorByPositions(int i, int j) {
    MathVector tmpVector(_mathvectors[i]);
    _mathvectors[i] = _mathvectors[j];
    _mathvectors[j] = tmpVector;
}

inline void Matrix::initialize(MathVector *mathvectors, int row, int column) {
    if (_row != row || _column != column) {
        _mathvectors = new MathVector[_row];
    }
    _row = row;
    _column = column;
    if (mathvectors == nullptr) {
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