#include <iostream>
#include <vector>
#include "Hashmap.h"
#define BUCKETS 26

Hashmap::Hashmap() {
  buckets.reserve(BUCKETS);
  for (int i = 0; i < BUCKETS; i++) {
    LinkedList* n = new LinkedList();
    buckets.push_back(n);
  }
  mapSize = 0;
}
Hashmap::~Hashmap() {
  clear();
  for (int i = 0; i < BUCKETS; i++) {
    delete buckets[i];
  }
  buckets.clear();
}

void Hashmap::insert(string key, int value) {
  int h = hash(key);
  LinkedList* list = buckets[h];
  bool isa = list->insert(key, value);
  if (isa) mapSize++;
}
/*
void Hashmap::balance() {
  int ll_size = 0;
  for (LinkedList * l : buckets) {
    int s = l->size();
    if (s > ll_size)
      ll_size = s;
  }
  std::cout << ll_size << std::endl;
  if (ll_size >= (buckets.size() - 1)) {
    int olds = buckets.size();
    buckets.reserve(olds);
    for (int i = 0; i < olds; i++) {
      LinkedList* n = new LinkedList();
      buckets.push_back(n);
    }
  }
}*/

bool Hashmap::contains(string key) const {
  int h = hash(key);
  LinkedList* list = buckets[h];
  if (list->find(key))
    return true;
  return false;
}

int Hashmap::get(string key) const {
  int h = hash(key);
  LinkedList* list = buckets[h];
  return list->get(key);
}

int& Hashmap::operator[](string key) {
  int h = hash(key);
  LinkedList* list = buckets[h];
  if (list->find(key) == nullptr) mapSize++;
  return list->at(key);
}

//TODO finsih   
bool Hashmap::remove(string key) {
  int h = hash(key);
  LinkedList* list = buckets[h];
  if (contains(key)) {
    bool isr = list->remove(key);
    if (isr) mapSize--;
    return isr;
  }
  return false;
}

void Hashmap::clear() {
  for (LinkedList* list : buckets) {
    list->clear();
  }
  mapSize = 0;
}

string Hashmap::toString() const {
  stringstream ss;
  for (int i = 0; i < buckets.size(); i++) {
    ss << "[" << i << "]";
    LinkedList* list = buckets[i];
    ss << list->toString() << endl;
  }
  string out = ss.str();
  out.pop_back();
  return out;
}

int Hashmap::size() const {
  return mapSize;
}
  
unsigned int Hashmap::hash(string key) const {
  int s = key.length();
  int sum = 0;
  for (char c : key)
    sum += (int)c;
  int avg = sum % buckets.size();
  return avg;
}
  
string Hashmap::toSortedString() const
{
  stringstream ss;
  priority_queue<Node> nodeHeap;
  for(int i = 0; i < buckets.size(); i++)
  {
    LinkedList* list = buckets[i];
    std::vector<Node*> nodes = list->getAllNodes();
    for (Node * node : nodes) {
      nodeHeap.push(*node);
    }
  }
  while(!nodeHeap.empty())
  {
    Node top = nodeHeap.top(); // Get top node (next node in sorted order)
    ss << top.key << " => " << top.value << endl; // Add node data to stringstream
    nodeHeap.pop(); // Pop it off
  }
  return ss.str();
}