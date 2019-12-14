# Bryan Kim
# bjk3yf
# 11.26.19
# Makefile

CXX = clang++
CXXFLAGS = -Walls -O2
OFILESDEC = huffNode2.o huffmandec.o
OFILESENC = huffmanenc.o heap.o huffNode.o

all: huffmandec huffmanenc

huffmandec: $(OFILESDEC)
	$(CXX) $(CXXFLAGS) $(OFILESDEC) -o decoder

huffmanenc: $(OFILESENC)
	$(CXX) $(CXXFLAGS) $(OFILESENC)	-o encoder

huffmandec.o : huffmandec.cpp huffNode2.h
	$(CXX) -c huffmandec.cpp
huffNode2.o : huffNode2.cpp huffNode2.h
	$(CXX) -c huffNode2.cpp

heap.o: heap.cpp heap.h huffNode.h
	$(CXX) -c heap.cpp
huffmanenc.o: huffmanenc.cpp heap.h huffNode.h
	$(CXX) -c huffmanenc.cpp
huffNode.o: huffNode.cpp huffNode.h
	$(CXX) -c huffNode.cpp


clean: 
	-rm *.o