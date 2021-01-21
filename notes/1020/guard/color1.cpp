/**
 * Using the color class.
 *
 Copyright (c) 2021, Sekhar Ravinutala.
*/

// Note the "" for the inclusion (not <>)
#include "color.h"

int main() {
  Color c1(0.5, 0.2, 0.2);
  Color c2(0.1, 0.3, 0.2);

  // "Add" colors
  Color c3 = c1 + c2;  // Equivalent to "Color c3 = c1.operator+(c2);"
  c3.dump("c3");

  // "Cascaded" addition
  Color c4 = c1 + c2 + c3.scale(0.1);
  c4.dump("c4");
}