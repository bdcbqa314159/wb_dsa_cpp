#include <iostream>

#include "bStack.hpp"

using namespace std;

int main() {
  bStack stackInt = bStack();

  stackInt.push(32);
  stackInt.push(47);
  stackInt.push(18);
  stackInt.push(59);
  stackInt.push(88);
  stackInt.push(91);

  cout << stackInt << endl;

  return 0;
}