#ifndef POLYGON_H
#define POLYGON_H

#include "./vector.h"
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Polygon {
private:
    Vector *_vectors;
    int _amountOfSides;
    double __heronFormula(Vector, Vector, Vector) const;
    void __sortVectors();
    Vector &__getCenter();

public:
    Polygon();
    Polygon(Vector[], int);
    ~Polygon();
    Vector point(int);
    int sides();
    double perimeter();
    double area();
};

Polygon::Polygon() {
    _vectors = nullptr;
    _amountOfSides = -1;
}

Polygon::Polygon(Vector vectors[], int amountOfSides) {
    _amountOfSides = amountOfSides;
    _vectors = new Vector[_amountOfSides];
    for (int vectorIndex = 0; vectorIndex < _amountOfSides; vectorIndex++) {
        _vectors[vectorIndex] = vectors[vectorIndex];
    }
    __sortVectors();
}

Polygon::~Polygon() {
    delete[] _vectors;
    _vectors = nullptr;
}

Vector Polygon::point(int position) {
    if (position < 0 || position > _amountOfSides) {
        throw "cc";
    }
    return _vectors[position - 1];
}

int Polygon::sides() {
    return _amountOfSides;
}

double Polygon::perimeter() {
    double perimeter = 0;
    for (int vectorIndex = 0; vectorIndex < _amountOfSides; vectorIndex++) {
        perimeter += ((_vectors[vectorIndex] - _vectors[(vectorIndex + 1) % _amountOfSides]).length());
    }
    return perimeter;
}

Vector &Polygon::__getCenter() {
    int dimension = _vectors[0].dim();
    double entries[dimension];
    for (int vectorIndex = 0; vectorIndex < _amountOfSides; vectorIndex++) {
        for (int dimensionIndex = 0; dimensionIndex < dimension; dimensionIndex++) {
            entries[dimensionIndex] += ((_vectors[vectorIndex].at(dimensionIndex + 1)) / _amountOfSides);
        }
    }
    return *new Vector(entries, dimension);
}

void Polygon::__sortVectors() {
    Vector center = __getCenter();
    Vector baseVector = _vectors[0] - center;
    std::sort(_vectors, _vectors + _amountOfSides, [baseVector, center](Vector vectorA, Vector vectorB) {
        Vector
            A = vectorA - center,
            B = vectorB - center;
        double
            angleA = baseVector.angle(A),
            angleB = baseVector.angle(B);
        return angleA > angleB;
    });
}

double Polygon::__heronFormula(Vector pointA, Vector pointB, Vector pointC) const {
    Vector
        a = pointA - pointB,
        b = pointB - pointC,
        c = pointC - pointA;
    Vector triangle[3] = {a, b, c};
    double
        A = a.length(),
        B = b.length(),
        C = c.length();
    double S = 0.5 * (A + B + C);
    return (double)sqrt(S * (S - A) * (S - B) * (S - C));
}

double Polygon::area() {
    double result = 0;
    if ((_amountOfSides - 2) <= 0) {
        throw "not a polygon!";
    }
    int leftPointIndex = 1, rightPointIndex = 2;
    while (rightPointIndex <= _amountOfSides - 1) {
        result += __heronFormula(_vectors[0], _vectors[leftPointIndex++], _vectors[rightPointIndex++]);
    }
    return result;
}

template <class RandomAccessIterator, class Condition>
vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition condition) {
    vector<Polygon *> result;
    for (auto _iterator = begin; _iterator != end; _iterator++) {
        if (condition(*_iterator)) {
            result.push_back(*_iterator);
        }
    }
    return result;
};

#endif