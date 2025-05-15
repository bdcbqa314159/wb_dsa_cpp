#include "bDoublyLinkedList.hpp"

#include <cstddef>
#include <limits>
#include <ostream>

#include "bDoublyNode.hpp"

constexpr size_t size_t_max = std::numeric_limits<size_t>::max();

bDoublyNode* bDoublyLinkedList::get(size_t index) const {
  if (index >= m_size) {
    return nullptr;
  }

  bDoublyNode* node = head;
  for (size_t i = 0; i < index; ++i) {
    node = node->next;
  }

  return node;
}

size_t bDoublyLinkedList::size() const { return m_size; }

size_t bDoublyLinkedList::find(int value) const {
  if (m_size == 0) {
    return size_t_max;
  }

  bDoublyNode* node = head;
  size_t index = 0;
  while (node->value != value) {
    ++index;
    node = node->next;
    if (node == nullptr) {
      return size_t_max;
    }
  }
  return index;
}

void bDoublyLinkedList::insertHead(int value) {
  bDoublyNode* node = new bDoublyNode(value);
  node->next = head;

  if (head) {
    head->prev = node;
  }

  head = node;

  if (m_size == 0) {
    tail = node;
  }

  ++m_size;
  return;
}

void bDoublyLinkedList::insertTail(int value) {
  if (m_size == 0) {
    return insertHead(value);
  }
  bDoublyNode* node = new bDoublyNode(value);
  tail->next = node;
  node->prev = tail;
  tail = node;
  ++m_size;
}

void bDoublyLinkedList::insertAt(size_t index, int value) {
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
    bDoublyNode* prevNode = head;
    for (size_t i = 0; i < index - 1; ++i) {
      prevNode = prevNode->next;
    }

    bDoublyNode* nextNode = prevNode->next;
    bDoublyNode* node = new bDoublyNode(value);
    prevNode->next = node;
    node->prev = prevNode;
    node->next = nextNode;
    nextNode->prev = node;
    ++m_size;
  }
}

void bDoublyLinkedList::removeHead() {
  if (m_size == 0) {
    return;
  }

  bDoublyNode* node = head;
  head = head->next;
  delete node;

  if (head) {
    head->prev = nullptr;
  }
  --m_size;
}

void bDoublyLinkedList::removeTail() {
  if (m_size == 0) {
    return;
  }

  if (m_size == 1) {
    return removeHead();
  }

  bDoublyNode* node = tail;
  tail = tail->prev;
  tail->next = nullptr;

  delete node;
  --m_size;
}

void bDoublyLinkedList::removeAt(size_t index) {
  if (index > m_size) {
    return;
  }

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
    bDoublyNode* prevNode = head;
    for (size_t i = 0; i < index - 1; ++i) {
      prevNode = prevNode->next;
    }

    bDoublyNode* node = prevNode->next;
    bDoublyNode* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete node;
    --m_size;
  }
}

bDoublyLinkedList::~bDoublyLinkedList() {
  while (m_size > 0) {
    removeHead();
  }
}

std::ostream& operator<<(std::ostream& os, const bDoublyLinkedList& obj) {
  bDoublyNode* node = obj.get(0);
  os << "h:";
  while (node) {
    os << *node;
    node = node->next;
  }
  os << ":t";

  return os;
}
