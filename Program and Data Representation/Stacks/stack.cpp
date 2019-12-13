// Bryan Kim
// bjk3yf
// 09.14.19
// stack.cpp

#include <iostream>
#include "stack.h"

using namespace std;

stack::stack(){
  head = new stackNode;
  tail = new stackNode;
  tail->previous = head;
  count = 0;
}

stack::~stack(){
  while(!(count ==0)){
    pop();
  }
  delete head;
  delete tail;
}

void stack::push(int e){
  stackNode * a = tail->previous;
  tail->previous = new stackNode;
  tail->previous->value = e;
  tail->previous->previous = a;
  count++;
}

int stack::top(){
  return tail->previous->value;
}

void stack::pop(){
  if(!empty()){
  stackNode* a = tail->previous;
  tail->previous = tail->previous->previous;
  delete a;
  count--;
  }
}

bool stack::empty(){
  if(count==0)
    return true;
  else
    return false;
}
