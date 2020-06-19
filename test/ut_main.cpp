#include <gtest/gtest.h>

#include "./ut_circle.h"
#include "./ut_convexPolygon.h"
#include "./ut_util.h"
#include "./ut_vector.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
