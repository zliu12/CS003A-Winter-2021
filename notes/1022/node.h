/**
 * Node structure.
 *
 * Copyright (c) [2021], Qichang.L
 */

#ifndef NODE_H_
#define NODE_H_

struct Node {
  int value;
  Node* next;
  Node(int);
};

#endif    // NODE_H_