#pragma once
#ifndef BNODE_HPP
#define BNODE_HPP

#include <iostream>

class Node {
 public:
  int value{0};
  Node* next{nullptr};

  Node() = default;
  Node(int otherValue) : value(otherValue), next(nullptr) {}

  ~Node() {
    if (next != nullptr) {
      delete next;
    }
  }
};

inline std::ostream& operator<<(std::ostream& os, const Node& obj) {
  Node temp(obj);
  Node* pTemp = &temp;
  while (pTemp != nullptr) {
    os << pTemp->value << " -> ";
    pTemp = pTemp->next;
  }
  os << "nullptr\n";
  return os;
}

#endif  // BNODE_HPP