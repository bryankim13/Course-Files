// Bryan Kim
// bjk3yf
// 11/24/19
// heap.h

#ifndef HEAP_H
#define HEAP_H
#include "huffNode.h"
#include <vector>

using namespace std;

class heap{
public:
	heap();
	~heap();
	void insert(huffNode* x);
	vector<huffNode*> getV();
	huffNode* findMin();
	huffNode* deleteMin();
	unsigned int size();
	void makeEmpty();
	bool isEmpty();
	void print();

private:
	vector <huffNode*> data;
	unsigned int hsize;
	void percolateUp(int x);
	void percolateDown(int x);
};
#endif