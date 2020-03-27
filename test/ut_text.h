#include "../src/text.h"

TEST(Text, render) {
    Text t;
    t.setText("oeincuoaingcog49w84c9g8rhc9");
    ASSERT_EQ("<p>oeincuoaingcog49w84c9g8rhc9</p>", t.render());
    t.setText("");
    ASSERT_EQ("<p></p>", t.render());
}

TEST(Text, setText) {
    Text t;
    t.setText("shnihow8c8hfoinhcfihfsn84fchsn");
    ASSERT_EQ("<p>shnihow8c8hfoinhcfihfsn84fchsn</p>", t.render());
    t.setText("");
    ASSERT_EQ("<p></p>", t.render());
}

TEST(Text, empty) {
    Text t;
    ASSERT_EQ("<p></p>", t.render());
}