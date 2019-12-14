// Bryan Kim
// bjk3yf
// 11/24/19
// huffNode.cpp

#include "huffNode.h"
using namespace std;

huffNode::huffNode(){
	value = NULL;
	left = NULL;
	right = NULL;
	encoding = "";
	rep = 0;
}
huffNode::huffNode(char v, int r){
	value = v;
	left = NULL;
	right = NULL;
	rep = r;
}
void huffNode::huffPrint(huffNode *x,string y){
	if(x->left==NULL && x->right==NULL){
		if(x->value == ' ')
			cout<<"space "<<y<<endl;
		else
			cout<<x->value<<" "<<y<<endl;
		x->encoding = y;
	}
	if(x->left!=NULL){
		huffPrint(x->left,y+"0");
	}
	if(x->right!=NULL){
		huffPrint(x->right,y+"1");
	}
}
bool huffNode::operator<(const huffNode &x)const{
	return (this->rep<x.rep);
}

void huffNode::findEnc(huffNode* y, char x){
	if(y->value==x){
		cout<<y->encoding<<" ";
	}
	if(y->left!=NULL){
	    findEnc(y->left, x);
	}
	if(y->right!=NULL){
	    findEnc(y->right, x);
	}

}