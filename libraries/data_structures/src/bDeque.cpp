#include "bDeque.hpp"

#include <limits>

#include "bDoublyNode.hpp"

bool bDeque::isEmpty() const { return (m_size == 0); }

bDoublyNode* bDeque::getFront() const { return m_front; }

void bDeque::enqueueFront(int val) {
  bDoublyNode* node = new bDoublyNode(val);

  node->next = m_front;

  if (m_front) {
    m_front->prev = node;
  }

  m_front = node;

  if (m_size == 0) {
    m_back = node;
  }
  ++m_size;
}

void bDeque::enqueueBack(int val) {
  if (m_size == 0) {
    return enqueueFront(val);
  }

  bDoublyNode* node = new bDoublyNode(val);

  m_back->next = node;
  node->prev = m_back;

  m_back = node;

  ++m_size;
}

void bDeque::dequeueFront() {
  if (m_size == 0) {
    return;
  }

  bDoublyNode* node = m_front;
  m_front = m_front->next;

  if (m_front) {
    m_front->prev = nullptr;
  }

  delete node;
  --m_size;
}

void bDeque::dequeueBack() {
  if (m_size == 0) {
    return;
  }

  if (m_size == 1) {
    return dequeueFront();
  }

  bDoublyNode* node = m_back;
  m_back = m_back->prev;
  m_back->next = nullptr;

  delete node;
  --m_size;
}

bDeque::~bDeque() {
  while (m_size > 0) {
    dequeueFront();
  }
}

int bDeque::front() const {
  if (m_front) {
    return m_front->value;
  }

  return std::numeric_limits<int>::max();
}

int bDeque::back() const {
  if (m_back) {
    return m_back->value;
  }

  return std::numeric_limits<int>::max();
}

std::ostream& operator<<(std::ostream& os, const bDeque& obj) {
  bDoublyNode* node = obj.getFront();

  while (node) {
    os << *node;
    node = node->next;
  }

  return os;
}