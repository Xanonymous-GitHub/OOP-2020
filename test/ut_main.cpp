#include <gtest/gtest.h>

#include "./ut_binary.h"
#include "./ut_numeric.h"
// #include "./ut_util.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
