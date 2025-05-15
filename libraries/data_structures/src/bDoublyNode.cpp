#include "bDoublyNode.hpp"

#include <iostream>

bDoublyNode::bDoublyNode(int otherValue)
    : value(otherValue), next(nullptr), prev(nullptr) {}

std::ostream& operator<<(std::ostream& os, const bDoublyNode& obj) {
  os << obj.value;
  if (obj.next != nullptr) {
    os << " <-> ";
  }

  return os;
}