// Bryan Kim
// bjk3yf
// 11/24/19
// heap.cpp

#include <iostream>
#include "heap.h"
using namespace std;
//implemented my code based on the code shown in lab
heap::heap(){
	hsize = 0;
	data.push_back(NULL);
}

heap::~heap(){
}
void heap::insert(huffNode* x){
	data.push_back(x);
	percolateUp(++hsize);
}

void heap::percolateUp(int hole) {
	huffNode* temp = data[hole];
	for( ; (hole > 1) && (temp->rep <= data[hole/2]->rep); hole /= 2)
		data[hole] = data[hole/2];

	data[hole] = temp;
}

// void heap::percolateUp(int hole) {
// 	huffNode* temp = data[hole];
// 	for( ; (hole > 1) && (temp->rep < data[hole/2]->rep); hole /= 2)
// 		data[hole] = data[hole/2];

// 	data[hole] = temp;
// }

void heap::percolateDown(int hole){
	huffNode* temp = data[hole];
	while(hole*2<=hsize){
		int child = hole*2;
		if((child+1<=hsize) && (*data[child+1] < *data[child]))
			child++;
		if(*data[child]<*temp){
			data[hole]=data[child];
			hole = child;
		}
		else{
			break;
		}
	}
	data[hole]=temp;
}

huffNode* heap::deleteMin(){
	if(hsize==0){
		throw "deleteMin() called empty heap";
	}
	huffNode* ret = data[1];
	data[1] = data[hsize--];
	data.pop_back();
	percolateDown(1);
	return ret;
}

huffNode* heap::findMin(){
	if(hsize == 0)
		throw "findMin() called on empty heap";
	return data[1];
}

unsigned int heap::size(){
	return hsize;
}

void heap::makeEmpty(){
	hsize = 0;
	data.resize(1);
}

bool heap::isEmpty(){
	return hsize==0;
}

void heap::print(){
	//cout<<"("<<data[0]->value<<") ";
	cout<<"(x)";
	for ( int i = 1; i <= hsize; i++ ) {
        cout << data[i]->value << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        //if ( isPow2 )
         //   cout << endl << "\t";
    }
    cout << endl;
}
vector<huffNode*> heap:: getV(){
	return data;
}