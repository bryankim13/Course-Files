// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations
// Bryan Kim
// bjk3yf
// 10/14/19
// TreeCalc.cpp

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  stack <TreeNode*> mystack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  while(!mystack.empty()){
    TreeNode* temp = mystack.top();
    cleanTree(temp);
    mystack.pop();
  }
  delete root;
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  // if(ptr->left==NULL && ptr->right == NULL)
  //delete ptr;
  if(ptr->left !=NULL && ptr->right==NULL){
    cleanTree(ptr->left);
    //  delete ptr;
  }
  else if(ptr->left==NULL && ptr->right!=NULL){
    cleanTree(ptr->right);
    //   delete ptr;
  }
  else if(ptr->left != NULL && ptr->right != NULL){
    cleanTree(ptr->right);
    cleanTree(ptr->left);
  }
    delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  root = new TreeNode(val);
  if(val == "+" || val == "-" || val == "*" || val == "/"){
    TreeNode * temp1 = mystack.top();
    root->right = temp1;
    mystack.pop();
    TreeNode*temp2 = mystack.top();
    root->left = temp2;
    mystack.pop();
    mystack.push(root);
  }
  else
    mystack.push(root);
}


//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
  cout<< ptr->value<<" ";
  if(ptr->left!=NULL){
    printPrefix(ptr->left);
  }
  if(ptr->right!=NULL){
    printPrefix(ptr->right);
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    if(ptr->value == "+" || ptr->value == "-" || ptr->value == "*" || ptr->value == "/"){
      cout<< "(";
	printInfix(ptr->left);
	cout<<" "<<ptr->value<< " ";
	printInfix(ptr->right);
	cout<< ")";
  }
    else
      cout<<ptr->value;
    
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
  if(ptr->left!=NULL && ptr->right != NULL){
    printPostfix(ptr->left);
    printPostfix(ptr->right);
  }
  else if(ptr->left!= NULL && ptr->right==NULL){
    printPostfix(ptr->left);
  }
  else if(ptr->left== NULL && ptr->right!=NULL){
    printPostfix(ptr->right);
  }
  cout<<ptr->value<< " ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
	printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
	printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
	printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
  if(ptr->left== NULL && ptr->right==NULL){
    return atoi(ptr->value.c_str());
  }
  else if(ptr->value == "+")
    return calculate(ptr->left)+calculate(ptr->right);
  else if(ptr->value == "-")
    return calculate(ptr->left)-calculate(ptr->right);
  else if(ptr->value == "*")
    return calculate(ptr->left)*calculate(ptr->right);
   else if(ptr->value == "/")
    return calculate(ptr->left)/calculate(ptr->right);
  
    return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i=calculate(mystack.top());
    cleanTree(mystack.top());
    mystack.pop();
    return i;
}
