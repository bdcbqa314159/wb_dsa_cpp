#include <iostream>

#include "bQueue.hpp"

using namespace std;

int main() {
  // NULL
  bQueue queueInt = bQueue();

  // Enqueue several numbers to the queue
  queueInt.enqueue(35);
  queueInt.enqueue(91);
  queueInt.enqueue(26);
  queueInt.enqueue(78);
  queueInt.enqueue(44);
  queueInt.enqueue(12);

  cout << queueInt << endl;

  return 0;
}