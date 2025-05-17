#pragma once
#ifndef BQUEUE_HPP
#define BQUEUE_HPP

#include "bNode.hpp"

class bQueue {
  size_t m_size{};
  bNode *m_front{nullptr}, *m_back{nullptr};

 public:
  bNode* getFront() const;
  bQueue() = default;
  ~bQueue();
  bool isEmpty() const;

  int front() const;
  int back() const;

  void enqueue(int value);
  void dequeue();
};

std::ostream& operator<<(std::ostream& os, const bQueue& obj);

#endif  // BQUEUE_HPP