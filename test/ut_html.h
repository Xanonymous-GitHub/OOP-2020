#include "../src/html.h"
#include "../src/image.h"
#include "../src/text.h"

TEST(HTML, render) {
    Html h;
    ASSERT_EQ("<HTML><body></body></HTML>", h.render());
}

TEST(HTML, append_text) {
    Html h;
    Text t;
    t.setText("test");
    h.appendTag(&t);
    ASSERT_EQ("<HTML><body><p id='' style=''>test</p></body></HTML>", h.render());
}

TEST(HTML, append_image) {
    Html h;
    Image i;
    i.setSrc("image1.png");
    h.appendTag(&i);
    ASSERT_EQ("<HTML><body><img id='' src='image1.png' style=''/></body></HTML>", h.render());
}

TEST(HTML, append_multiChild) {
    Html h;
    Text t1;
    Text t2;
    Image i1;
    t1.setText("test1");
    t2.setText("test2");
    i1.setSrc("image1.png");
    h.appendTag(&t1);
    h.appendTag(&t2);
    h.appendTag(&i1);
    ASSERT_EQ("<HTML><body><p id='' style=''>test1</p><p id='' style=''>test2</p><img id='' src='image1.png' style=''/></body></HTML>", h.render());
}
