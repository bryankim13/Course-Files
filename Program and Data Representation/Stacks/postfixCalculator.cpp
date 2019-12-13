// Bryan Kim
// bjk3yf
// 09/14/19
// postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"

using namespace std;

postfixCalculator :: postfixCalculator(){
  s = new stack();
}

postfixCalculator :: ~postfixCalculator(){
  delete s;
}

void postfixCalculator::push(int e){
  s->push(e);
}

int postfixCalculator::top(){
  return s->top();
}

void postfixCalculator::pop(){
  s->pop();
}

bool postfixCalculator::empty(){
  return s->empty();
}

void postfixCalculator::numAdd(){
  if(!(s->empty())){
    int a = s->top();
    s->pop();
      if(!s->empty()){
        int b = s->top();
	s->pop();
	s->push(b+a);
      }
      else{
	s->push(a);
	exit(-1);
      }
    }
  else{
    exit(-1);
  }
}
void postfixCalculator::numSub(){
  if(!s->empty()){
  int a = s->top();
  s->pop();
    if(!s->empty()){
      int b = s->top();
      s->pop();
      s->push(b-a);
    }
    else{
      s->push(a);
      exit(-1);
    }
  }
  else{
    exit(-1);
  }
}
void postfixCalculator:: numMult(){
  if(!s->empty()){
  int a = s->top();
  s->pop();
    if(!s->empty()){
      int b = s->top();
      s->pop();
      s->push(b*a);
    }
    else{
      s->push(a);
      exit(-1);
    }
  }
  else{
    exit(-1);
  }
}
void postfixCalculator::numDiv(){
 if(!s->empty()){
  int a = s->top();
  s->pop();
    if(!s->empty()){
      int b = s->top();
      s->pop();
      s->push(b/a);
    }
    else{
      s->push(a);
      exit(-1);
    }
  }
  else{
    exit(-1);
  }  
}
void postfixCalculator::negat(){
  if(!s->empty()){
    int a = s->top();
    s->pop();
    s->push(-a);
  }
  else{
    exit(-1);
  }
}


