/**
 * Linked list implementation
 *
 * Copyright (c) [2021], Qichang.L
 */

#include "list.h"
#include <cstdio>

List::List() : _head(nullptr), _tail(nullptr) {
}

List::~List() {
  // Can't do np = np->next directly
  for (Node* np = _head; np != nullptr; ){
    Node* p = np;
    np = np->next;
    delete p;
  }
}

// O(1) time complexity b/c it takes "constant" time irrespective of the size of
// the list
void List::add(int v) {
  // Be sure to create nodes on the heap, NOT on the stack 
  // as an "automatic" var!
  Node* np= new Node(v);
  if (_head == nullptr) {
    // Be sure to update ALL the affected attributes
    _head = np;
    _tail = np;
    return;
  }
  _tail->next = np;
  _tail = _tail->next;
}

// Check if value is in list
bool List::search(int v) {
  // Always do this check (list can be empty)
  if (_head == nullptr) {
    return false;
  }

  for (Node* np = _head; np != nullptr; np = np->next) {
    if (np->value == v) {
      return true;
    }
  }
  return false;
}

// Insert v2 after first node containing v1
bool List::insert(int v1, int v2) {
  if (_head == nullptr) {
    return false;
  }
  for (Node* np = _head; np != nullptr; np = np->next) {
    if (np->value == v1) {
      Node* v2np = new Node(v2);
      v2np->next = np->next;
      np->next = v2np;
      if (v2np->next == nullptr) {
        _tail = v2np;
      }
      return true;
    }
  }
  return false;
}

// Remove value from list, if present
bool List::remove(int v) {
  // No elements
  if (_head == nullptr) {
    return false;
  }

  // Head node matches value
  if (_head->value == v) {
    // Only one element
    if (_head == _tail) {
      delete _head;
      _head = _tail = nullptr;
      return true;
    }

    // More than one element
    Node* head = _head;
    _head = _head->next;
    delete head;
    return true;
  }

  // More than one element
  for (Node* np = _head; np->next != nullptr; np = np->next) {
    if (np->next->value == v) {
      // Need a temp var b/c np->next is getting freed
      Node* next = np->next;
      np->next = np->next->next;
      // Don't forget this!
      delete next;
      // Alway update ALL the affected attributes
      if (np->next == nullptr) {
        _tail = np;
      }
      return true;
    }
  }
  return false;
}
void List::dump() {
  for (Node* np = _head; np != nullptr; np = np->next) {
    if (np != _head) {
      printf(" -> ");
    }
    printf("%d", np->value);
  }
  printf("\n");
}
