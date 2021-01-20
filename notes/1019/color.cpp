/**
 * Color Class Definition.
 *
 * Copyright (c) [2021], Qichang.L
 */

// Included in the implementation file as well as all the files that use the
// class
# include "color.h"
#include <cmath>

// Put "Color::" to tell the compiler this is the Color's value.
// A "Definition" w/ an "implementation" (ref @ln17&18)
double Color::_value(double v) {
    if (v < 0) {
        return 0;
    }
    if (v > 1) {
        return 1;
    }
    return v;
}

Color::Color() : _red(0), _green(0), _blue(0) {
}

Color::Color(double v) {
    _red = _green = _blue = _value(v);
}

Color::value() const {
    return sqrt((_red * _red + _green * _green + _blue * _blue) / 3.0);
}

Color::Color &scale(double factor) {
    _red = _value(_red * factor);
    _green = _value(_green * factor);
    _blue = _value(_blue * factor);
    return *this;
}

Color::Color operator+(Color c) const {
    return Color(_red + c._red, _blue + c._blue, _green + c._green);
}

Color &ref() {
    return *this;
}

std::string toString() const {
    char buf[0x100];
    snprintf(buf, "[%.2lf, %.2lf, %.2lf]", _red, _green, _blue);
    return buf;
}

void dump(const char *t) const {
    printf("%s: %s\n", t, toString().c_str());
}
