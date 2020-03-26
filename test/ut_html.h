#include "../src/html.h"
#include "../src/text.h"

TEST(Html, appendChild) {
    Html h;
    Text t;
    t.setText("four-at-hello");
    h.appendChild(t);
    ASSERT_EQ("<html><body><p>four-at-hello</p></body></html>", h.render());
}

TEST(Html, render) {
    Html h;
    ASSERT_EQ("<html><body></body></html>", h.render());
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
    ASSERT_EQ("<html><body><p>92387492837592837498</p></body></html>", content);
    std::remove(pos);
    file.close();
}