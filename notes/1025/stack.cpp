/**
 * Stack of doubles.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "stack.h"

Stack::~Stack() {
  for (Node *np = _top; np != nullptr;) {
    Node *p = np;
    np = np->next;
    delete p;
  }
}

bool Stack::empty() const {
  return _top == nullptr;
}

int Stack::size() const {
  return _size;
}

// Returns NONE if empty
double Stack::top() const {
  return _top == nullptr ? NONE : _top->value;
}

void Stack::push(double v) {
  Node *np = new Node(v);
  _size++;      // Don't forget to update ALL affected attributes!
  if (_top == nullptr) {
    _top = np;
    return;
  }
  np->next = _top;
  _top = np;
}

double Stack::pop() {
  if (_top == nullptr) {
    return NONE;
  }
  --_size;
  Node *np = _top;
  _top = _top->next;
  double v = np->value;
  delete np;
  return v;
}