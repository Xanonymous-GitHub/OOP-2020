#include "../src/text.h"
#include <gtest/gtest.h>

TEST(text, defaultConstructor) {
  Text t;
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'></p>", t.render());
}

TEST(text, transtypeConstructor) {
  Text t("7eb1c9bfaa3ba2956c6c0724c5dfeebf06765494");
  ASSERT_EQ("<p id='7eb1c9bfaa3ba2956c6c0724c5dfeebf06765494' "
            "style='color:#000000;font-size:16px;'></p>",
            t.render());
}

TEST(text, setColor) {
  Text t;
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'></p>", t.render());
}

TEST(text, setFontSize) {
  Text t;
  t.setColor("dc39f0352b14c145dcfa24527c4ac9b68015c7de");
  ASSERT_EQ("<p id='' "
            "style='color:dc39f0352b14c145dcfa24527c4ac9b68015c7de;font-size:"
            "16px;'></p>",
            t.render());
}

TEST(text, setText) {
  Text t;
  t.setText("bc55d08e98b8025a8f9e01e2c595b3eba36c4ab5");
  ASSERT_EQ("<p id='' "
            "style='color:#000000;font-size:16px;'>"
            "bc55d08e98b8025a8f9e01e2c595b3eba36c4ab5</p>",
            t.render());
}

TEST(text, render) {
  Text t1;
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'></p>", t1.render());
  Text t2;
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'></p>", t2.render());
  Text t3;
  t3.setColor("dc39f0352b14c145dcfa24527c4ac9b68015c7de");
  ASSERT_EQ("<p id='' "
            "style='color:dc39f0352b14c145dcfa24527c4ac9b68015c7de;font-size:"
            "16px;'></p>",
            t3.render());
  Text t4;
  t4.setText("bc55d08e98b8025a8f9e01e2c595b3eba36c4ab5");
  ASSERT_EQ("<p id='' "
            "style='color:#000000;font-size:16px;'>"
            "bc55d08e98b8025a8f9e01e2c595b3eba36c4ab5</p>",
            t4.render());
}