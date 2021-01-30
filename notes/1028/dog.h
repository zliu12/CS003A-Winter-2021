/**
 * Dog (derived class).
 *
 * Copyright (c) [2021], Qichang.L
 */

#ifndef DOG_H_
#define DOG_H_

#include <string>
#include "animal.h"

class Dog : public Animal {
 private:
  std::string _name = "Dog";
  std::string _sound = "bark";

 public:
  Dog(double);
  std::string name() const;
  std::string sound() const;
};

#endif  // DOG_H_