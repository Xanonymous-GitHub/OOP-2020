#include "../src/color.h"
#include "../src/fontsize.h"
#include "../src/position.h"
#include "../src/size.h"

TEST(STYLE, color_default) {
    Color c;
    ASSERT_EQ("color:#000000;", c.renderStyle());
}

TEST(STYLE, color_set_the_color) {
    Color c("#FFFFFF");
    ASSERT_EQ("color:#FFFFFF;", c.renderStyle());
}

TEST(STYLE, fontsize_default) {
    FontSize fs;
    ASSERT_EQ("font-size:16px;", fs.renderStyle());
}

TEST(STYLE, fontsize_set_the_size) {
    FontSize fs(20);
    ASSERT_EQ("font-size:20px;", fs.renderStyle());
}

TEST(STYLE, position_default) {
    Position p;
    ASSERT_EQ("top:0px;left:0px;position:absolute;", p.renderStyle());
}

TEST(STYLE, position_set_top_and_left) {
    Position p1(100);
    ASSERT_EQ("top:100px;left:0px;position:absolute;", p1.renderStyle());
    Position p2(100, 100);
    ASSERT_EQ("top:100px;left:100px;position:absolute;", p2.renderStyle());
}

TEST(STYLE, size_default) {
    Size s;
    ASSERT_EQ("height:0px;weight:0px;", s.renderStyle());
}

TEST(STYLE, size_set_height_and_right) {
    Size s1(100);
    ASSERT_EQ("height:100px;weight:0px;", s1.renderStyle());
    Size s2(100, 100);
    ASSERT_EQ("height:100px;weight:100px;", s2.renderStyle());
}
