// Bryan Kim
// bjk3yf
// 12/1/19
// topological.cpp

/**
* @author Bryan Kim
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

class node{
public:
	node();
	node(int w, string x); 
	int weight; 
	string val;
	node* next;
	int topNum;
};

/**
*  @brief Basic constructor for the node
*/
node::node(){
	weight = 0; ///< The number of vertices that point to this node
	val = ""; ///< The value assigned to the node
	next = NULL; ///< The following nodes that this node points to
	topNum = -1;
}

/**
*  @brief Constructor with desired values
*  @parem w Disired weight of the node
*  @parem x String value for the node
*/
node::node(int w, string x){
	weight = w;
	val = x;
	next = NULL;
	topNum = -1;
}

class graph{
public:
	graph();
	vector<node*> g;
	vector<node*> queue;
	void insert(string x, string y);
	void print();
	void topSort();
	node* find(string x);
private:
	void addOn(node * x, node *y);
};

/**
*  @brief Constructor for the graph
*
*/
graph::graph(){
	vector <node*> g; ///< A vector holding all the nodes
	vector <node*> queue;
}

/**
*  @brief takes an input string and finds the node corresponding to that string
*  @return A node pointer than has the same value as the string
*  @parem A string that is used to find the desired node
*/
node* graph::find(string x){
	for(int i = 0; i < g.size(); i++){
		if(g[i]->val == x)
			return g[i];
	}
	return NULL;
}

/**
*  @brief Inserts the edge
*  @parem x The string of the pointee of the edge
*  @parem y The pointed string value 
*/
void graph::insert(string x, string y){
	node* xx = new node(0,x);
	node* yy = new node(1,y);

	bool inserting = true;
	bool inserting2 = true;
	for(int i = 0; i < g.size(); i++){
		if(g[i]->val == x){
			addOn(g[i],yy);
			inserting = false;
		}
		if(g[i]->val == y){
			inserting2 = false;
			g[i]->weight++;
		}
	}
	if(inserting){
		g.push_back(xx); //inserting new node if not there
		addOn(g.back(),yy);
	}
	if(inserting2)
		g.push_back(yy);
		
}

/**
*  @brief Adds the second paremeter to the end of the first paremeter node
*  @parem x The pointer of a node where the insert is occurring.
*  @parem y The pointer of a node that is being inserted into the first node
*/
void graph::addOn(node* x,node * y){
	if(x->next==NULL){
		x->next = y;
	}
	else
		addOn(x->next, y);
}
/**
*  @brief Prints out the graph in topological order
*/
void graph::topSort(){
	queue = g;
	std::queue <string> q;
	node* v, *w;
	int counter=0;
	for(int i = 0; i < queue.size(); i++){
		if(queue[i]->weight == 0){
			q.push(g[i]->val);
		}
	}
	while(!(q.empty()) && counter < queue.size()){
		v = find(q.back());
		q.pop();
		v->topNum = ++counter;
		cout<< v->val<<" ";
		w = v->next;
	while(w!=NULL){
		w->weight--;
		if(w->weight == 0){
			q.push(w->val);
		}
		w = w->next;
	}

	}
	cout<<endl;
}

/**
*  @brief Prints out the graph nodes along with their weights
*/
void graph::print(){
	for(int i = 0; i < g.size();i++){
		cout<<g[i]->val<<" " <<g[i]->weight<<endl;
	}
}





int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    graph gr;
    // read in two strings
    string s1, s2;
    bool looping = true;
    while(looping){
    file >> s1;
    file >> s2;
    // output those strings
    if(s1=="0" && s2=="0")
    	looping = false;
    else
    	gr.insert(s1,s2);

    }

    gr.topSort();
    // string comparison done with ==, but not shown here
    // close the file before exiting
    file.close();
}
