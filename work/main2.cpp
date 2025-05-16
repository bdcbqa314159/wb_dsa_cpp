#include <iostream>

#include "bStack.hpp"

using namespace std;

int main() {
  // NULL
  bStack stackInt = bStack();

  // Store several numbers to the stack
  stackInt.push(32);
  stackInt.push(47);
  stackInt.push(18);
  stackInt.push(59);
  stackInt.push(88);
  stackInt.push(91);

  // // list the element of stack
  // while (!stackInt.isEmpty()) {
  //   // Get the top element
  //   cout << stackInt.top() << " - ";

  //   // Remove the top element
  //   stackInt.pop();
  // }
  // cout << "END" << endl;

  cout << stackInt << endl;

  return 0;
}