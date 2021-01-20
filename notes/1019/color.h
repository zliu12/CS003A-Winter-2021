/**
 * Color Class Declarations.
 * Color "header" fil w/ only declarations
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>

#define NUDGE 0.01

class Color {
 private:
  double _red, _green, _blue;

  // A "declaration" w/ no "implementation"
  double _value(double);

 public:
  Color();
  explicit Color(double);
  Color(double, double, double);
  double value() const;
  Color& scale(double factor);
  Color operator+(Color c) const;
  std::string toString() const;
  void dump(const char *t) const;
};