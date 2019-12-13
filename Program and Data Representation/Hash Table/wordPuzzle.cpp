// Bryan Kim
// bjk3yf
// 10/20/19
// wordPuzzle.cpp

// Complexity of Thetha(n) since the program runs through every object in the grid.
#include <sstream>
#include <iostream>
#include "timer.h"
#include "hashTable.h"
#include <fstream>
#include <string>
using namespace std;
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols);
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);

char grid[500][500];

int main(int argc, char **argv){
	string fname = argv[2];
	string dictname = argv[1];

	int row;
	int col;
    int words = 0;

	bool tf = readInGrid(fname, row, col);
    if(!tf){
        cout<<"exit reading"<<endl;
        exit(1);
    }

	int count = 0;
	ifstream file(dictname.c_str());

	string n;
	while(file>>n){
		count++;
	}
    file.close();
   
	hashTable *ht = new hashTable(count);

    fstream file2(dictname.c_str());

    while(file2>>n){
		ht->insert(n);
	}
	file2.close();
vector<string> pholder;
	timer time;
	time.start();

string temp;
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			for(int k = 0; k<8; k++){
				for(int q = 3; q <23; q++){
					temp = getWordInGrid(i,j,k,q,row,col);
					if(ht->find(temp)){
						if(temp.length()==q){

                            ostringstream ro;
                            ro << i;
                            string rows = ro.str();

                            ostringstream co;
                            co << j;
                            string cols = co.str();

							if(k == 0){
                                string x = "N ("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "N ("<<i<<", "<<j<<"):"<<temp<<endl;
							}
						
							else if(k == 1){
                                string x = "NE("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "NE("<<i<<", "<<j<<"):"<<temp<<endl;
							}

							else if(k == 2){
                                string x = "E ("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "E ("<<i<<", "<<j<<"):"<<temp<<endl;
							}

							else if(k == 3){
                                string x = "SE("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "SE("<<i<<", "<<j<<"):"<<temp<<endl;
							}

							else if(k == 4){
                                string x = "S ("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "S ("<<i<<", "<<j<<"):"<<temp<<endl;
							}

							else if(k == 5){
                                string x = "SW("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "SW("<<i<<", "<<j<<"):"<<temp<<endl;
							}

							else if(k == 6){
                                string x = "W ("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "W ("<<i<<", "<<j<<"):"<<temp<<endl;
							}

							else if(k == 7){
                                string x = "NW("+rows+", "+cols+"):"+temp;
                                pholder.push_back(x);
								//cout<< "NW("<<i<<", "<<j<<"):"<<temp<<endl;
							}
                            words++;
						}
					}
				}
			}       
		}
    }
    for(int e = 0; e<pholder.size();e++){
        cout<<pholder.at(e)<<endl;
    }
	time.stop();
    cout<<words<< " words found"<< endl;
	cout<<"Found all words in "<<time.getTime()<<" seconds"<< endl;
    int a = (int) time.getTime() * 1000;
    cout<<a<<endl;
	return 0;
}

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
        }
    }
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}