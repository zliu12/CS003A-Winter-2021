/**
 * Gelatin Implementation
 *
 * Copyright (c) [2021], Zhao Liu
 */

#include "species.h"

// Constructor, set the oject default value
Gelatin::Gelatin(double gelatinWeight) {
  _gelWeight = gelatinWeight;
  _gelShape = "sphere";
}

// Accessor, return the weight value of the object
double Gelatin::weight() {
  return _gelWeight;
}

// Accessor, return the shape value of the object
const char *Gelatin::shape() {
  return _gelShape;
}

// Member funciton morph(const char*)
void Gelatin::morph(const char *morphShape) {
  std::string shape = morphShape;
  if (shape == "flat") {
    _gelShape = morphShape;
  } else {
    _gelShape = "sphere";
  }
}

// Member function morph()
void Gelatin::morph() {
  _gelShape = "sphere";
}

// Member function split() edits the member variable _gelWeight by setting it to
// the half, which the _gelWeight was initialized to 540 but is equal to 270 
// now. Then split() creates a new object named gelSplit that takes in the new
// value of _gelWeight. The returned value is assigned to the newGelatin. 
Gelatin Gelatin::split() {
  _gelWeight /= 2;
  Gelatin gelSplit(_gelWeight);
  return gelSplit;
}

// Friend function, operator != overloaded
bool operator!=(const Gelatin &gelNew, const Gelatin &gelOriginal) {
  return true;
}