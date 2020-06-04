#include "../src/size.h"
#include "../src/image.h"
#include "../src/position.h"

TEST(IMAGE, default_constructor){
  Image i;
  ASSERT_EQ("<img id='' src='' style=''/>",i.render());
}

TEST(IMAGE, constructor){
  Image i("oop_img_001");
  ASSERT_EQ("<img id='oop_img_001' src='' style=''/>",i.render());
}

TEST(IMAGE, set_src){
  Image i;
  i.setSrc("Hash Browns.png");
  ASSERT_EQ("<img id='' src='Hash Browns.png' style=''/>",i.render());
}

TEST(IMAGE, add_position){
  Image i;
  i.setSrc("Hash Browns.png");
  i.addStyle(new Position(100, 100));
  ASSERT_EQ("<img id='' src='Hash Browns.png' style='top:100px;left:100px;position:absolute;'/>",i.render());
}

TEST(IMAGE, add_size){
  Image i;
  i.setSrc("Hash Browns.png");
  i.addStyle(new Size(100, 100));
  ASSERT_EQ("<img id='' src='Hash Browns.png' style='height:100px;weight:100px;'/>",i.render());
}

TEST(IMAGE, add_multiple_style){
  Image i;
  i.setSrc("Hash Browns.png");
  i.addStyle(new Position(100, 100));
  i.addStyle(new Size(100, 100));
  ASSERT_EQ("<img id='' src='Hash Browns.png' style='top:100px;left:100px;position:absolute;height:100px;weight:100px;'/>",i.render());
}
