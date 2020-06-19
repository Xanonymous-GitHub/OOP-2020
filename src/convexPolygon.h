#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H

#include "shape.h"
#include "vector.h"
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class ConvexPolygon : public Shape {
private:
    vector<Vector> __entries;

    double __heronFormula(Vector pointA, Vector pointB, Vector pointC) const {
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

    Vector &__getCenter() {
        int dimension = __entries[0].dim();
        double entries[dimension];
        int amountOfSides = __entries.size();
        for (int vectorIndex = 0; vectorIndex < amountOfSides; vectorIndex++) {
            for (int dimensionIndex = 0; dimensionIndex < dimension; dimensionIndex++) {
                entries[dimensionIndex] += ((__entries[vectorIndex].at(dimensionIndex)) / amountOfSides);
            }
        }
        return *new Vector(entries, dimension);
    }

    void __sortVectors() {
        Vector center = __getCenter();
        int amountOfSides = __entries.size();
        Vector baseVector = __entries[0] - center;
        std::sort(__entries.begin() + 1, __entries.end(), [baseVector, center](Vector vectorA, Vector vectorB) {
            Vector
                A = vectorA - center,
                B = vectorB - center;
            double
                angleA = baseVector.angle(A),
                angleB = baseVector.angle(B);
            return angleA < angleB;
        });
    }

public:
    ConvexPolygon(vector<Vector> entries, string name) : Shape(name) {
        __entries.clear();
        __entries = entries;
        __sortVectors();
    }

    double perimeter() override {
        double perimeter = 0;
        int amountOfSides = __entries.size();
        for (int vectorIndex = 0; vectorIndex < amountOfSides; vectorIndex++) {
            perimeter += ((__entries[vectorIndex] - __entries[(vectorIndex + 1) % amountOfSides]).length());
        }
        return perimeter;
    }

    double area() override {
        double result = 0;
        if ((__entries.size() - 2) <= 0) {
            throw "not a polygon!";
        }
        int leftPointIndex = 1, rightPointIndex = 2;
        while (rightPointIndex <= __entries.size() - 1) {
            result += __heronFormula(__entries[0], __entries[leftPointIndex++], __entries[rightPointIndex++]);
        }
        return result;
    }

    string toString() override {
        stringstream result;
        result << "convex polygon {\n"
               << this->name() << endl;
        for (int i = 0; i < __entries.size(); i++) {
            result << __entries[i].toString() << endl;
        }
        result << "}\n";
        return result.str();
    }
};

#endif