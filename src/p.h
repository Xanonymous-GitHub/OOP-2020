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
    $v(long)
    _c;

public:
    P() {
        _c.add(0);
    }
    P($v(long) c) {
        for (int i = 0; i < c.size(); i++) {
            _c.add(c[i]);
        }
    }
    P(P const &p) {
        for (int i = 0; i < p._c.size(); i++) {
            _c.add(p._c[i]);
        }
    }
    str get_poly() {
        str rendered_string, symble, string_c, variable, power_symbol, string_power;
        int deg_of_c = _c.size() - 1;
        while (!(_c[deg_of_c--]))
            ;
        deg_of_c += 1;
        variable = "x";
        power_symbol = "^";
        for (int i = deg_of_c; i >= 0; i--) {
            int abs_c = abs(_c[i]);
            string_c = to_string(abs_c);
            if (abs_c == _c[i]) {
                symble = i == deg_of_c ? "" : " + ";
            } else {
                symble = i == deg_of_c ? "-" : " - ";
            }
            if (i < 1) {
                variable = "";
            }
            if (i <= 1) {
                power_symbol = "";
                string_power = "";
            } else {
                string_power = to_string(i);
            }
            rendered_string += (symble + string_c + variable + power_symbol + string_power);
        }
        if (!(rendered_string.size())) {
            rendered_string = "Nothing...";
        }
        return rendered_string;
    }
    void operator=(P const &p) {
        _c.assign(p._c.begin(), p._c.end());
    }
    P operator+(P const &p) {
        $v(long)
        New_c;
        int origin_size = _c.size();
        int new_size = p._c.size();
        for (int i = 0; i < new_size; i++) {
            New_c.add(i <= origin_size ? _c[i] + p._c[i] : p._c[i]);
        }
        P New_p(New_c);
        return New_p;
    }

    P operator-(P const &p) {
        $v(long)
        New_c;
        int origin_size = _c.size();
        int new_size = p._c.size();
        for (int i = 0; i < new_size; i++) {
            New_c.add(i <= origin_size ? _c[i] - p._c[i] : -1 * p._c[i]);
        }
        P New_p(New_c);
        return New_p;
    }
    P operator*(P const &p) {
        int origin_size = _c.size();
        int new_size = p._c.size();
        $v(long)
        New_c(origin_size + new_size, 0);
        for (int i = 0; i < origin_size; i++) {
            for (int j = 0; j < new_size; j++) {
                New_c[i + j] += _c[i] * p._c[j];
            }
        }
        P New_p(New_c);
        return New_p;
    }
};
#endif