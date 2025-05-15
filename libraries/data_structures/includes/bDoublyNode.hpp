#pragma once
#ifndef BDOUBLYNODE_HPP
#define BDOUBLYNODE_HPP

#include <iostream>

class bDoublyNode {
 public:
  int value{};
  bDoublyNode *next{nullptr}, *prev{nullptr};

  bDoublyNode() = default;
  bDoublyNode(int otherValue);
};

std::ostream& operator<<(std::ostream& os, const bDoublyNode& obj);

#endif  // BDOUBLYNODE_HPP