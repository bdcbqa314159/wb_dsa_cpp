#pragma once
#ifndef BLINKED_LIST_HPP
#define BLINKED_LIST_HPP

#include <cstddef>

#include "bNode.hpp"

class bLinkedList {
  size_t m_size{};

 public:
  bNode *head{nullptr}, *tail{nullptr};

  bLinkedList() = default;
  ~bLinkedList();

  bNode* get(size_t index);

  void insertHead(int value);
  void insertTail(int value);
  void insertAt(size_t index, int value);

  size_t find(int value) const;

  void removeHead();
  void removeTail();
  void removeAt(size_t index);

  size_t size() const;
};

std::ostream& operator<<(std::ostream& os, const bLinkedList& obj);

#endif  // BLINKED_LIST_HPP