#include <gtest/gtest.h>
#include "test_term.h"
#include "test_polynomial.h"
int main(int argc, char **argv)
{
    testing ::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
