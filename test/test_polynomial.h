#include "../src/polynomial.h"
TEST(Poly, consturctor)
{
    const int degree1 = 6, degree2 = 0;
    Term terms1[degree1 + 1], terms2[degree2 + 1];
    double c1[] = {1, 2, 3, 4.2, -5, 6, 7}, c2 = 0.0;
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    terms2[0] = Term(c2, 0);
    Polynomial poly1(terms1, degree1), poly2(terms2, 0);
    ASSERT_EQ(degree1, poly1.getDegree());
    ASSERT_EQ(0, poly2.getDegree());
    for (int i = 0; i < degree1 + 1; i++)
    {
        ASSERT_NEAR(c1[i], poly1.getTermByExponent(i).getCoefficient(), 0.001);
    }
    ASSERT_NEAR(0, poly2.getTermByExponent(0).getCoefficient(), 0.001);
}
TEST(Poly, copy_constructor)
{
    const int degree1 = 6, degree2 = 3;
    Term terms1[degree1 + 1], terms2[degree2 + 1];
    double c1[] = {1, 2, 3, 4.2, -5, 6, 7}, c2[] = {0, 1, 2, 3};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    for (int i = 0; i < degree2 + 1; i++)
    {
        terms2[i] = Term(c2[i], i);
    }
    Polynomial poly1(terms1, degree1);
    Polynomial poly2(poly1);
    ASSERT_EQ(degree1, poly2.getDegree());
    for (int i = 0; i < degree1 + 1; i++)
    {
        ASSERT_NEAR(c1[i], poly2.getTermByExponent(i).getCoefficient(), 0.001);
    }
}
TEST(Poly, operator_assignment)
{
    const int degree1 = 6, degree2 = 3;
    Term terms1[degree1 + 1], terms2[degree2 + 1];
    double c1[] = {1, 2, 3, 4.2, -5, 6, 7}, c2[] = {0, 1, 2, 3};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    for (int i = 0; i < degree2 + 1; i++)
    {
        terms2[i] = Term(c2[i], i);
    }
    Polynomial poly1(terms1, degree1), poly2(terms2, degree2);
    poly2 = poly1;
    ASSERT_EQ(degree1, poly2.getDegree());
    for (int i = 0; i < degree1 + 1; i++)
    {
        ASSERT_NEAR(c1[i], poly2.getTermByExponent(i).getCoefficient(), 0.001);
    }
}
TEST(Poly, operator_add)
{
    const int degree1 = 6, degree2 = 3;
    Term terms1[degree1 + 1], terms2[degree2 + 1];
    double c1[] = {1, 2, 3, 4.2, -5, 6, 7}, c2[] = {0, 1, 2, 3}, ans[] = {1, 3, 5, 7.2, -5, 6, 7};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    for (int i = 0; i < degree2 + 1; i++)
    {
        terms2[i] = Term(c2[i], i);
    }
    Polynomial poly1(terms1, degree1), poly2(terms2, degree2);
    Polynomial poly = (poly2 + poly1);
    ASSERT_EQ(degree1, poly.getDegree());
    for (int i = 0; i < degree1 + 1; i++)
    {
        ASSERT_NEAR(ans[i], poly.getTermByExponent(i).getCoefficient(), 0.001);
    }
}
TEST(Poly, get_designate_term_by_exponent)
{
    const int degree1 = 6;
    Term terms1[degree1 + 1];
    double c1[] = {1, 2, 3, 4.2, -5, 6, 7};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    Polynomial poly1(terms1, degree1);
    for (int i = 0; i < degree1 + 1; i++)
    {
        ASSERT_NEAR(c1[i], poly1.getTermByExponent(i).getCoefficient(), 0.001);
    }
    ASSERT_ANY_THROW(poly1.getTermByExponent(8).getCoefficient());
}

TEST(Poly, degree_of_polynomial)
{
    const int degree1 = 6;
    Term terms1[degree1 + 1];
    double c1[] = {1, 2, 3, 4.2, -5, 6, 7};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    Polynomial poly1(terms1, degree1);
    ASSERT_EQ(degree1, poly1.getDegree());
}

TEST(Poly, degree_of_polynomial_zero)
{
    const int degree1 = 0;
    Term terms1[degree1 + 1];
    double c1[] = {1};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    Polynomial poly1(terms1, degree1);
    ASSERT_EQ(degree1, poly1.getDegree());
}

TEST(Poly, evaluate_by_a_given_x)
{
    const int degree1 = 3;
    Term terms1[degree1 + 1];
    double x = 2;
    double c1[] = {2, 3, 4.2, -5};
    for (int i = 0; i < degree1 + 1; i++)
    {
        terms1[i] = Term(c1[i], i);
    }
    Polynomial poly1(terms1, degree1);
    ASSERT_NEAR(-15.2, poly1.evaluate(x), 0.001);
}
