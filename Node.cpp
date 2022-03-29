#include "Node.h"

bool operator>(const Node& a, const Node& b)
{
  if(a.value != b.value)
    return a.value > b.value;
  else
    return a.key > b.key;
}

bool operator<(const Node& a, const Node& b)
{
  if(a.value != b.value)
    return a.value < b.value;
  else
    return a.key < b.key;
}

bool operator==(const Node& a, const Node& b)
{
  return a.value == b.value && a.key == b.key;
}