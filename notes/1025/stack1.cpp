/**
 * Check out stack.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include "stack.h"

#define CHECK(s, b) printf("%s: %s\n", b ? "pass" : "fail", s)

int main() {
  Stack s1;
  CHECK("should be empty on creation", s1.empty());
  CHECK("top should be NONE on empty", s1.top() == NONE);

  s1.push(100);
  CHECK("should not be empty after push", !s1.empty());
  CHECK("size should be 1 after one push", s1.size() == 1);
  CHECK("last pushed item should be on top", s1.top() == 100);

  s1.push(200);
  CHECK("should not be empty after push", !s1.empty());
  CHECK("size should be 2 after second push", s1.size() == 2);
  CHECK("last pushed item should be on top", s1.top() == 200);

  CHECK("should pop the last pushed value", s1.pop() == 200);
  CHECK("should not be empty after pop", !s1.empty());
  CHECK("size should be 1 after one pop", s1.size() == 1);
  CHECK("last pushed item should be on top", s1.top() == 100);
}