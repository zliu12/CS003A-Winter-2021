/**
 * 13.1 Linked Lists
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>

/* 
TODO: Linked Lists
1.A linked list is a list of nodes in which each node has a member var that's
  a ptr that points to the next node in the list
2.The 1st node in the list is called head, which is why the ptr var that points
  to the 1st node is named head
3.The ptr named head is not itself the head of the list but only points to the
  head of the list
4.The last node has no special name, but its member ptr var value must have the
  value of NULL
 */

struct Node {
  int data;
  Node *link;
};
typedef Node *NodePtr;

void headInsert(NodePtr &head, int theNumber);
NodePtr search(NodePtr head, int target);
void insert(NodePtr afterMe, int theNumber);

int main() {
  // head is pointer variable that points to the head of the linked list
  // head itself is not the 1st node
  NodePtr head;   // Anothe way to define: Node *head;

  // Use the operator new to create a new dynamic var that'll become the 1st
  // node of the list
  head = new Node;

  // Give values to the member var of the new node
  head->data = 3;
  head->link = nullptr;

  /* 
  TODO: Pointers as Iterators
  1.An iterator is a construct that allows you to cycle through the data items
    stored in a data structure so that you can perform whatever action you on
    each data item
   */
  // Moving through the linked list one node at a time starting at the head of
  // the list and cycling through all the nodes in the list
  NodePtr iter;
  int count = 0;
  for (iter = head; iter != nullptr; iter = iter->link) {
    printf("Var in %d is: %d\n", count, iter->data);
  }

  /**
   * TODO: Removing a node
   * Assume pointers before and discard have been positioned
   */
  NodePtr before;
  NodePtr discard;
  // set the ptr var of before point to the node that's pointed to by the ptr
  // var of discard
  before->link = discard->link;
  // If not using this node(discard) for sth else, you should destroy it and
  // return the memroy it uses to the freestore(heap) by a delete keyword
  delete discard;
}

/* 
TODO: empty list
1.If the ptr var head is supposed to point to the head of a linked list and you
  want to indicate that the list is empty, then you set the val of head to NULL:
  head = NULL 
! Always check to see if a func for manipulating a linked list works on the 
! empty list
 */

/* 
TODO: Memory Leak
A program that loses nodes is sometimes said to be a "memory leak",
to avoid such lost nodes, the program must always keep some pointer pointing to
the head of the list, usually the pointer in a pointer variable like head 
 */

/* 
TODO: Insert a Node at the Head of a list
 */
void headInsert(NodePtr &head, int theNumber) {
  // Create a new dynamic var pointed by tempPtr. (This new dynamic var is the
  // new node. This new node can be referred to as *tempPtr)
  NodePtr tempPtr;    // 创建一个NodePtr指针tempPtr
  tempPtr = new Node;   // 让NodePtr指针tempPtr先指向一个没有赋值的Node struct
  tempPtr->data = theNumber;

  // Make the link member of tempPtr point to the head node (1st node)
  // 让tempPtr的link(用来存储地址)等于head(head储存了原链表中冠node的地址)
  tempPtr->link = head;
  // 此时tempPtr->link中存储的地址和head中所存储的地址相同，均指向原链表中的冠node

  // Set the ptr var head point to tempPtr b/c ptr var head is supposed to
  // store the memory location of the first node
  // 修改head存储的地址，改为tempPtr本身所指向的地址，即NodePtr指针tempPtr本身的
  // 地址
  head = tempPtr;
  // 此时tempPtr->link指向原链表中的冠node，而head则指向tempPtr这个node
  // Textbook, Page750, Display13.3
}

/*
TODO: Searching a Linked List
Pseudocode for search func:
Make the ptr var here point to the head node (that is, 1st node) of the linked
list
while (here is not pointing to a node containing target and here is not pointing
to the last node) {
  Make here point to the next node in the list.
}
if (the node pointed to by here contains target) {
  return here;
} else {
  return NULL;
}
 */

// Precondition: the ptr head points to the head of a linked list. The ptr var
// in the last node is NULL. If the list is empty, then head is NULL.
// Returns a ptr that points to the 1st node that contains the target. If no
// node contains the target, the func returns NULL.
NodePtr search(NodePtr head, int target) {
  // head和here不是node，是一个ptr var that can point to a node, here/head本身指向
  // 了一个node
  NodePtr here = head;

  // check if the list is empty, or if here(head) is equal to NULL
  // 检查here/head是否指向空，如果是，返回空
  if (here == nullptr) {
    return nullptr;
  } else {
    // We test to see if here isn't pointing to the last node by testing to see 
    // if the member var here->link isn't equal to NULL
    // 链表最后一个node->link指向空，所以当here->link指向空时，here也就指向了最后一个
    // node
    // here是一个Node type ptr var，不是node（不要理解成node），它只是指向了一个node
    // 罢了
    // here = head(指向冠node的ptr var)，此时here也指向冠node，here->data代表冠node
    // 中data变量， here->link代表冠node中指针变量，而这个指针变量指向下一个node(亚
    // node)
    // 所以，here = here->link会使here本身直接指向亚node，此时here->link代表亚node
    // 中指针变量，而这个指针变量则指向再下一个node(季node)...
    // 如此反复，直到here指向的node的data等于target或者here指向的node的link指向空
    while (here->data != target && here->link != nullptr) {
      here = here->link;
    }
    // 当here指向的node的data等于target，返回here(存储了target的地址)
    if (here->data == target) {
      return here;
    } else {    // 当找不到的时候，返回空
      return nullptr;
    }
  }
}

/**
 * TODO: Inserting and Removing Nodes Inside a List
 */

// Precondition: afterMe points to a node in a linked list.
// Postcondition: A new node containing theNumber has been added after the
// node pointed to by afterMe
// afteMe is assumed
void insert(NodePtr afterMe, int theNumber) {
  // 创建一个ptr var tempPtr
  NodePtr tempPtr;
  // 让tempPtr指向 new node
  tempPtr = new Node;
  // 使new node的data(数据)等于theNumber
  tempPtr->data = theNumber;
  // 使new node的link(指针)等于afterMe的link(指针)，afterMe的link指向afterMe后面
  // 的node，所以tempPtr的link此时也指向afterMe后面的node
  tempPtr->link = afterMe->link;
  // 使afterMe的link等于tempPtr，tempPtr指向 new node，所以afterMe此时也指向了
  // new node
  afterMe->link = tempPtr;
}
