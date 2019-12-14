// Bryan Kim
// bjk3yf
// 11/24/19
//huffmanenc.cpp
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char ** argv){
	if(argc!=2){
		cout<<"Must supply the input file name as the one and only parameter"<<endl;
		exit(1);
	}

	FILE *f = fopen(argv[1],"r");

	if(f==NULL){
		cout<<"File "<<argv[1] << " does not exist!"<<endl;
		exit(2);
	}
	char g;
	vector <int> a(128,0);
	int count = 0;
	while((g=fgetc(f)) !=EOF){
		int n = (int) g;
		if(a[n]==0){
			count++;
		}
		a[n]++;
	}
	
	heap huff;
	heap huff2;
	for(int i = 0; i < a.size(); i++){
		if(a[i]!=0 && i>31 && i<128){
			huffNode * temp = new huffNode((char) i, a[i]);
			huff.insert(temp);
			huff2.insert(temp);
		}
	}
	huffNode *t1, *t2, *t3;
	for(int i = 1; i < count-1; i++){
		t1 = huff.deleteMin();
		t2 = huff.deleteMin();
		t3 = new huffNode(NULL, t1->rep+t2->rep);
		t3->left = t1;
		t3->right = t2;
		huff.insert(t3);
	}
	t3->huffPrint(t3,"");

cout<<"----------------------------------------"<<endl;
 	rewind(f);
 	int bits=0;
 	vector<huffNode*> t = huff2.getV();
	while((g=fgetc(f)) !=EOF){
		t3->findEnc(t3,g);
		for(int i = 1; i < huff2.size()+1;i++){
			if(t[i]->value == g)
				bits+=t[i]->encoding.size();
		}
	}
	cout<<endl;

	fclose(f);

cout<<"----------------------------------------"<<endl;
cout<<"There are a total of "<<t3->rep<<" symbols that are encoded"<<endl;
cout<<"There are "<<count-1<<" distinct symbols used"<<endl;
cout<<"There were "<<t3->rep*8<<" bits in the original file"<<endl;
cout<<"There were "<<bits<<" bits in the compressed file"<<endl;
cout<<"This gives a compression ratio of "<<(double)(t3->rep*8)/(double)bits<<endl;
cout<<"The cost of the Huffman tree is "<<(double)bits/(t3->rep)<<endl;
return 0;
}