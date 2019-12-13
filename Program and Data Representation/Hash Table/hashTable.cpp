// Bryan Kim
// bjk3yf
// 10/20/19
// hashTable.cpp

#include <iostream>
#include "hashTable.h"

hashTable::hashTable(){
	size = 191;
	dict = new vector< list<string> > (size);
}

hashTable::hashTable(int num){
	size = getNextPrime(2*num);
	dict = new vector< list<string> >(size);
}

unsigned int hashTable::hash(string x){
	unsigned int tot = 7;//0;

	for(int i = 0; i < x.length();i++){
		//tot += x[i];
		tot = tot*31+x[i];
	}
	if(tot>=size)
		return tot%size;
	//return tot%size;
	return tot; 
}

void hashTable::insert(string x){
	int h = hash(x);
	dict->at(h).push_back(x);
}
 
bool hashTable::find(string x){
	int h = hash(x);
	for(string s : dict->at(h)){
		if(x == s)
			return true;
	}
	return false;
}


bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}