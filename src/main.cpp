#include <iostream>
#include "./html.h"
#include "./text.h"

int main(int argc, char *argv[]) {
    Html h;
    Text t1, t2;
    t1.setText("Hello, World");
    t2.setText("This is a simple ui output");
    h.appendChild(t1);
    h.appendChild(t2);
    h.outputHtml();
    return 0;
}
