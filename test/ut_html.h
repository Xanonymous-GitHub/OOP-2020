#include "../src/html.h"
#include "../src/image.h"
#include "../src/text.h"
#include <gtest/gtest.h>

TEST(html, appendTag) {
  Html h;
  Image *i = new Image;
  Text *t = new Text;
  h.appendTag(i);
  h.appendTag(t);
  ASSERT_EQ("<HTML><body><img id='' src='' "
            "style='top:0px;left:0px;position:absolute;'/><p id='' "
            "style='color:#000000;font-size:16px;'></p></body></HTML>",
            h.render());
}

TEST(html, appendText) {
  Html h;
  Text t;
  h.appendText(t);
  ASSERT_EQ("<HTML><body><p id='' "
            "style='color:#000000;font-size:16px;'></p></body></HTML>",
            h.render());
}

TEST(html, appendImage) {
  Html h;
  Image i;
  h.appendImage(i);
  ASSERT_EQ("<HTML><body><img id='' src='' "
            "style='top:0px;left:0px;position:absolute;'/></body></HTML>",
            h.render());
}

TEST(html, render) {
  Html h;
  Image *i = new Image;
  Text *t = new Text;
  h.appendTag(i);
  h.appendTag(t);
  ASSERT_EQ("<HTML><body><img id='' src='' "
            "style='top:0px;left:0px;position:absolute;'/><p id='' "
            "style='color:#000000;font-size:16px;'></p></body></HTML>",
            h.render());
}