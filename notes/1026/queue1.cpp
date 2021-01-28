/**
 * Check out Queue.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include "queue.h"

#define CHECK(s, b) printf("%s: %s\n", b ? "pass" : "fail", s)

int main() {  
  Queue q1;
  CHECK("should be empty on creation", q1.empty());
  CHECK("next should be NONE on empty", q1.next() == NONE);

  q1.shift("TOM");
  CHECK("should not be empty after shift", !q1.empty());
  CHECK("size should be 1 after one shift", q1.size() == 1);
  CHECK("last pushed item should be next after one shit", q1.next() == "TOM");

  q1.shift("LISA");
  CHECK("should not be empty after shift", !q1.empty());
  CHECK("size should be 2 after two shifts", q1.size() == 2);
  CHECK("next should not change after shift", q1.next() == "TOM");

  CHECK("should unshift the first value", q1.unshift() == "TOM");
  CHECK("should not be empty after unshift", !q1.empty());
  CHECK("size should be 1 after one unshift", q1.size() == 1);
  CHECK("second shifted item should be next", q1.next() == "LISA");
}