/**
 * Moclan Implemenatation
 *
 * Copyright (c) [2021], Zhao Liu
 */

#include "species.h"

// Constructor, initialize values of the object
Moclan::Moclan(double mocHeight, double mocWeight) {
  speciesHeight = mocHeight;
  speciesWeight = mocWeight;
  _isEgg = false;
}

// Accessor, return the object's value of member variable _isEgg
bool Moclan::isEgg() {
  return _isEgg;
}

// Member function layEgg(), creates an object moclanCopy equals to the class
// Moclan, and then set the _isEgg value of the moclanCopy to true. When calling
// layEgg, the returned value (moclanCopy) is assigend to the l-value
Moclan Moclan::layEgg() {
  Moclan moclanCopy = *this;
  moclanCopy._isEgg = true;
  return moclanCopy;
}

// Mutator, edit the object's value of member variable _isEgg
void Moclan::hatch() {
  _isEgg = false;
}