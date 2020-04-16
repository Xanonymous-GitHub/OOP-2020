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
    double *new_entries = new double[get_dimension()];
    for (int i = 0; i < get_dimension(); i++) {
        new_entries[i] = operator[](i) + mathVector[i];
    }
    MathVector *new_MathVector = new MathVector(new_entries, get_dimension());
    delete[] new_entries;
    return *new_MathVector;
}

MathVector &MathVector::scale(double magnification) {
    double *new_entries = new double[get_dimension()];
    for (int i = 0; i < get_dimension(); i++) {
        new_entries[i] = operator[](i) * magnification;
    }
    MathVector *new_MathVector = new MathVector(new_entries, get_dimension());
    delete[] new_entries;
    return *new_MathVector;
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

void MathVector::initialize(double *entries, int dimension) {
    _entries = new double[dimension];
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