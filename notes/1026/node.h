/**
 * Node structure.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <string>
#ifndef NODE_H_
#define NODE_H_

struct Node {
  std::string value;
  Node *next;
  explicit Node(std::string);
};

#endif    // NODE_H_