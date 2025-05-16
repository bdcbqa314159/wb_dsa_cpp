#pragma once
#ifndef BSTACK_HPP
#define BSTACK_HPP

#include "bNode.hpp"

class bStack {
  size_t m_size{};
  bNode* m_top{nullptr};

 public:
  bStack() = default;
  ~bStack();
  bNode* getTop() const;
  bool isEmpty() const;
  int top() const;
  void push(int val);
  void pop();
};

std::ostream& operator<<(std::ostream& os, const bStack& obj);

#endif  // BSTACK_HPP