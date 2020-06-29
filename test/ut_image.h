#include "../src/size.h"
#include "../src/image.h"
#include "../src/position.h"

TEST(IMAGE, default_constructor)
{
    Image i;
    ASSERT_EQ("<img id='' src='' style=''/>", i.render());
}

TEST(IMAGE, constructor)
{
    Image i("img_id");
    ASSERT_EQ("<img id='img_id' src='' style=''/>", i.render());
}

TEST(IMAGE, set_src)
{
    Image i;
    i.setSrc("Hash Browns.png");
    ASSERT_EQ("<img id='' src='Hash Browns.png' style=''/>", i.render());
}

TEST(IMAGE, add_position)
{
    Image i;
    i.setSrc("Hash Browns.png");
    i.addStyle(new Position(50, 50));
    ASSERT_EQ("<img id='' src='Hash Browns.png' style='top:50px;left:50px;position:absolute;'/>", i.render());
}

TEST(IMAGE, add_size)
{
    Image i;
    i.setSrc("Hash Browns.png");
    i.addStyle(new Size(50, 50));
    ASSERT_EQ("<img id='' src='Hash Browns.png' style='height:50px;weight:50px;'/>", i.render());
}

TEST(IMAGE, add_multiple_style)
{
    Image i;
    i.setSrc("Hash Browns.png");
    i.addStyle(new Position(50, 50));
    i.addStyle(new Size(50, 50));
    ASSERT_EQ("<img id='' src='Hash Browns.png' style='top:50px;left:50px;position:absolute;height:50px;weight:50px;'/>", i.render());
}
