/**
 * Node structure.
 *
 * Copyright (c) [2021], Qichang.L
 */

#ifndef NODE_H_
#define NODE_H_

struct Node {
  double value;
  Node *next;
  explicit Node(double);
};

#endif    // NODE_H_