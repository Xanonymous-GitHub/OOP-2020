#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

class MathVector {
public:
    MathVector();
    MathVector(int);
    MathVector(double *, int);
    MathVector(MathVector const &);
    ~MathVector();
    MathVector &operator=(MathVector const &);
    MathVector operator+(MathVector &);
    MathVector &scale(double);
    double &operator[](int);
    int get_dimension() const;

private:
    void initialize(double *, int);
    double *_entries;
    int _dimension;
};

MathVector::MathVector() : _dimension(0), _entries(nullptr) {}

MathVector::MathVector(int dimension) {
    initialize(nullptr, dimension);
}

MathVector::MathVector(double *entries, int dimension) {
    initialize(entries, dimension);
}

MathVector::MathVector(MathVector const &mathVector) {
    initialize(mathVector._entries, mathVector.get_dimension());
}

MathVector::~MathVector() {
    if (_entries) {
        delete[] _entries;
    }
}

MathVector &MathVector::operator=(MathVector const &mathVector) {
    initialize(mathVector._entries, mathVector.get_dimension());
    return *this;
}

MathVector MathVector::operator+(MathVector &mathVector) {
    if (mathVector.get_dimension() != get_dimension()) {
        throw("");
    }
    for (int i = 0; i < get_dimension(); i++) {
        operator[](i) += mathVector[i];
    }
    return *this;
}

MathVector &MathVector::scale(double magnification) {
    for (int i = 0; i < get_dimension(); i++) {
        operator[](i) *= magnification;
    }
    return *this;
}

double &MathVector::operator[](int position) {
    if ((position + 1) > get_dimension()) {
        position = get_dimension() - 1;
    } else if (position < 0) {
        position = 0;
    }
    return _entries[position];
}

int MathVector::get_dimension() const {
    return _dimension;
}

inline void MathVector::initialize(double *entries, int dimension) {
    if (_dimension != dimension) {
        _entries = new double[_dimension];
    }
    _dimension = dimension;
    if (entries == nullptr) {
        for (int i = 0; i < _dimension; i++) {
            _entries[i] = 0;
        }
    } else {
        for (int i = 0; i < _dimension; i++) {
            _entries[i] = entries[i];
        }
    }
}

#endif