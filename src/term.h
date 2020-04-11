#ifndef TERM_H
#define TERM_H
#define $Term(x) Term x(new_c, new_exponent);return x

class Term
{
public:
    // default constructor
    // default constructor should construct a term //
    // with coefficient 0 and exponent zero        //
    Term()
    {
        c = 0.0;
        exponent = 0;
    }

    // constructor
    Term(double coefficient, int exponent)
    {
        this->c = coefficient;
        this->exponent = exponent;
    }

    // operator assignment
    Term &operator=(Term const &t) // should return void. 
    {
        // a good advice: there should NOT return any type, should be "void".
        // Because the idea of assignment is just to change self, not returning new thing.
        c = t.c;
        exponent = t.exponent;
        return *this; // should not do this, not needed.
    }

    // operator add
    Term operator+(Term const &t)
    {
        double new_c = c + t.c;
        if (exponent != t.exponent)
        {
            throw "exponent not match!\n";
        }
        int new_exponent = exponent;
        $Term(new_term);
    }

    // operator multiply
    Term operator*(Term const &t)
    {
        double new_c = c * t.c;
        int new_exponent = exponent + t.exponent;
        $Term(new_term);
    }

    // operator equal
    bool operator==(Term const &t)
    {
        return (c == t.c && exponent == t.exponent);
    }

    // access coefficient of a term
    double getCoefficient() const
    {
        return c;
    }

    // access exponent of a term
    int getExponent() const
    {
        return exponent;
    }

    // evaluate by a given x
    double evaluate(double x)
    {
        int x_tmp = 1;
        for (int i = 0; i < exponent; i++)
        {
            x_tmp *= x;
        }
        return c * x_tmp;
    }

private:
    double c = 0.0;
    int exponent = 0;
};
#endif