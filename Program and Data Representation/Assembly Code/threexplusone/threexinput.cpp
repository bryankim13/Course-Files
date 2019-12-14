// Bryan Kim
// bjk3yf
// 11/9/19
// threexinput.cpp

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int);

int main(){
	cout<<"Insert a number: "<<endl;
	int x,n;
	double avg = 0;
	cin>>x;
	cout<<"How many times do you want to iterate?"<<endl;
	cin>>n;
	timer t;
	t.start();
	for(int i = 0; i < n; i++){
		threexplusone(x);
	}
	t.stop();
	avg=(t.getTime()*1000)/n;
	cout<<"It takes "<<threexplusone(x)<<" steps"<<endl;
	cout<<"On the average of "<<n<<" times, it takes "<<avg<< " milliseconds"<<endl;
	return 0;
}