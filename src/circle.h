#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "vector.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Circle : public Shape {
private:
    double __radius;
    Vector __origin;

public:
    Circle() {
        __radius = 0.0f;
        __origin = *new Vector(2);
    }

    Circle(int radius) {
        __radius = radius;
        __origin = *new Vector(2);
    }

    Circle(double radius, string name) : Shape(name) {
        __radius = radius;
        __origin = *new Vector(2);
    }

    Circle(double radius, string name, Vector origin) : Shape(name) {
        __radius = radius;
        __origin = origin;
    }

    double area() override {
        return __radius * __radius * M_PI;
    }

    double perimeter() override {
        return 2 * M_PI * __radius;
    }

    string toString() override {
        stringstream result;
        result << "circle {\n"
               << this->name() << endl
               << __origin.toString() << endl
               << __radius << endl
               << "}\n";
        return result.str();
    }
};

#endif