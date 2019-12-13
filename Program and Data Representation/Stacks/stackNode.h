// Bryan Kim
// bjk3yf
// 09.14.19
// stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

class stackNode {
 public:
  stackNode();
 private:
  int value;
  stackNode* previous;
  friend class stack;
};



#endif
