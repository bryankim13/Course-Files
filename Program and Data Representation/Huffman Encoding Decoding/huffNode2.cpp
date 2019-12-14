// Bryan Kim
// bjk3yf
// 11/25/19
// huffNode.cpp

#include "huffNode2.h"
#include <string>
using namespace std;

huffNode2::huffNode2(){
	value = "";
	right = NULL;
	left = NULL;
}

huffNode2::huffNode2(string v){
	value = v;
	left = NULL;
	right = NULL;
}