/**
 * Operator overloading
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#define NUDGE 0.01

class Color {
 private:
  double _red, _green, _blue;
  double _value(double v) {
    if (v < 0) {
    return 0;
    }
    if (v > 1) {
     return 1;
    }
    return v;
    }

 public:
  Color() : _red(0), _green(0), _blue(0) {
  }

  explicit Color(double v) {
    _red = _green = _blue = _value(v);
  }

  Color(double r, double g, double b) : _red(_value(r)), _green(_value(g)),
                                        _blue(_value(b)) {
  }

  // Copy constructor
  Color (const Color &c) : _red(c._red), _green(c._green), _blue(c._blue)) {
    printf("Copy constructor: %.2lf, %.2lf, %.2lf")
  }

  double value() {
    return sqrt((_red * _red + _green * _green + _blue * _blue) / 3.0);
  }

  // Note that this returns itself by reference, meaning there is no copying
  Color &scale(double factor) {
    _red = _value(_red * factor);
    _green = _value(_green * factor);
    _blue = _value(_blue * factor);
    return *this;
  }

  // This function returns a copy of the copy, NOT this instance
  // Keyword "const" after a function indicates that the code doesn't alter
  // the attributes of the class.
  // Note that the first param is always assumed to be this instance
  Color operator+(Color c) const {
    return Color(_red + c._red, _blue + c._blue, _green + c._green);
  }

  // This function returns a copy of the color NOT this instance
  Color operator*(double s) const {
    return Color(_red * s, _green * s, _blue * s);
  }

  // Unary "pre" ++
  Color operator++() {
    _red += NUDGE;
    _green += NUDGE;
    _blue += NUDGE;
    return *this;
  }

  // Unary "post" ++
  Color operator++(int) {
    Color original = *this;
    _red += NUDGE;
    _green += NUDGE;
    _blue += NUDGE;
    return original;
  }

  void dump(const *char t) {
    printf("%s: [%.2lf, %.2lf, %.2lf]\n", t, _red, _green, _blue);
  }
};

// Reqire for operations with the scale in front
Color operator*(double s, Color c) {
  // This works because we do have Color::operator * (double);
  // Cannot return Color(c._red * s, c._green * s, c._blue * s) because
  // these members are private
  return c * s;
}

int main() {
  Color c1(0.5, 0.2, 0.2);
  Color c2(0.1, 0.3, 0.2);

  // "Add" colors
  Color c3 = c1 + c2;   // Equivalent to "Color c3 = c1.operator+(c2);"
  c3.dump("c3");
  c3.scale(0.5);
  c3.dump("c3");
  c1.dump("c1");

  // // "Cascaded" addition
  // Color c4 = c1 + c2 + c3.scale(0.1);
  // c4.dump("c4");

  // // Multiply operator overloading
  // Color c5 = c4 * 0.2;  // Equivalent to "Color c5 = c4.operator*(0.2)"
  // c5.dump("c5");

  // // Multiply with scale first
  // Color c6 = 0.2 * c4;
  // c6.dump("c6");

  // // Unary "pre" ++
  // Color c7 = ++c6;
  // c6.dump("c6");
  // c7.dump("c7");

  // // Unary "post" ++
  // Color c8 = c6++;
  // c6.dump("c6");
  // c8.dump("c8");
}