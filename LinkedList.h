#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Node.h"

class LinkedList {
public:
  LinkedList();
  virtual ~LinkedList();
  
  /*
   * Insert node with key and value into list
   * If already in list, update value
   * return true if added
   */
  bool insert(std::string key, int value);
  
  /*
  remove
  The node with the given key should be removed from the list.
  The list may or may not include a node with the given value.
  Returns true if removed
  */
  bool remove(std::string key);
  
  /*
  clear
  
  Remove all nodes from the list.
  */
  void clear();
  
  /*
  at
  
  Returns the value of the node at the given index. The list begins at
  index 0.
  
  If the given index is out of range of the list, throw an out of range exception.
  */
  int& at(std::string key);
  int get(std::string key);
  
  /*
  size
  Returns the number of nodes in the list.
  */
  int size();
  
  Node * getHead() { return head; }
  Node * getTail() { return tail; }
  
  /*
   * Return address of node in list, null if not found
   */
  Node * find(std::string key);
  
  /*
   * Return string representation of list
   * key => value, key=>value
   */
  std::string toString();

  std::vector<Node*> getAllNodes();

private:
  Node * head;
  Node * tail;
  int list_size;
};
#endif /* LINKEDLIST_H */
