/**
 * 13.1 Nodes
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <string>

/*
TODO: Linked List
1.Constructed using pointers
2.Not in fixed in size, can grow and shrink while program's running
 */

/* 
TODO: Nodes and Linked Lists
1.Dynamic vars that are either structs or classes normally have one or more
  member vars that are ptr vars which connect them to other dynamic vars.
*/

/*
TODO: Nodes
1.Can a struct or class
2.Contains information part (string, integer, char, etc), arrow part (ptr
  that can point to other nodes of the same type)  
! Ptrs point to the entire node, not to the individual items inside of the node
*/
// definition of ListNode must come first since it's used in the definition of
// ListNodePtr
struct ListNode {
  std::string item = "roll";
  int count = 10;
  ListNode *link;
};
typedef ListNode* ListNodePtr;

int main() {
  // Not a node but a ptr var points to a node
  // Another way to define: ListNode *head;
  ListNodePtr head;

  // One way to change the number in the above Node from 10 to 12
  // head is a ptr, *head is the thing it points to, which is the node(dynamic
  // var) containing "rolls" and the int 10
  // (*head) refers to a struct(node), (*head).count is the name of the int var
  // in the struct(node)
  // Dereferencing operator * and a dot operator
  // Paratheses is mandatory
  (*head).count = 12;
  // Another way to change the number in the Node from 12 to 16
  head->count = 16;
  head->item = "bagel";
  /*
  TODO: Null 
  1.Give a value to a ptr var
  2.An end marker indicates the end of the list of nodes
  3.Null is 0
  4.#include <iostream> or <cstddef> library
  5.A ptr can be set to NULL using the assignment operator 
   */
  double *there = NULL;

  /* 
  TODO: Arrow Operator ->
  1.Specify a member of a struct/class obj that's pointed to by a ptr var
  2.Syntax: Pointer_Variable->Member_Name
   */
  struct Record {
    int number;
    char grade;
  };
  // Create a dynamic var of type Record, sets the member var of the dynamic
  // struct var to 2001 and 'A'
  Record *p;
  p = new Record;
  p->number = 2001;
  p->grade = 'A';

  /* 
  TODO: nullptr (C++11)
  1.Not the integer 0 but it's a literal const used to represent a null pointer
  2.Use nullptr anywhere you would have used NULL for a ptr
  3.Can only be assigned to a pointer
   */
  double *there = nullptr;

  return 0;
}




