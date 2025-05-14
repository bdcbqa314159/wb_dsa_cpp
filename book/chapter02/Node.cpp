#include "Node.hpp"

#include <iostream>

void PrintNode(Node *node) {
  while (node != nullptr) {
    std::cout << node->value << " -> ";
    node = node->next;
  }

  std::cout << "nullptr" << std::endl;
}