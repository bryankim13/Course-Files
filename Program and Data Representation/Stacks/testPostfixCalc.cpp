// Bryan Kim
// bjk3yf
// 09/14/19
// testPostfixCalc.cpp

#include <iostream>
#include "postfixCalculator.h"
using namespace std;
int main(){
  postfixCalculator* calc = new postfixCalculator;
  string s;
  while(cin>>s){
    if(s.front()=='-' && s.size()>1){
      calc->push(atoi(s.c_str()));
    }
    else  if(s == "+"){
      calc->numAdd();
    }
    else if(s == "-"){
      calc->numSub();
    }
    else if(s == "*"){
      calc->numMult();
    }
    else if(s == "/"){
      calc->numDiv();
    }
    else if(s == "~"){
      calc->negat();
    }
    else{
      calc->push(atoi(s.c_str()));
    }
  }
  cout << calc->top() << endl;
  delete calc;
  return 0;
}
