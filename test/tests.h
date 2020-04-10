#include "../src/defines.h"
#include "../src/p.h"
TEST(operator, plus) {
    $v(long)
        c1,
        c2;
    long c1_data[] = {1, 2, 3, 4, 5};
    long c2_data[] = {-2, 2, 1};
    c1.$mount(c1_data);
    c2.$mount(c2_data);
    P p1(c1), p2(c2);
    
}

TEST(operator, minus) {
}

TEST(operator, multiple) {
}