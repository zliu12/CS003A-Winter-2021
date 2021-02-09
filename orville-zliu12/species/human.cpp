/**
 * Human Implementation
 *
 * Copyright (c) [2021], Zhao Liu
 */

#include "species.h"

// Accessor, return the object's value of member variable _isMale
bool Human::isMale() {
  return _isMale = false;
}

// Constructor, intialize values of the object
Human::Human(bool male, double humanHeight, double humanWeight) {
  _isMale = male;
  speciesHeight = humanHeight;
  speciesWeight = humanWeight;
}
