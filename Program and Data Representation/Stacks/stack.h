// Bryan Kim
// bjk3yf
// 09.14.19
// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"
using namespace std;

class stack{
 public :
  stack();
  ~stack();
  void push(int e);
  int top();
  void pop();
  bool empty();
 private :
  stackNode* head, * tail;
  int count;
};
#endif
