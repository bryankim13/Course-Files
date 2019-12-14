// Bryan Kim
// bjk3yf
// 11/24/19
// huffNode.h

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
#include <string>
using namespace std;

class huffNode{
public:
	huffNode();
	huffNode(char v, int r);
	bool operator<(const huffNode &x)const;
	void huffPrint(huffNode* x, string y);
	string encoding;
	char value;
	huffNode * left, * right;
	int rep;
	void findEnc(huffNode* y,char x);
};
#endif