#include <cstddef>
#include <iostream>

#include "bDoublyLinkedList.hpp"

using namespace std;
int main() {
  bDoublyLinkedList linkedList = bDoublyLinkedList();

  // it will be printed backwardly
  // 43->NULL
  linkedList.insertHead(43);

  // 43->76->NULL
  linkedList.insertHead(76);

  // 15->43->76->NULL
  linkedList.insertTail(15);

  // 44->15->43->76->NULL
  linkedList.insertTail(44);

  // Print the list element
  cout << "First Printed:" << endl;
  cout << linkedList;
  cout << endl;

  // 100->44->15->43->76->NULL
  linkedList.insertAt(4, 100);

  // 100->44->48->15->43->76->NULL
  linkedList.insertAt(3, 48);

  // 100->44->48->15->43->76->22->NULL
  linkedList.insertAt(0, 22);

  // Print the list element
  cout << "Second Printed:" << endl;
  cout << linkedList;
  cout << endl;

  return 0;
}