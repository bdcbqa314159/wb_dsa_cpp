#include "bLinkedList.hpp"

#include <limits>
#include <ostream>

#include "bNode.hpp"

constexpr size_t size_t_max = std::numeric_limits<size_t>::max();

bNode* bLinkedList::get(size_t index) const {
  if (m_size == 0 || index >= m_size) {
    return nullptr;
  }

  bNode* node = head;
  for (size_t i = 0; i < m_size; ++i) {
    node = node->next;
  }

  return node;
}

size_t bLinkedList::size() const { return m_size; }

size_t bLinkedList::find(int value) const {
  if (m_size == 0) {
    return size_t_max;
  }

  size_t index = 0;
  bNode* node = head;
  while (node->value != value) {
    ++index;
    node = node->next;
    if (node == nullptr) {
      return size_t_max;
    }
  }

  return index;
}

void bLinkedList::insertHead(int value) {
  bNode* node = new bNode(value);
  node->next = head;
  head = node;

  if (m_size == 0) {
    tail = node;
  }

  ++m_size;
  return;
}

void bLinkedList::insertTail(int value) {
  if (m_size == 0) {
    return insertHead(value);
  }

  bNode* node = new bNode(value);
  tail->next = node;
  tail = node;

  ++m_size;
}

void bLinkedList::insertAt(size_t index, int value) {
  if (index > m_size) {
    return;
  }

  if (index == 0) {
    return insertHead(value);
  }

  else if (index == m_size) {
    return insertTail(value);
  }

  else {
    bNode* prevNode = head;
    for (size_t i = 0; i < index - 1; ++i) {
      prevNode = prevNode->next;
    }

    bNode* nextNode = prevNode->next;
    bNode* node = new bNode(value);
    prevNode->next = node;
    node->next = nextNode;
    ++m_size;
    return;
  }
}

void bLinkedList::removeHead() {
  if (m_size == 0) {
    return;
  }

  bNode* node = head;
  head = head->next;
  delete node;
  --m_size;
  return;
}

void bLinkedList::removeTail() {
  if (m_size == 0) {
    return;
  }

  bNode* prevNode = head;
  bNode* node = prevNode->next;

  while (node->next) {
    prevNode = node;
    node = node->next;
  }

  prevNode->next = nullptr;
  tail = prevNode;
  delete node;
  --m_size;
  return;
}

void bLinkedList::removeAt(size_t index) {
  if (m_size == 0) {
    return;
  }

  if (index == 0) {
    return removeHead();
  }

  else if (index == m_size - 1) {
    return removeTail();
  }

  else {
    bNode* prevNode = head;
    for (size_t i = 0; i < index - 1; ++i) {
      prevNode = prevNode->next;
    }

    bNode* node = prevNode->next;
    bNode* nextNode = node->next;

    prevNode->next = nextNode;
    delete node;
    --m_size;
  }
}

bLinkedList::~bLinkedList() {
  while (m_size > 0) {
    removeHead();
  }
}

std::ostream& operator<<(std::ostream& os, const bLinkedList& obj) {
  bNode* node = obj.get(0);

  while (node) {
    os << *node;
    node = node->next;
  }
  return os;
}
