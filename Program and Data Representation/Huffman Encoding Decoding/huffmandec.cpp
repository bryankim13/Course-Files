//Bryann Kim
//bjk3yf
//11/25/19
//huffmandec.cpp

// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffNode2.h"
using namespace std;


void inserting(huffNode2* x, string val, string enc){
    if(enc.length()==0)
        x->value = val;

    if(enc.substr(0,1)=="0"){
        if(x->left==NULL)
            x->left = new huffNode2();
        inserting(x->left, val, enc.substr(1,enc.length()-1));
    }
    if(enc.substr(0,1)=="1"){
        if(x->right==NULL)
            x->right = new huffNode2();
        inserting(x->right, val, enc.substr(1,enc.length()-1));
    }
}

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes

    huffNode2 * root = new huffNode2();

    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        cout << "character '" << character << "' has prefix code '"
             << prefix << "'" << endl;
    inserting(root, character, prefix);
    }
    // read in the second section of the file: the encoded message

    huffNode2* pHolder = root;
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
        for(int i = 0; i < bits.length(); i++){
        if(bits.substr(i,1)=="0"){
            pHolder = pHolder->left;
            if(pHolder->left==NULL && pHolder->right==NULL){
                cout<<pHolder->value;
                pHolder=root;
            }
        }
        else if(bits.substr(i,1)=="1"){
            pHolder = pHolder->right;
            if(pHolder->left==NULL && pHolder->right==NULL){
                cout<<pHolder->value;
                pHolder=root;
            }
        }
    }

    }
    cout<<endl;
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
}
