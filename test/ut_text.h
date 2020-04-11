#include "../src/text.h"

TEST(TEXT, render) {
    Text t;
    ASSERT_EQ("<p style='color:#000000;font-size:16px;'></p>", t.render());
}

TEST(TEXT, setColor) {
    Text t;
    t.setColor("f2ae75cbff14b82306d05277cee8da06392f9897ddb78463134156ccf654fc181e1502dd351f95fa95fb2e8635c920479d4f08cb7e2f50caf986a349fc112035");
    ASSERT_EQ("<p style='color:f2ae75cbff14b82306d05277cee8da06392f9897ddb78463134156ccf654fc181e1502dd351f95fa95fb2e8635c920479d4f08cb7e2f50caf986a349fc112035;font-size:16px;'></p>", t.render());
}

TEST(TEXT, setFontSize) {
    Text t;
    t.setFontSize("f2ae75cbff14b82306d05277cee8da06392f9897ddb78463134156ccf654fc181e1502dd351f95fa95fb2e8635c920479d4f08cb7e2f50caf986a349fc112035");
    ASSERT_EQ("<p style='color:#000000;font-size:f2ae75cbff14b82306d05277cee8da06392f9897ddb78463134156ccf654fc181e1502dd351f95fa95fb2e8635c920479d4f08cb7e2f50caf986a349fc112035;'></p>", t.render());
}

TEST(TEXT, setText) {
    Text t;
    t.setText("ad14f4367d0bbd1922990523566da394fa7d6a1120219fb5868ec264bb12a692135afaa5514d3651a36ce3468f777a5f14bd266e1fa59eb1dcc0331374440a60");
    ASSERT_EQ("<p style='color:#000000;font-size:16px;'>ad14f4367d0bbd1922990523566da394fa7d6a1120219fb5868ec264bb12a692135afaa5514d3651a36ce3468f777a5f14bd266e1fa59eb1dcc0331374440a60</p>", t.render());
}