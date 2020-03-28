#include "../src/html.h"
#include "../src/text.h"

TEST(Html, appendChild) {
    Html h;
    Text t;
    t.setText("four-at-hello");
    h.appendChild(t);
    ASSERT_EQ("<HTML><body><p>four-at-hello</p></body></HTML>", h.render());
}

TEST(Html, appendMultiChild) {
    Html h;
    Text t1, t2, t3;
    t1.setText("123321");
    t2.setText("456654");
    t3.setText("789987");
    h.appendChild(t1);
    h.appendChild(t2);
    h.appendChild(t3);
    ASSERT_EQ("<HTML><body><p>123321</p><p>456654</p><p>789987</p></body></HTML>", h.render());
}

TEST(Html, render) {
    Html h;
    ASSERT_EQ("<HTML><body></body></HTML>", h.render());
}

TEST(Html, outputHtml) {
    Html h;
    Text t;
    t.setText("92387492837592837498");
    h.appendChild(t);
    auto pos = "main.html";
    std::remove(pos);
    h.outputHtml();
    std::ifstream file(pos);
    ASSERT_TRUE(file.is_open());
    std::string content;
    file >> content;
    ASSERT_EQ("<HTML><body><p>92387492837592837498</p></body></HTML>", content);
    std::remove(pos);
    file.close();
}