#Bryan Kim
#bjk3yf
#10/14/19
#Makefile
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -O2 -g
OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o
BSTPathTest: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) 

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BinarySearchTree.cpp

BinaryNode.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BinaryNode.cpp

clean:
	-rm *.o 
