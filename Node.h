#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
  Node(std::string k, int v, Node * p, Node * n): key(k), value(v), prev(p), next(n) {}

  Node(std::string k, int v, Node * p): key(k), value(v), prev(p) {
    next = nullptr;
  }

  Node(std::string k, int v) : key(k), value(v) {
    next = nullptr;
    prev = nullptr;
  }

  virtual ~Node() {}

  std::string key;
  int value;
  Node * next;
  Node * prev;

  friend bool operator>(const Node& a, const Node& b);
  friend bool operator<(const Node& a, const Node& b);
  friend bool operator==(const Node& a, const Node &b);
};

#endif