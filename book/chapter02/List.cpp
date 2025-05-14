#include "List.hpp"

#include <cassert>
#include <limits>

List::~List() {
  delete[] m_items;
  m_items = nullptr;
}

int List::Get(int index) {
  assert(index >= 0 && index <= m_count);

  return m_items[index];
}

void List::Insert(int index, int value) {
  assert(index >= 0 && index <= m_count);

  int *oldArray = m_items;
  m_count++;
  m_items = new int[m_count];

  for (int i = 0, j = 0; i < m_count; ++i) {
    if (index == i) {
      m_items[i] = value;
    }

    else {
      m_items[i] = oldArray[j];
      ++j;
    }
  }

  delete[] oldArray;
}

int List::Search(int val) {
  for (int i = 0; i < m_count; ++i) {
    if (m_items[i] == val) {
      return i;
    }
  }
  return std::numeric_limits<int>::max();
}

void List::Remove(int index) {
  assert(index >= 0 && index <= m_count);

  int *oldArray = m_items;

  m_count--;
  m_items = new int[m_count];

  for (int i = 0, j = 0; i < m_count; ++i, ++j) {
    if (index == j) {
      ++j;
    }

    m_items[i] = oldArray[j];
  }

  delete[] oldArray;
}

int List::Count() { return m_count; }