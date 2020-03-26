#include "html.h"
#include "text.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0);
    Html h;
    Text t1;
    Text t2;
    t1.setText("Hello, World");
    t2.setText("This is a simple ui output");
    h.appendChild(t1);
    h.appendChild(t2);
    h.outputHtml();
    return 0;
}
