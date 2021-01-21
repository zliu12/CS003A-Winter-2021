/**
 * Color class definition.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cmath>

// Included in the implementation file as well as all the
// files that use the class
#include "color.h"

// A "definition" with an "implementation"
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

Color::Color(double r, double g, double b) : _red(_value(r)), _green(_value(g)), _blue(_value(b)) {
}

double Color::value() const {
  return sqrt((_red * _red + _green * _green + _blue * _blue) / 3.0);
}

Color& Color::scale(double factor) {
  _red = _value(_red * factor);
  _green = _value(_green * factor);
  _blue = _value(_blue * factor);
  return *this;
}

Color Color::operator+(Color c) const {
  return Color(_red + c._red, _blue + c._blue, _green + c._green);
}

std::string Color::toString() const {
  char buf[0x100];
  sprintf(buf, "[%.2lf, %.2lf, %.2lf]", _red, _green, _blue);
  return buf;
}

void Color::dump(const char* t) const {
  // Note that we need to extract the C string value out of std::string
  printf("%s: %s\n", t, toString().c_str());
}