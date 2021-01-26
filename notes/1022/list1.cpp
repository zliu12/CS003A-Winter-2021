/**
 * Operate on linked list
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "list.h"
#include <cstdio>

// Macro takes in 2 args
#define IN(l, v) (l.search(v) ? "int" : "not in")

// Using a regular function
void check(List l, int v) {
  printf("%d is %s\n", v, l.search(v) ? "in" : "not in");
}

int main() {
  List l1;
  int values[] = {231, -24, 22, 983};
  // colon means goes through values
  for (int v : values) {
    l1.add(v);
  }
  l1.dump();

  for (int v : values) {
    printf("%d is %s\n", v, IN(l1, v));
  }
  check(l1, 100);
}