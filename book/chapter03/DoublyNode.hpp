#pragma once
#ifndef DOUBLY_NODE_HPP
#define DOUBLY_NODE_HPP

template <typename T>
class DoublyNode {
 public:
  T value{};
  DoublyNode<T> *next{nullptr}, *prev{nullptr};
  DoublyNode() = default;
  DoublyNode(T val) : value(val), next(nullptr), prev(nullptr) {}
};

#endif  // DOUBLY_NODE_HPP