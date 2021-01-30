/**
 * Animal (base class).
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "animal.h"

Animal::Animal(double w) : _weight(w) {
}

double Animal::weight() const {
  return _weight;
}

std::string Animal::name() const {
  return _name;
}