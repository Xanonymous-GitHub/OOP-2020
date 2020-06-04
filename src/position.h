#ifndef POSITION_H
#define POSITION_H

#include "./style.h"

class Position : public Style {
private:
    int top, left;

public:
    Position() : top(0), left(0) {}
    Position(int top) : top(top), left(0) {}
    Position(int top, int left) : top(top), left(left) {}
    string const renderStyle() override {
        return "top:" + to_string(top) + "px;left:" + to_string(left) + "px;" + "position:absolute;";
    }
};

#endif