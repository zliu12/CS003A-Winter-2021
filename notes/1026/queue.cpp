/**
 * Queue Implementation.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "queue.h"

Queue::~Queue() {
  for (Node *np = _head; np != nullptr;)
  {
    Node *p = np;
    np = np->next;
    delete p;
  }
}

bool Queue::empty() const {
  return _head == nullptr;
}

int Queue::size() const {
  return _size;
}

std::string Queue::next() const {
  return _head == nullptr ? NONE : _head->value;
}

void Queue::shift(std::string v) {
  Node *np = new Node(v);
  _size++;
  if (_head == nullptr) {
    _head = _tail = np;
    return;
  }
  _tail->next = np;
  _tail = _tail->next;
}

std::string Queue::unshift() {
  if (_head == nullptr) {
    return NONE;
  }
  --_size;
  Node *np = _head;
  _head = _head->next;
  // If there is only one element, don't forget ALL scenarios!
  if (_head == nullptr) {
    _tail = nullptr;
  }
  std::string v = np->value;
  delete np;  // Always delate node pulled out
  return v;
}