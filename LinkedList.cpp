#include "LinkedList.h"
#include <string>

LinkedList::LinkedList() {
  list_size = 0;
  head = nullptr;
  tail = head;
}

LinkedList::~LinkedList() {
  //clear();
}

bool LinkedList::insert(std::string key, int value) {
  if (head) {
    Node * f = find(key);
    if (f == nullptr) { //Not in list
      Node * n = new Node(key, value);
      Node * l = tail;
      l->next = n;
      n->prev = l;
      tail = n;
      list_size++;
      return true;
    } else { //In list
      f->value = value;
      return false;
    }
  } else { //emtpy
    head = new Node(key, value);
    tail = head;
    list_size++;
    return true;
  }
}

/*
remove

The node with the given value should be removed from the list.

The list may or may not include a node with the given value.
*/
bool LinkedList::remove(std::string key) {
  Node * doomed = find(key);
  if (doomed == nullptr) { //Not found
    return false;
  }
  if (doomed == head) { //Remove head
    Node * next = doomed->next;
    if (next == nullptr) { //Only one node
      delete doomed;
      head = nullptr;
      tail = head;
      list_size--;
      return true;
    } else {
      next->prev = nullptr;
      head = next;
      delete doomed;
      list_size--;
      return true;
    }
  } else if (doomed == tail) { //Minimum 2 nodes, remove tail
    Node * next = doomed->prev;
    next->next = nullptr;
    tail = next;
    delete doomed;
    list_size--;
    return true;
  } else {
    Node * last = doomed->prev;
    Node * next = doomed->next;
    last->next = next;
    next->prev = last;
    delete doomed;
    list_size--;
    return true;
  }
  
}

/*
clear

Remove all nodes from the list.
*/
void LinkedList::clear() {
  if (head) {
    remove(head->key);
    clear();
  }
}

/*
at

Returns reference to the value of the node at the given index. The list begins at
index 0.
*/
int& LinkedList::at(std::string key) {
  Node * it = head;
  while(it) {
    if (it->key == key) {
      return it->value;
    }
    it = it->next;
  }
  insert(key, 0);
  return tail->value;
}

int LinkedList::get(std::string key) {
  Node *it = find(key);
  if (it) {
    return it->value;
  }
  throw std::invalid_argument(key);
}

/*
size
Returns the number of nodes in the list.
*/
int LinkedList::size() {
  return list_size;
}

Node * LinkedList::find(std::string key) {
  Node * it = head;
  while (it) {
    if (it->key == key) {
      return it;
    }
    it = it->next;
  }
  return nullptr;
}

std::string LinkedList::toString() {
  std::stringstream ss;
  std::string out = "";
  Node * it = head;
  while (it != nullptr) {
      ss << " " << it->key << " => " << it->value << ",";
      it = it->next;
  }
  out = ss.str();
  return out;
}

std::vector<Node*> LinkedList::getAllNodes() {
  Node * it = head;
  std::vector<Node*> nodes;
  while(it) {
    nodes.push_back(it);
    it = it->next;
  }
  return nodes;
}