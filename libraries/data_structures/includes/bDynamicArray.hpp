#pragma once
#ifndef BDYNAMIC_ARRAY_HPP
#define BDYNAMIC_ARRAY_HPP

#include <cstddef>

class bDynamicArray {
 private:
  size_t m_size{0};
  int *m_data{nullptr};

 public:
  bDynamicArray() = default;
  bDynamicArray(size_t size) : m_size(size) { m_data = new int[m_size]; }

  ~bDynamicArray() {
    if (m_data) {
      delete[] m_data;
      m_data = nullptr;
    }
  }

  int get(size_t index) const;
  void insert(size_t index, int value);
  size_t find(int val) const;
  void remove(size_t index);
  size_t size() const;
};

#endif  // BDYNAMIC_ARRAY_HPP