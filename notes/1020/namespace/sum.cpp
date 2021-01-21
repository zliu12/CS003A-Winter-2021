/**
 * Summing function to demonstrate need for unamed namespace.
 *
 * Copyright (c) [2021], Qichang.L
 */

// "Macro" to calculate min value
#define MIN(a, b) (a < b ? a : b)

namespace {
  // "Global" var, avoid at all costs unless protected inside an unnamed
  // namespace
  int count = 10;
}

// Sum numbers till n or count, whichever is lower
int sum(int n) {
  int sum = 0;
  for (int i  = 1; i < MIN(n, count); i++) {
    sum += i;
  }

  return sum;
}