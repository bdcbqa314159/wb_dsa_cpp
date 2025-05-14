#include <cstddef>
#include <iostream>

#include "bLinkedList.hpp"

using namespace std;
int main() {
  bLinkedList linkedList = bLinkedList();

  // 43->NULL
  linkedList.insertHead(43);

  // 76->43->NULL
  linkedList.insertHead(76);

  // 76->43->15->NULL
  linkedList.insertTail(15);

  // 76->43->15->44->NULL
  linkedList.insertTail(44);

  // Print the list element
  cout << "First Printed:" << endl;
  cout << linkedList;
  cout << endl;

  // 76->43->15->44->100->NULL
  linkedList.insertAt(4, 100);

  // 76->43->15->48->44->100->NULL
  linkedList.insertAt(3, 48);

  // 22->76->43->15->48->44->100->NULL
  linkedList.insertAt(0, 22);

  // Print the list element
  cout << "Second Printed:" << endl;
  cout << linkedList;
  cout << endl;

  // Get value of the second index
  // It should be 43
  cout << "Get value of the second index:" << endl;
  bNode* get = linkedList.get(2);
  if (get != NULL)
    cout << get->value;
  else
    cout << "not found";
  cout << endl << endl;

  // Find the position of value 15
  // It must be 3
  cout << "The position of value 15:" << endl;
  int srch = linkedList.find(15);
  cout << srch << endl << endl;

  // Remove first element
  cout << "Remove the first element:" << endl;
  linkedList.removeAt(0);
  // 76->43->15->48->44->100->NULL
  cout << linkedList;
  cout << endl;

  // Remove fifth element
  cout << "Remove the fifth element:" << endl;
  linkedList.removeAt(4);
  // 76->43->15->48->100->NULL
  cout << linkedList;
  cout << endl;

  // Remove tenth element
  cout << "Remove the tenth element:" << endl;
  linkedList.removeAt(9);
  // Nothing happen
  // 76->43->15->48->100->NULL
  cout << linkedList;
  cout << endl;

  return 0;
}