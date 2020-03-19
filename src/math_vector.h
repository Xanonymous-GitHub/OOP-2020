#include <cmath>
class MathVector {
private:
    double *_vec;
    int _dim;

public:
    MathVector(double *, int);
    ~MathVector();
    double component(int index);
    bool isZero();
    double length();
    int getDim();
};

MathVector::MathVector(double *data, int dim) {
    _dim = dim;
    _vec = new double[_dim];
    for (int i = 0; i < _dim; i++) {
        _vec[i] = data[i];
    }
}

MathVector::~MathVector() {
    delete _vec;
}

double MathVector::component(int index) {
    if (index > _dim)
        throw "index out of range!\n";
    return _vec[index - 1];
}

bool MathVector::isZero() {
    for (int i = 0; i < _dim; i++) {
        if (_vec[i])
            return false;
    }
    return true;
}

double MathVector::length() {
    double result;
    for (int i = 0; i < _dim; i++) {
        result += _vec[i] * _vec[i];
    }
    return sqrt(result);
}

int MathVector::getDim() {
    return _dim;
}