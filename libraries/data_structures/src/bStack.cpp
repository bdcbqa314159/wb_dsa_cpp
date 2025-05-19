#include "bStack.hpp"

#include <limits>

#include "bNode.hpp"

bNode* bStack::getTop() const { return m_top; }

bool bStack::isEmpty() const { return (m_size == 0); }

int bStack::top() const {
  if (m_top) {
    return m_top->value;
  }
  return std::numeric_limits<int>::max();
}

void bStack::push(int value) {
  bNode* node = new bNode(value);
  node->next = m_top;
  m_top = node;

  ++m_size;
}

void bStack::pop() {
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
