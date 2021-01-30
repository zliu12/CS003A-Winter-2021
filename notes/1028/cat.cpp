/**
 * Cat (derived class).
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "cat.h"

Cat::Cat(double w) : Animal(w) {
}

std::string Cat::sound() const {
  return _sound;
}

std::string Cat::name() const {
  return _name;
}