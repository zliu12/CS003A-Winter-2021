/**
 * Color "header" file with only declarations.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#ifndef QC_CLASS_NOTES_1019_COLOR_H_
#define COLOR_H_
#include <string>

class Color {
 private:
  double _red, _green, _blue;

  // A "declaration" with no "implementation"
  double _value(double);

 public:
  Color();
  explicit Color(double);
  Color(double, double, double);
  double value() const;
  Color& scale(double);
  Color operator+(Color) const;
  std::string toString() const;
  void dump(const char*) const;
};

#endif  // QC_CLASS_NOTES_1019_COLOR_H_