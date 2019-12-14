# Bryan Kim
# bjk3yf
# 11/24/19
# Makefile

CXX = clang++ 
CXXFLAGS = -Wall -O2
OFILES = huffmanenc.o heap.o huffNode.o

huffmanenc: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

heap.o: heap.cpp heap.h huffNode.h
	$(CXX) -c heap.cpp
huffmanenc.o: huffmanenc.cpp heap.h huffNode.h
	$(CXX) -c huffmanenc.cpp
huffNode.o: huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp

clean: 
	-rm *.o