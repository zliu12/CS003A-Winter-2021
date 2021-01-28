/**
 * Queue Interface.
 *
 * Copyright (c) [2021], Qichang.L
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <string>
#include "node.h"

#define NONE (std::string("_NONE_"))

class Queue {
 private:
  Node *_head = nullptr;
  Node *_tail = nullptr;
  int _size = 0;

 public:
  ~Queue();
  bool empty() const;
  int size() const;
  std::string next() const;
  void shift(std::string);
  std::string unshift();
};

#endif  // QUEUE_H_