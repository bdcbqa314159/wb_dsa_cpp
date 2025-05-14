#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cassert>
#include <iostream>
#include <limits>

#include "NodeTemplate.hpp"

template <typename T>
class LinkedList {
 private:
  int m_count{0};

 public:
  Node<T> *head{nullptr}, *tail{nullptr};

  LinkedList() = default;

  Node<T> *get(int index);

  void insertHead(T value);
  void insertTail(T value);
  void insertAt(int index, T value);

  int search(T value);

  void removeHead();
  void removeTail();
  void removeAt(int index);

  int count() const;
  void printList() const;
};

template <typename T>
Node<T> *LinkedList<T>::get(int index) {
  assert(index >= 0 && index < m_count);
  Node<T> *current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }
  return current;
}

template <typename T>
void LinkedList<T>::insertHead(T value) {
  Node<T> *node = new Node<T>(value);

  node->next = head;
  head = node;

  if (m_count == 0) {
    tail = node;
  }
  ++m_count;
}

template <typename T>
void LinkedList<T>::insertTail(T value) {
  if (m_count == 0) {
    insertHead(value);
    return;
  }

  Node<T> *node = new Node<T>(value);

  tail->next = node;

  tail = node;
  ++m_count;
}

template <typename T>
void LinkedList<T>::insertAt(int index, T value) {
  assert(index >= 0 && index <= m_count);

  if (index == 0) {
    insertHead(value);
    return;
  }

  else if (index == m_count) {
    insertTail(value);
    return;
  }

  Node<T> *prevNode = head;

  for (int i = 0; i < index - 1; ++i) {
    prevNode = prevNode->next;
  }

  Node<T> *nextNode = prevNode->next;

  Node<T> *node = new Node<T>(value);
  prevNode->next = node;
  node->next = nextNode;

  ++m_count;
}

template <typename T>
int LinkedList<T>::search(T value) {
  if (m_count == 0) {
    return std::numeric_limits<int>::max();
  }

  int index = 0;
  Node<T> *node = head;

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
void LinkedList<T>::removeHead() {
  if (m_count == 0) {
    return;
  }

  Node<T> *node = head;
  head = head->next;
  delete node;

  --m_count;
}

template <typename T>
void LinkedList<T>::removeTail() {
  if (m_count == 0) {
    return;
  }

  if (m_count == 1) {
    removeHead();
    return;
  }

  Node<T> *prevNode = head;
  Node<T> *node = head->next;

  while (node->next != nullptr) {
    prevNode = node;
    node = node->next;
  }

  prevNode->next = nullptr;
  tail = prevNode;
  delete node;
  --m_count;
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
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

  Node<T> *prevNode = head;

  for (int i = 0; i < index - 1; ++i) {
    prevNode = prevNode->next;
  }

  Node<T> *node = prevNode->next;  // Node to be deleted
  Node<T> *nextNode = node->next;
  prevNode->next = nextNode;
  delete node;
  --m_count;
}

template <typename T>
int LinkedList<T>::count() const {
  return m_count;
}

template <typename T>
void LinkedList<T>::printList() const {
  Node<T> *node = head;

  while (node != nullptr) {
    std::cout << node->value << " -> ";
    node = node->next;
  }

  std::cout << "nullptr" << std::endl;
}

#endif  // LINKEDLIST_HPP