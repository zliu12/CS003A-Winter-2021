/**
 * Utility functions.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include "animal.h"

// This does NOT need to be aware of the derived classes
void dump(const Animal *ap) {
  printf("name: %s, weight: %.1lf\n", ap->name().c_str(), ap->weight());
}