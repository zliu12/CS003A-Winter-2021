/**
 * Check inheritance, method redefinition.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "cat.h"
#include "dog.h"

int main() {
  Animal a1(100);
  printf("a1.name() = %s, a1.weight() = %.1lf\n",
    a1.name().c_str(), a1.weight());

  Cat c1(10);
  printf("c1.name() = %s, c1.weight() = %.1lf, c1.sound() = %s\n",
    c1.name().c_str(), c1.weight(), c1.sound().c_str());

  Dog d1(20);
  printf("d1.name() = %s, d1.weight() = %.1lf, d1.sound() = %s\n",
    d1.name().c_str(), d1.weight(), d1.sound().c_str());

  // Weight gets assigned, but not the name b/c it's a copy
  Animal ac2 = c1;
  printf("a1.name() = %s, a1.weight() = %.1lf\n",
    ac2.name().c_str(), ac2.weight());

  // First copy, then initialize
  // Weight gets assigned, but not the name b/c it's a copy
  Animal ad1 = d1;
  printf("ad1.name() = %s, ad1.weight() = %.1lf\n",
    ad1.name().c_str(), ad1.weight());
}