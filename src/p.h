#ifndef P_H
#define P_H
#include "defines.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class P {
private:
    $(long)
    _c;

public:
    P() {
        _c.add(0);
    }
    P($(long) c) {
        for (int i = 0; i < c.size(); i++) {
            _c.add(c[i]);
        }
    }
    str get_poly() {
        str tmp;
        for (int i = _c.size() - 1; i >= 0; i--) {
            if (_c[i]) {
                long tmp_c = abs(_c[i]);
                if (i != _c.size() - 1) {
                    tmp += tmp_c == _c[i] ? " + " : " - ";
                } else {
                    tmp += tmp_c == _c[i] ? "" : "-";
                }
                if (_c[i] != 1) {
                    tmp += to_string(tmp_c);
                }
                if (i) {
                    tmp += "x";
                    if (i > 1) {
                        tmp += "^" + to_string(i);
                    }
                }
            }
        }
        return tmp;
    }
    P &operator=(P const &p) {
        _c.assign(p._c.begin(), p._c.end());
        return *this;
    }
    P &operator+(P const &p) {
        $(long)
        New_c;
        int origin_size = _c.size();
        int new_size = p._c.size();
        for (int i = 0; i < new_size; i++) {
            New_c.add(i <= origin_size ? _c[i] + p._c[i] : p._c[i]);
        }
        P New_p(New_c);
        return New_p;
    }
};
#endif