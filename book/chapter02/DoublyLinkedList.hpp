#pragma once
#ifndef DOUBLY_LINKEDLIST_HPP
#define DOUBLY_LINKEDLIST_HPP

#include <cassert>
#include <iostream>
#include <limits>

#include "DoublyNode.hpp"

template <typename T>
class DoublyLinkedList {
 private:
  int m_count{0};

 public:
  DoublyNode<T> *head{nullptr}, *tail{nullptr};

  DoublyLinkedList() = default;

  DoublyNode<T> *get(int index);

  void insertHead(T value);
  void insertTail(T value);
  void insertAt(int index, T value);

  int search(T value);

  void removeHead();
  void removeTail();
  void removeAt(int index);

  int count() const;
  void printList() const;
  void printListBackward() const;
};

template <typename T>
DoublyNode<T> *DoublyLinkedList<T>::get(int index) {
  assert(index >= 0 && index < m_count);
  DoublyNode<T> *current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }
  return current;
}

template <typename T>
void DoublyLinkedList<T>::insertHead(T value) {
  DoublyNode<T> *node = new DoublyNode<T>(value);

  node->next = head;

  if (head != nullptr) {
    head->prev = node;
  }

  head = node;

  if (m_count == 0) {
    tail = node;
  }
  ++m_count;
}

template <typename T>
void DoublyLinkedList<T>::insertTail(T value) {
  if (m_count == 0) {
    insertHead(value);
    return;
  }

  DoublyNode<T> *node = new DoublyNode<T>(value);

  tail->next = node;
  node->prev = tail;

  tail = node;
  ++m_count;
}

template <typename T>
void DoublyLinkedList<T>::insertAt(int index, T value) {
  assert(index >= 0 && index <= m_count);

  if (index == 0) {
    insertHead(value);
    return;
  }

  else if (index == m_count) {
    insertTail(value);
    return;
  }

  DoublyNode<T> *prevNode = head;

  for (int i = 0; i < index - 1; ++i) {
    prevNode = prevNode->next;
  }

  DoublyNode<T> *nextNode = prevNode->next;

  DoublyNode<T> *node = new DoublyNode<T>(value);

  node->next = nextNode;
  node->prev = prevNode;

  prevNode->next = node;
  nextNode->prev = node;

  ++m_count;
}

template <typename T>
int DoublyLinkedList<T>::search(T value) {
  if (m_count == 0) {
    return std::numeric_limits<int>::max();
  }

  int index = 0;
  DoublyNode<T> *node = head;

  while (node->value != value) {
    index++;
    node = node->next;
    if (node == nullptr) {
      return std::numeric_limits<int>::max();
    }
  }
  return index;
}

template <typename T>
void DoublyLinkedList<T>::removeHead() {
  if (m_count == 0) {
    return;
  }

  DoublyNode<T> *node = head;
  head = head->next;
  delete node;

  if (head != nullptr) {
    head->prev = nullptr;
  }

  --m_count;
}

template <typename T>
void DoublyLinkedList<T>::removeTail() {
  if (m_count == 0) {
    return;
  }

  if (m_count == 1) {
    removeHead();
    return;
  }

  DoublyNode<T> *node = tail;
  tail = tail->prev;
  tail->next = nullptr;
  delete node;
  --m_count;
}

template <typename T>
void DoublyLinkedList<T>::removeAt(int index) {
  if (index < 0 || index >= m_count) {
    return;
  }
  if (m_count == 0) {
    return;
  }

  if (index == 0) {
    removeHead();
    return;
  }

  if (index == m_count - 1) {
    removeTail();
    return;
  }

  DoublyNode<T> *prevNode = head;

  for (int i = 0; i < index - 1; ++i) {
    prevNode = prevNode->next;
  }

  DoublyNode<T> *node = prevNode->next;  // Node to be deleted
  DoublyNode<T> *nextNode = node->next;
  prevNode->next = nextNode;
  nextNode->prev = prevNode;

  delete node;
  --m_count;
}

template <typename T>
int DoublyLinkedList<T>::count() const {
  return m_count;
}

template <typename T>
void DoublyLinkedList<T>::printList() const {
  DoublyNode<T> *node = head;

  while (node != nullptr) {
    std::cout << node->value << " -> ";
    node = node->next;
  }

  std::cout << "nullptr" << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::printListBackward() const {
  DoublyNode<T> *node = tail;

  while (node != nullptr) {
    std::cout << node->value << " -> ";
    node = node->prev;
  }

  std::cout << "nullptr" << std::endl;
}

#endif  // DOUBLY_LINKEDLIST_HPP