#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class Vector {
private:
    int _dimension;
    double *_entries;
    double __innerProduct(Vector) const;

public:
    Vector();
    Vector(double[], int);
    int dim();
    double at(int);
    Vector &operator+(Vector);
    Vector &operator-(Vector);
    bool operator==(Vector);
    double length() const;
    double angle(Vector) const;
    bool partOuterProduct(Vector) const;
};

Vector::Vector() {
    _dimension = -1;
    _entries = nullptr;
}

Vector::Vector(double entries[], int dimension) {
    _dimension = dimension;
    _entries = new double[_dimension];
    for (int entryIndex = 0; entryIndex < _dimension; entryIndex++) {
        _entries[entryIndex] = entries[entryIndex];
    }
}

int Vector::dim() {
    return _dimension;
}

double Vector::at(int position) {
    if (position < 0 || position > _dimension) {
        throw "haha";
    }
    return _entries[position - 1];
}

Vector &Vector::operator+(Vector otherVector) {
    if (otherVector.dim() != _dimension) {
        throw "dimension not match!";
    }
    double *newEntries = new double[_dimension];
    for (int entryIndex = 0; entryIndex < _dimension; entryIndex++) {
        newEntries[entryIndex] = (_entries[entryIndex] + otherVector._entries[entryIndex]);
    }
    Vector *newVector = new Vector(newEntries, _dimension);
    delete[] newEntries;
    return *newVector;
}

Vector &Vector::operator-(Vector otherVector) {
    if (otherVector.dim() != _dimension) {
        throw "dimension not match!";
    }
    double *newEntries = new double[_dimension];
    for (int entryIndex = 0; entryIndex < _dimension; entryIndex++) {
        newEntries[entryIndex] = (_entries[entryIndex] - otherVector._entries[entryIndex]);
    }
    Vector *newVector = new Vector(newEntries, _dimension);
    delete[] newEntries;
    return *newVector;
}

bool Vector::operator==(Vector otherVector) {
    if (otherVector.dim() == _dimension) {
        for (int entryIndex = 0; entryIndex < _dimension; entryIndex++) {
            if (_entries[entryIndex] != otherVector.at(entryIndex + 1)) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

double Vector::length() const {
    double result = 0;
    for (int entryIndex = 0; entryIndex < _dimension; entryIndex++) {
        result += _entries[entryIndex] * _entries[entryIndex];
    }
    return (double)sqrt(result);
}

double Vector::__innerProduct(Vector otherVector) const {
    if (otherVector.dim() != _dimension) {
        throw "dimension not match!";
    }
    double result = 0;
    for (int entryIndex = 0; entryIndex < _dimension; entryIndex++) {
        result += this->_entries[entryIndex] * otherVector.at(entryIndex + 1);
    }
    return result;
}

double Vector::angle(Vector otherVector) const {
    double result = acos(__innerProduct(otherVector) / (this->length() * otherVector.length()));
    if (!(partOuterProduct(otherVector))) {
        result = 2 * M_PI - result;
    }
    return result;
}

bool Vector::partOuterProduct(Vector otherVector) const {
    double result = _entries[0] * otherVector.at(2) - _entries[1] * otherVector.at(1);
    return result > 0;
}

#endif