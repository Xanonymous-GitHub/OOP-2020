#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Vector {
private:
    vector<double> __vector;

    double __innerProduct(Vector other_vector) const {
        if (other_vector.dim() != this->dim()) {
            throw "dimension not match!";
        }
        double result = 0;
        for (int entryIndex = 0; entryIndex < this->dim(); entryIndex++) {
            result += __vector[entryIndex] * other_vector.at(entryIndex);
        }
        return result;
    }

    bool __partOuterProduct(Vector other_vector) const {
        return this->area(other_vector) > 0;
    }

public:
    Vector() {
        __vector.clear();
    }

    Vector(int length) {
        __vector.clear();
        for (int i = 0; i < length; i++) {
            __vector.push_back(0);
        }
    }

    Vector(double *new_vector, int length) {
        __vector.clear();
        for (int i = 0; i < length; i++) {
            __vector.push_back(new_vector[i]);
        }
    }

    Vector(vector<double> new_vector, int length) {
        __vector.clear();
        for (int i = 0; i < length; i++) {
            __vector.push_back(new_vector[i]);
        }
    }

    double area(Vector other_vector) const {
        return ((this->at(0) * other_vector.at(1)) - (this->at(1) * other_vector.at(0))) / 2;
    }

    double at(int index) const {
        int vector_size = __vector.size();
        if ((!vector_size) || index < 0 || index > vector_size - 1) {
            throw "no";
        }
        return __vector[index];
    }

    int dim() const {
        if (__vector.size() == 0) {
            return -1; // WTF? so...
        }
        return __vector.size();
    }

    double length() const {
        double result = 0;
        int vector_size = this->dim();
        for (int i = 0; i < vector_size; i++) {
            result += __vector[i] * __vector[i];
        }
        return sqrt(result);
    }

    string toString() const {
        string result = "(";
        int vector_size = this->dim();
        for (int i = 0; i < vector_size; i++) {
            stringstream stream;
            string tmp;
            stream << __vector[i];
            stream >> tmp;
            result += tmp;
            if (i < vector_size - 1) {
                result += ",";
            }
        }
        result.push_back(')');
        return result;
    }

    Vector &operator+(const Vector &other_vector) {
        if (other_vector.dim() != this->dim()) {
            throw "no";
        }
        int vector_size = this->dim();
        double *new_vector_entries = new double[vector_size];
        for (int i = 0; i < vector_size; i++) {
            new_vector_entries[i] = (this->at(i) + other_vector.at(i));
        }
        return *new Vector(new_vector_entries, vector_size);
    }

    Vector &operator-(const Vector &other_vector) {
        if (other_vector.dim() != this->dim()) {
            throw "no";
        }
        int vector_size = this->dim();
        double *new_vector_entries = new double[vector_size];
        for (int i = 0; i < vector_size; i++) {
            new_vector_entries[i] = (this->at(i) - other_vector.at(i));
        }
        return *new Vector(new_vector_entries, vector_size);
    }

    Vector &operator=(const Vector &other_vector) {
        int vector_size = other_vector.dim();
        __vector.clear();
        for (int i = 0; i < vector_size; i++) {
            __vector.push_back(other_vector.at(i));
        }
        return *this;
    }

    double angle(Vector other_vector) const {
        double result = acos(__innerProduct(other_vector) / (this->length() * other_vector.length()));
        if (!(__partOuterProduct(other_vector))) {
            result = 2 * M_PI - result;
        }
        return result;
    }
};

#endif