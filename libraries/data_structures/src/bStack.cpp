#include "bStack.hpp"

#include <limits>

#include "bNode.hpp"

bool bStack::isEmpty() const { return (m_size == 0); }

bNode* bStack::getTop() const { return m_top; }

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
  bNode* top = obj.getTop();

  while (top) {
    os << *top;
    top = top->next;
  }
  return os;
}