#include <iostream>

#include "bDeque.hpp"

using namespace std;

int main() {
  // NULL
  bDeque deque = bDeque();

  // Enqueue several numbers to the deque
  // 26
  deque.enqueueFront(26);
  // 26 - 78
  deque.enqueueBack(78);
  // 26 - 78 - 44
  deque.enqueueBack(44);
  // 91 - 26 - 78 - 44
  deque.enqueueFront(91);
  // 35 - 91 - 26 - 78 - 44
  deque.enqueueFront(35);
  // 35 - 91 - 26 - 78 - 44 - 12
  deque.enqueueBack(12);

  cout << deque << endl;

  return 0;
}