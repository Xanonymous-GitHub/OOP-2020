#include "../src/text.h"
#include "../src/color.h"
#include "../src/fontsize.h"

TEST(TEXT, default_constructor)
{
    Text t;
    ASSERT_EQ("<p id='' style=''></p>", t.render());
}

TEST(TEXT, constuctor)
{
    Text t("text_id");
    ASSERT_EQ("<p id='text_id' style=''></p>", t.render());
}

TEST(TEXT, set_text)
{
    Text t;
    t.setText("content");
    ASSERT_EQ("<p id='' style=''>content</p>", t.render());
}

TEST(TEXT, add_color)
{
    Text t;
    t.addStyle(new Color("#0F0F0F"));
    ASSERT_EQ("<p id='' style='color:#0F0F0F;'></p>", t.render());
}

TEST(TEXT, add_fontSize)
{
    Text t;
    t.addStyle(new FontSize(32));
    ASSERT_EQ("<p id='' style='font-size:32px;'></p>", t.render());
}

TEST(TEXT, add_multiple_style)
{
    Text t;
    t.addStyle(new Color("#333333"));
    t.addStyle(new FontSize(12));
    ASSERT_EQ("<p id='' style='color:#333333;font-size:12px;'></p>", t.render());
}
