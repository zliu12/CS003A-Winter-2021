/**
 * Cat (derived class).
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "dog.h"

Dog::Dog(double w) : Animal(w) {
}

std::string Dog::sound() const {
  return _sound;
}

std::string Dog::name() const {
  return _name;
}