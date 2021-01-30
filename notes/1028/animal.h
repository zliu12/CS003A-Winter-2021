/**
 * Animal (base class).
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <string>
#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal {
 private:
  std::string _name = "Animal";
  double _weight;

 public:
  Animal(double);
  virtual std::string name() const;
  double weight() const;
  virtual std::string sound() = 0;
};

#endif  // ANIMAL_H_