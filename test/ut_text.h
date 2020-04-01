#include "../src/text.h"

TEST(TEXT, render) {
    Text t;
    ASSERT_EQ("<p style='color:#000000;font-size:16px;'></p>", t.render());
}
