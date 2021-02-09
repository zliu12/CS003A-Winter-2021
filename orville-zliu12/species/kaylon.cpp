/**
 * Kaylon Implementation
 *
 * Copyright (c) [2021], Zhao Liu
 */

#include "species.h"

// Constructor, initialize values of the object
Kaylon::Kaylon(double kaylonHeight, double kaylonWeight) {
  speciesHeight = kaylonHeight;
  speciesWeight = kaylonWeight;
}

// Accessor, return the object's value of member variable _isFiring
bool Kaylon::isFiring() const {
  return _isFiring;
}

// Mutator, edit the object's value of member variable _isFiring
bool Kaylon::startFiring() {
  _isFiring = true;
  return _isFiring;
}

// Mutator, edit the object's value of member variable _isFiring
bool Kaylon::stopFiring() {
  _isFiring = false;
  return _isFiring;
}