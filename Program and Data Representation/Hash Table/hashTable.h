// Bryan Kim
// bjk3yf
// 10/20/19
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

class hashTable {
public:
	hashTable(); // constructor
	hashTable(int num);
	void insert(string x); // checks if size is 
	bool find(string x); // checks if string exists
	unsigned int hash(string x); // returns an unsigned int to check
	bool checkprime(unsigned int p);
	int getNextPrime (unsigned int n);

private:
	int size; // tracks the size of the table
	vector < list<string> > * dict; // holds all the values

};
#endif