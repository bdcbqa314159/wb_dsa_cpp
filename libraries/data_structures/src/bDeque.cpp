#include "bDeque.hpp"

#include <limits>

#include "bDoublyNode.hpp"

bDoublyNode* bDeque::getFront() const { return m_front; }

bool bDeque::isEmpty() const { return (m_size == 0); }

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

void bDeque::enqueueFront(int value) {
  bDoublyNode* node = new bDoublyNode(value);

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

void bDeque::enqueueBack(int value) {
  if (m_size == 0) {
    return enqueueFront(value);
  }

  bDoublyNode* node = new bDoublyNode(value);
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
  m_front->prev = nullptr;

  delete node;
  --m_size;
}

void bDeque::dequeueBack() {
  if (m_size == 0) {
    return;
  }

  else if (m_size == 1) {
    return dequeueFront();
  }

  else {
    bDoublyNode* node = m_back;
    m_back = m_back->prev;
    m_back->next = nullptr;

    delete node;
    --m_size;
  }
}

bDeque::~bDeque() {
  while (m_size > 0) {
    dequeueFront();
  }
}

std::ostream& operator<<(std::ostream& os, const bDeque& obj) {
  bDoublyNode* node = obj.getFront();
  while (node) {
    os << *node;
    node = node->next;
  }
  return os;
}
