#include "../src/text.h"
#include "../src/color.h"
#include "../src/fontsize.h"

TEST(TEXT, default_constructor){
  Text t;
  ASSERT_EQ("<p id='' style=''></p>", t.render());
}

TEST(TEXT, constuctor){
  Text t("oop_text_001");
  ASSERT_EQ("<p id='oop_text_001' style=''></p>", t.render());
}

TEST(TEXT, set_text){
  Text t;
  t.setText("test content");
  ASSERT_EQ("<p id='' style=''>test content</p>",t.render());
}

TEST(TEXT, add_color){
  Text t;
  t.addStyle(new Color("#FFFFFF"));
  ASSERT_EQ("<p id='' style='color:#FFFFFF;'></p>",t.render());
}

TEST(TEXT, add_fontSize){
  Text t;
  t.addStyle(new FontSize(20));
  ASSERT_EQ("<p id='' style='font-size:20px;'></p>",t.render());
}

TEST(TEXT, add_multiple_style){
  Text t;
  t.addStyle(new Color("#FFFFFF"));
  t.addStyle(new FontSize(20));
  ASSERT_EQ("<p id='' style='color:#FFFFFF;font-size:20px;'></p>",t.render());
}
