#pragma once
#ifndef BNODE_HPP
#define BNODE_HPP

#include <iostream>

class bNode {
 public:
  int value{};
  bNode* next{nullptr};

  bNode() = default;
  bNode(int otherValue);
};

std::ostream& operator<<(std::ostream& os, const bNode& obj);

#endif  // BNODE_HPP