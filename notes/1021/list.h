/**
 * Linked list.
 *
 * Copyright (c) [2021], Qichang.L
 */

#ifndef LIST_H_
#define LIST_H_
#include "node.h"

class List {
 private:
  Node* _head;
  Node* _tail;

 public:
  List();
  void add(int);
  void dump();
};

#endif    // LIST_H_