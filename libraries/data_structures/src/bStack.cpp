#include "bStack.hpp"

#include <limits>

#include "bNode.hpp"

bNode* bStack::getTop() const {
  if (m_top) {
    return m_top;
  }
  return nullptr;
}

bool bStack::isEmpty() const { return (m_size == 0); }

int bStack::top() const {
  if (m_top) {
    return m_top->value;
  }
  return std::numeric_limits<int>::max();
}

void bStack::push(int val) {
  bNode* node = new bNode(val);

  node->next = m_top;
  m_top = node;

  ++m_size;
}

void bStack::pop() {
  if (m_size == 0) {
    return;
  }

  bNode* node = m_top;
  m_top = m_top->next;
  delete node;
  --m_size;
}

bStack::~bStack() {
  while (m_size > 0) {
    pop();
  }
}

std::ostream& operator<<(std::ostream& os, const bStack& obj) {
  bNode* node = obj.getTop();

  while (node) {
    os << *node;
    node = node->next;
  }
  return os;
}
