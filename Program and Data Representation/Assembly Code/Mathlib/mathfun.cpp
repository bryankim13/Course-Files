// Bryan Kim
// bjk3yf
// 11.5.19
// mathfun.cpp

#include <iostream>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);

int main(){
	int n1, n2, prod, pow;
	cout<< "Please enter number 1: "<<endl;
	cin>> n1;
	cout<< "Please enter number 2: "<<endl;
	cin>> n2;
	prod = product(n1,n2);
	cout<<n1<<" times " << n2<< " is "<< prod<<endl;
	pow = power(n1,n2);
	cout<<n1<<" to the power of "<<n2<<" is "<<pow<<endl;
	return 0;
}