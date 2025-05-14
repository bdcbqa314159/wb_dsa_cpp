#include "bNode.hpp"

#include <iostream>

bNode::bNode(int otherValue) : value(otherValue), next(nullptr) {}

std::ostream& operator<<(std::ostream& os, const bNode& obj) {
  os << obj.value;
  if (obj.next != nullptr) {
    os << " -> ";
  }

  return os;
}