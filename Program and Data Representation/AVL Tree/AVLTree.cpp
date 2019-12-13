// Bryan Kim
// bjk3yf
// 10.14.19
// AVLTree.cpp
#include "AVLTree.h"
#include <string>
#include "AVLNode.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  inserting(x, root);
}

void AVLTree::inserting(const string& x, AVLNode*& n){
  if(n == NULL){
    n = new AVLNode;
    n->value = x;
  }
  else if(x > n->value)
   inserting(x,n->right);
  else if(x < n->value)
   inserting(x,n->left);

    n->height = 1+max(height(n->left),height(n->right));
  balance(n);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  if(!find(x))
    return " ";
  else
    return path2(x,root);
}

string AVLTree::path2(const string& x, AVLNode* n) const{
  if(x == n->value)
    return n->value;
 else if(x>n->value)
    return n->value+" "+path2(x,n->right)+" ";
 else if(x<n->value)
   return n->value+" "+path2(x,n->left)+ " ";
 else
   return " ";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return find2(x,root);
}

bool AVLTree::find2(const string& x, AVLNode* n) const{
  if(n==NULL)
    return false;
  else if(x.compare(n->value)>0)
    return find2(x,n->right);
  else if(x.compare(n->value)<0)
    return find2(x,n->left);
  else
    return true;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return counter(root);
}

int AVLTree::counter(AVLNode* n)const{
  if(n->right==NULL && n->left==NULL)
    return 1;
  else if(n->right!=NULL && n->left==NULL)
    return 1+counter(n->right);
  else if(n->right==NULL && n->left!=NULL)
    return 1+counter(n->left);
  else
    return 1+counter(n->left)+counter(n->right);
}


// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
    int balance = height(n->left)-height(n->right);
  if(balance > 1 && n->value < n->left->value)
    n = rotateRight(n);
   else if(balance < -1 && n->value < n->right->value)
    n = rotateLeft(n);
  else if(balance > 1 && n->value > n->left->value){
    n->left = rotateLeft(n->left);
    n = rotateRight(n);
  }
 
    else if(balance < -1 && n->value > n->right->value){
    n->right = rotateRight(n->right);
    n=rotateLeft(n);
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode* r = n->right;
  AVLNode* rl = r->left;
  n->right = rl;
  r->left = n;
  
  n->height = 1 + max(height(n->left),height(n->right));
  r->height = 1 + max(height(r->left),height(r->right));
    return r;
  
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode* l = n->left;
  AVLNode* lr = l->right;

  n->left = lr;
  l->right = n;
  
  n->height = 1 + max(height(n->left),height(n->right));
  l->height = 1 + max(height(l->left),height(l->right));
  return l;
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }
