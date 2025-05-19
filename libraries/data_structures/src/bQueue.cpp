#include "bQueue.hpp"

#include <cstddef>
#include <limits>

#include "bNode.hpp"

bNode* bQueue::getFront() const { return m_front; }

bool bQueue::isEmpty() const { return (m_size == 0); }

int bQueue::front() const {
  if (m_front) {
    return m_front->value;
  }
  return std::numeric_limits<int>::max();
}

int bQueue::back() const {
  if (m_back) {
    return m_back->value;
  }
  return std::numeric_limits<int>::max();
}

void bQueue::enqueue(int value) {
  bNode* node = new bNode(value);

  if (m_size == 0) {
    m_back = node;
    m_front = node;
  }

  else {
    m_back->next = node;
    m_back = node;
  }

  ++m_size;
}

void bQueue::dequeue() {
  if (m_size == 0) {
    return;
  }
  bNode* node = m_front;
  m_front = m_front->next;
  delete node;
  --m_size;
}

bQueue::~bQueue() {
  while (m_size > 0) {
    dequeue();
  }
}

std::ostream& operator<<(std::ostream& os, const bQueue& obj) {
  bNode* node = obj.getFront();
  while (node) {
    os << *node;
    node = node->next;
  }
  return os;
}
