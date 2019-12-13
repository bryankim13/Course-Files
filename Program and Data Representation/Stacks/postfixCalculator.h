// Bryan Kim
// bjk3yf
// 09/14/19
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();

  ~postfixCalculator();
  void push(int e);
  int top();
  void pop();
  bool empty();
  void numAdd();
  void numSub();
  void numMult();
  void numDiv();
  void negat();
 private:
  stack *s;
};
#endif
