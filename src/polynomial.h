#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "./term.h"
#include <iostream>
class Polynomial
{
public:
    // consturctor
    Polynomial(Term *terms, int degree)
    {
        this->degree = degree;
        int size_of_c = degree + 1;
        c = new Term[size_of_c];
        degree = 0;
        for (int i = 0; i < size_of_c; i++)
        {
            c[i] = Term(terms[i].getCoefficient(), i);
            int degree_from_terms = terms[i].getExponent();
            if (degree_from_terms > degree)
                degree = degree_from_terms;
        }
    }

    // copy constructor
    Polynomial(Polynomial const &p)
    {
        degree = p.degree;
        int size_of_c = degree + 1;
        c = new Term[size_of_c];
        for (int i = 0; i < size_of_c; i++)
        {
            c[i] = Term(p.c[i].getCoefficient(), i);
        }
    }

    // destructor
    ~Polynomial()
    {
        delete[] c;
    }

    // operator assignment
    Polynomial &operator=(const Polynomial &p)
    {
        degree = p.degree;
        int size_of_c = degree + 1;
        c = new Term[size_of_c];
        for (int i = 0; i < size_of_c; i++)
        {
            c[i] = Term(p.c[i].getCoefficient(), i);
        }
        return *this;
    }

    // operator add
    Polynomial operator+(const Polynomial &p)
    {
        // true => self is bigger; false => other is bigger.
        bool size_relationship = degree >= p.degree;
        int smaller_degree = (size_relationship ? p.degree : degree);
        int bigger_degree = (size_relationship ? degree : p.degree);
        int size_of_c = bigger_degree + 1;
        Term new_terms[size_of_c];
        for (int i = 0; i < size_of_c; i++)
        {
            double self_c = c[i].getCoefficient();
            double other_c = p.c[i].getCoefficient();
            new_terms[i] = Term((i <= smaller_degree) ? self_c + other_c : (size_relationship ? self_c : other_c), i);
        }
        Polynomial new_poly(new_terms, bigger_degree);
        return new_poly;
    }

    bool operator==(const Polynomial &p)
    {
        if (p.degree != this->degree)
        {
            return false;
        }
        for (int i = 0; i < p.degree + 1; i++)
        {
            if (p.c[i].getCoefficient() != c[i].getCoefficient())
                return false;
        }
        return true;
    }

    // get designate term by exponent
    Term getTermByExponent(int exponent)
    {
        if (exponent > degree)
        {
            throw "not have this Term!";
        }
        else
        {
            Term packed_term(c[exponent].getCoefficient(), exponent);
            return packed_term;
        }
    }

    // degree of polynomial
    int getDegree()
    {
        return degree;
    }

    // evaluate by a given x
    double evaluate(double x)
    {
        int size = degree + 1;
        double result = 0.0;
        for (int i = 0; i < size; i++)
        {
            result += c[i].evaluate(x);
        }
        return result;
    }

private:
    Term *c;
    int degree = 0;
};
#endif