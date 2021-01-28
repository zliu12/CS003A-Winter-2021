/**
 * Stack of doubles.
 *
 * Copyright (c) [2021], Qichang.L
 */

#ifndef STACK_H_
#define STACK_H_

#include <limits>
#include "node.h"

#define NONE (std::numeric_limits<double>::min())

class Stack {
 private:
  Node *_top = nullptr;
  int _size = 0;

 public:
  ~Stack();
  bool empty() const;
  int size() const;
  double top() const;
  void push(double);
  double pop();
};

#endif  // STACK_H_