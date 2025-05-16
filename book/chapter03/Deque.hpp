#pragma once
#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "DoublyNode.hpp"

template <typename T>
class Deque {
 private:
  int m_count;
  DoublyNode<T>* m_front;
  DoublyNode<T>* m_back;

 public:
  Deque();
  bool IsEmpty();
  T Front();
  T Back();
  void EnqueueFront(T val);
  void EnqueueBack(T val);
  void DequeueFront();
  void DequeueBack();
};

template <typename T>
Deque<T>::Deque() : m_count(0), m_front(nullptr), m_back(nullptr) {}

template <typename T>
bool Deque<T>::IsEmpty() {
  return m_count <= 0;
}

template <typename T>
T Deque<T>::Front() {
  return m_front->value;
}

template <typename T>
T Deque<T>::Back() {
  return m_back->value;
}

template <typename T>
void Deque<T>::EnqueueFront(T val) {
  DoublyNode<T>* node = new DoublyNode<T>(val);

  node->next = m_front;

  if (m_front != nullptr) m_front->prev = node;

  m_front = node;
  if (m_count == 0) m_back = m_front;

  m_count++;
}

template <typename T>
void Deque<T>::EnqueueBack(T val) {
  if (m_count == 0) {
    EnqueueFront(val);
    return;
  }

  DoublyNode<T>* node = new DoublyNode<T>(val);

  m_back->next = node;

  node->prev = m_back;

  m_back = node;

  m_count++;
}

template <typename T>
void Deque<T>::DequeueFront() {
  if (m_count == 0) return;

  DoublyNode<T>* node = m_front;

  m_front = m_front->next;

  delete node;

  if (m_front != nullptr) m_front->prev = nullptr;

  m_count--;
}

template <typename T>
void Deque<T>::DequeueBack() {
  if (m_count == 0) return;

  if (m_count == 1) {
    DequeueFront();
    return;
  }

  DoublyNode<T>* node = m_back;

  m_back = m_back->prev;

  m_back->next = nullptr;

  delete node;

  m_count--;
}

#endif  // DEQUE_HPP