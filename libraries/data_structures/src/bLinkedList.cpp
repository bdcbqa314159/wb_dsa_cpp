#include "bLinkedList.hpp"

#include <cstddef>
#include <limits>

#include "bNode.hpp"

bNode* bLinkedList::get(size_t index) {
  if (index >= m_size) return nullptr;

  bNode* current = head;
  for (size_t i = 0; i < index; ++i) {
    current = current->next;
  }

  return current;
}

void bLinkedList::insertHead(int value) {
  bNode* node = new bNode(value);

  node->next = head;
  head = node;

  if (m_size == 0) {
    tail = node;
  }

  ++m_size;
}

void bLinkedList::insertTail(int value) {
  if (m_size == 0) {
    insertHead(value);
    return;
  }

  bNode* node = new bNode(value);
  tail->next = node;
  tail = node;
  ++m_size;
}

void bLinkedList::insertAt(size_t index, int value) {
  if (index > m_size) return;

  if (index == 0) {
    insertHead(value);
    return;
  }

  else if (index == m_size) {
    insertTail(value);
    return;
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
  }
}

size_t bLinkedList::find(int value) const {
  if (m_size == 0) {
    return std::numeric_limits<size_t>::max();
  }

  size_t index = 0;
  bNode* node = head;

  while (node->value != value) {
    index++;
    node = node->next;

    if (node == nullptr) {
      return std::numeric_limits<size_t>::max();
    }
  }
  return index;
}

void bLinkedList::removeHead() {
  if (m_size == 0) return;

  bNode* node = head;
  head = head->next;
  delete node;

  --m_size;
}

void bLinkedList::removeTail() {
  if (m_size == 0) return;
  if (m_size == 1) {
    removeHead();
    return;
  }

  bNode* prevNode = head;
  bNode* node = head->next;

  while (node->next != nullptr) {
    prevNode = node;
    node = node->next;
  }

  prevNode->next = nullptr;
  tail = prevNode;
  delete node;
  --m_size;
}

void bLinkedList::removeAt(size_t index) {
  if (index >= m_size) return;

  if (m_size == 0) return;

  if (index == 0) {
    removeHead();
    return;
  }

  if (index == m_size - 1) {
    removeTail();
    return;
  }

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

size_t bLinkedList::size() const { return m_size; }

bLinkedList::~bLinkedList() {
  while (m_size > 0) {
    removeHead();
  }
}

std::ostream& operator<<(std::ostream& os, const bLinkedList& obj) {
  bNode* node = obj.head;

  while (node != nullptr) {
    os << *node;
    node = node->next;
  }
  return os;
}