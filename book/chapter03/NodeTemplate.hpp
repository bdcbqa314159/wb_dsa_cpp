#pragma once
#ifndef NODE_TEMPLATE_HPP
#define NODE_TEMPLATE_HPP
#include <iostream>

template <typename T>
class Node {
 public:
  T value{};
  Node<T> *next{nullptr};
  Node() = default;
  Node(T val) : value(val), next(nullptr) {}
};

template <typename T>
void PrintNode(Node<T> *node) {
  while (node != nullptr) {
    std::cout << node->value << " -> ";
    node = node->next;
  }

  std::cout << "nullptr" << std::endl;
}

#endif  // NODE_TEMPLATE_HPP