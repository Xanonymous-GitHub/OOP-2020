#include "../src/html.h"
#include "../src/text.h"
#include "../src/image.h"

TEST(HTML, render)
{
    Html h;
    ASSERT_EQ("<HTML><body></body></HTML>", h.render());
}

TEST(HTML, append_text)
{
    Html h;
    Text t;
    t.setText("content");
    h.appendTag(&t);
    ASSERT_EQ("<HTML><body><p id='' style=''>content</p></body></HTML>", h.render());
}

TEST(HTML, append_image)
{
    Html h;
    Image i;
    i.setSrc("Hash Browns.png");
    h.appendTag(&i);
    ASSERT_EQ("<HTML><body><img id='' src='Hash Browns.png' style=''/></body></HTML>", h.render());
}

TEST(HTML, append_multiChild)
{
    Html h;
    Text t1;
    Text t2;
    Image i1;
    t1.setText("content1");
    t2.setText("content2");
    i1.setSrc("Hash Browns.png");
    h.appendTag(&t1);
    h.appendTag(&t2);
    h.appendTag(&i1);
    ASSERT_EQ("<HTML><body><p id='' style=''>content1</p><p id='' style=''>content2</p><img id='' src='Hash Browns.png' style=''/></body></HTML>", h.render());
}
