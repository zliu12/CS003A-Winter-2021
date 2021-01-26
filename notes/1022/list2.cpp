/**
 * Writing tests for insert().
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include "list.h"

// Check a test
#define CHECK(s, b) printf("%s, %s\n", s, b ? "pass" : "fail")

int main() {
  List l1;

  // Note that these check some so-called "corner" or "edge" cases (like
  // inserting on empty list, after head, and tail)
  CHECK("insert on empty", l1.insert(100, 101));
  l1.add(100);
  CHECK("insert 101 after head", l1.insert(100, 200));
  l1.add(300);
  CHECK("insert after internal value", l1.insert(200, 250));
  CHECK("insert after tail", l1.insert(300, 500));
  
  l1.dump();
}