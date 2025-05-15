#pragma once
#ifndef STACK_HPP
#define STACK_HPP

#include "NodeTemplate.hpp"

template <typename T>
class Stack {
 private:
  int m_count;
  Node<T>* m_top;

 public:
  Stack();
  bool IsEmpty();
  T Top();
  void Push(T val);
  void Pop();
};

template <typename T>
Stack<T>::Stack() : m_count(0), m_top(NULL) {}

template <typename T>
bool Stack<T>::IsEmpty() {
  return m_count <= 0;
}

template <typename T>
T Stack<T>::Top() {
  return m_top->value;
}

template <typename T>
void Stack<T>::Push(T val) {
  Node<T>* node = new Node<T>(val);

  node->next = m_top;

  m_top = node;

  m_count++;
}

template <typename T>
void Stack<T>::Pop() {
  if (IsEmpty()) return;

  Node<T>* node = m_top;

  m_top = m_top->next;

  delete node;

  m_count--;
}

#endif  // STACK_HPP