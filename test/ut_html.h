#include "../src/html.h"
#include "../src/image.h"
#include "../src/text.h"

TEST(HTML, appendText) {
    Html h;
    Text t;
    h.appendText(t);
    ASSERT_EQ("<HTML><body><p style='color:#000000;font-size:16px;'></p></body></HTML>", h.render());
}

TEST(HTML, appendImage) {
    Html h;
    Image i;
    h.appendImage(i);
    ASSERT_EQ("<HTML><body><img src='' style='top:0px;left:0px;'/></body></HTML>", h.render());
}

TEST(HTML, render) {
    Html h;
    Text t;
    Image i;
    h.appendText(t);
    h.appendImage(i);
    ASSERT_EQ("<HTML><body><p style='color:#000000;font-size:16px;'></p><img src='' style='top:0px;left:0px;'/></body></HTML>", h.render());
}