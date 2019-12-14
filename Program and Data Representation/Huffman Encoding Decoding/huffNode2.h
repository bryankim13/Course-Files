// Bryan Kim
// bjk3yf
// 11/25/19
// huffNode.h

#ifndef HUFFNODE2_H
#define HUFFNODE2_H

#include <iostream>
using namespace std;
class huffNode2{
public:
	huffNode2();
	huffNode2(string v);

	string value;
	string encode;
	huffNode2* left,*right;

};
#endif
