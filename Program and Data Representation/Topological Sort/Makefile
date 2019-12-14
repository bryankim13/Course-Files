# Bryan Kim
# bjk3yf
# 12/2/19
# Makefile

CXX = clang++ 
CXXFLAGS = -Wall -O2 
OFILES = topological.o 


topological: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
		doxygen -g

topological.o : topological.cpp
	$(CXX) -c topological.cpp

clean: 
	-rm *.o

