#pragma once
#ifndef BDOUBLYLINKED_LIST_HPP
#define BDOUBLYLINKED_LIST_HPP

#include <cstddef>

#include "bDoublyNode.hpp"

class bDoublyLinkedList {
  size_t m_size{};

 public:
  bDoublyNode *head{nullptr}, *tail{nullptr};

  bDoublyLinkedList() = default;
  ~bDoublyLinkedList();

  bDoublyNode* get(size_t index) const;

  void insertHead(int value);
  void insertTail(int value);
  void insertAt(size_t index, int value);

  size_t find(int value) const;

  void removeHead();
  void removeTail();
  void removeAt(size_t index);

  size_t size() const;
};

std::ostream& operator<<(std::ostream& os, const bDoublyLinkedList& obj);

#endif  // BDOUBLYLINKED_LIST_HPP