#include "bDynamicArray.hpp"

#include <cassert>
#include <cstddef>
#include <limits>

size_t bDynamicArray::size() const { return m_size; }

size_t bDynamicArray::find(int value) const {
  if (m_size == 0) {
    return std::numeric_limits<size_t>::max();
  }

  for (size_t i = 0; i < m_size; ++i) {
    if (m_data[i] == value) {
      return i;
    }
  }

  return std::numeric_limits<size_t>::max();
}

int bDynamicArray::get(size_t index) const {
  if (index >= m_size) {
    return std::numeric_limits<int>::max();
  }

  return m_data[index];
}

void bDynamicArray::remove(size_t index) {
  if (index >= m_size) return;

  int *old_data = m_data;
  --m_size;
  m_data = new int[m_size];

  for (size_t i = 0, j = 0; i < m_size; ++i, ++j) {
    if (index == i) {
      ++j;
    }

    m_data[i] = old_data[j];
  }

  delete[] old_data;
}

void bDynamicArray::insert(size_t index, int value) {
  if (index >= m_size) return;

  int *old_data = m_data;
  ++m_size;
  m_data = new int[m_size];

  for (size_t i = 0, j = 0; i < m_size; ++i) {
    if (index == i) {
      m_data[i] = value;
    }

    else {
      m_data[i] = old_data[j];
      ++j;
    }
  }

  delete[] old_data;
}