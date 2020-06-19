#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
private:
    string _name;

public:
    Shape() {
        _name = "anonymous";
    }

    Shape(string name) {
        _name = name;
    }

    virtual ~Shape() {
    }

    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string toString() = 0;
    string name() {
        return _name;
    }
};

#endif