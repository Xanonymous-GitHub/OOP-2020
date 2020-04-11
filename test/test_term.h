#include "../src/term.h"
TEST(Term, default_constructor)
{
    Term term();
    ASSERT_NEAR(0.0, term.getCoefficient(), 0.001);
    ASSERT_EQ(0, term.getExponent());
}
TEST(Term, constructor)
{
    double coefficient = 194.87f;
    int exponent = 8;
    Term term(coefficient, exponent);
    ASSERT_NEAR(194.87, term.getCoefficient(), 0.001);
    ASSERT_EQ(8, term.getExponent());
}
TEST(Term, operator_assignment)
{
    double coefficient1 = 193.6f, coefficient2 = 64.31f;
    int exponent1 = 4, exponent2 = 3;
    Term term1(coefficient1, exponent1), term2(coefficient2, exponent2);
    term1 = term2;
    ASSERT_NEAR(64.31, term1.getCoefficient(), 0.001);
    ASSERT_EQ(3, term1.getExponent());
}
TEST(Term, operator_add)
{
    double coefficient1 = 3.2f, coefficient2 = 2.3f, coefficient3 = 44.44f;
    int exponent1 = 3, exponent2 = 3, exponent3 = 4;
    Term term1(coefficient1, exponent1), term2(coefficient2, exponent2), term3(coefficient3, exponent3);
    Term term = (term1 + term2);
    ASSERT_NEAR(5.5, term.getCoefficient(), 0.001);
    ASSERT_EQ(3, term.getExponent());
    ASSERT_ANY_THROW(term3 + term2);
}
TEST(Term, operator_multiply)
{
    double coefficient1 = 3114.44f, coefficient2 = 3114.0f;
    int exponent1 = 9, exponent2 = 3;
    Term term1(coefficient1, exponent1), term2(coefficient2, exponent2);
    Term term = (term1 * term2);
    ASSERT_NEAR(9698366.16, term.getCoefficient(), 0.001);
    ASSERT_EQ(12, term.getExponent());
}
TEST(Term, operator_equal)
{
    double coefficient1 = 64.31f, coefficient2 = 64.31f, coefficient3 = 31.64f, coefficient4 = 31.64f;
    int exponent1 = 3, exponent2 = 3, exponent3 = 4, exponent4 = 5;
    Term term1(coefficient1, exponent1), term2(coefficient2, exponent2), term3(coefficient3, exponent3), term4(coefficient4, exponent4);
    ASSERT_TRUE(term1 == term2);
    ASSERT_FALSE(term2 == term3);
    ASSERT_FALSE(term3 == term4);
}
TEST(Term, access_coefficient_of_a_term)
{
    double coefficient1 = 64.44f;
    int exponent1 = 3;
    Term term1(coefficient1, exponent1);
    Term term2();
    ASSERT_NEAR(64.44, term1.getCoefficient(), 0.001);
    ASSERT_NEAR(0.0, term2.getCoefficient(), 0.001);
}
TEST(Term, access_exponent_of_a_term)
{
    double coefficient1 = 64.44f;
    int exponent1 = 3;
    Term term1(coefficient1, exponent1);
    Term term2();
    ASSERT_EQ(3, term1.getExponent());
    ASSERT_EQ(0, term2.getExponent());
}

TEST(Term, evaluate_by_a_given_x)
{
    double coefficient1 = 64.44f;
    int exponent1 = 3;
    double x = 19.1;
    Term term1(coefficient1, exponent1);
    Term term2();
    ASSERT_NEAR(449009.60724, term1.evaluate(x), 0.001);
    ASSERT_NEAR(0.0, term2.evaluate(x), 0.001);
}
