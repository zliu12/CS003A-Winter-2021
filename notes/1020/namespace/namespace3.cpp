/**
 * Unnamed namepaces.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>

extern int sum(int);

// Unamed namespace
namespace {
  int count = 100;
}

int main() {
  printf("count = %d\n", count);
  printf("sum(count) = %d\n", sum(count));
}