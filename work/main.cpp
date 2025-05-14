#include <iostream>

class Node {
 public:
  int value{0};
  Node* next{nullptr};

  Node() = default;
  Node(int otherValue) : value(otherValue), next(nullptr) {}
};

inline std::ostream& operator<<(std::ostream& os, const Node& obj) {
  Node temp(obj);
  Node* pTemp = &temp;
  while (pTemp != nullptr) {
    os << pTemp->value << " -> ";
    pTemp = pTemp->next;
  }
  os << "nullptr";
  return os;
}

int main() {
  Node n1(2);
  Node n2(3);
  Node n3(4);

  n1.next = &n2;
  n2.next = &n3;

  std::cout << n1 << "\n";

  return 0;
}