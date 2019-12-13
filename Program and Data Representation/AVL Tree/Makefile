#Bryan Kim
#bjk3yf
#10.14.19
#Makefile
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -O2
OFILES = AVLNode.o AVLTree.o AVLPathTest.o

AVLPathTest: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLTree.cpp
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLPathTest.cpp

clean:
	-rm *.o
