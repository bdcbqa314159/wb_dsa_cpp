#pragma once
#ifndef NODE_HPP
#define NODE_HPP

class Node {
 public:
  int value{};
  Node *next{nullptr};
  Node() = default;
};

void PrintNode(Node *node);

#endif  // NODE_HPP