#pragma once
#ifndef BDEQUE_HPP
#define BDEQUE_HPP

#include "bDoublyNode.hpp"

class bDeque {
  size_t m_size{};
  bDoublyNode *m_front{nullptr}, *m_back{nullptr};

 public:
  bDeque() = default;
  ~bDeque();
  bool isEmpty() const;

  bDoublyNode* getFront() const;

  int front() const;
  int back() const;

  void enqueueFront(int val);
  void enqueueBack(int val);

  void dequeueFront();
  void dequeueBack();
};

std::ostream& operator<<(std::ostream& os, const bDeque& obj);

#endif  // BDEQUE_HPP