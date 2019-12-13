# Bryan Kim
# bjk3yf
# 10/20/19
# Makefile

CXX = clang++ -O2 
CXXFLAGS = -std=c++11 -Wall 
OFILES = hashTable.o  timer.o wordPuzzle.o

wordPuzzle: ${OFILES}
	${CXX} $(CXXFLAGS) $(OFILES)

hashTable.o : hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

timer.o : timer.cpp timer.h
	$(CXX) -c timer.cpp

wordPuzzle.o : wordPuzzle.cpp timer.h hashTable.h
	$(CXX) -c wordPuzzle.cpp

clean:
	rm *.o