#include "NodeTemplate.hpp"

int main() {
  // +------+------+
  // | 4.93 | NULL |
  // +------+------+
  Node<float>* node1 = new Node<float>(4.93);

  // +------+------+
  // | 6.45 | NULL |
  // +------+------+
  Node<float>* node2 = new Node<float>(6.45);

  // +------+------+
  // | 8.17 | NULL |
  // +------+------+
  Node<float>* node3 = new Node<float>(8.17);

  // +------+------+  +------+------+  +------+------+
  // | 4.93 |   +---->| 6.45 | NULL |  | 8.17 | NULL |
  // +------+------+  +------+------+  +------+------+
  node1->next = node2;

  // +------+------+  +------+------+  +------+------+
  // | 4.93 |   +---->| 6.45 |   +---->| 8.17 | NULL |
  // +------+------+  +------+------+  +------+------+
  node2->next = node3;

  // Print the node
  PrintNode(node1);

  return 0;
}