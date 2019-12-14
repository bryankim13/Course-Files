# Bryan Kim
# bjk3yf
# 11-5-19
# Makefile
CXX = clang++ -m64
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OFILES = mergeSort.o testMergeSort.o

.SUFFIXES: .o .cpp
.SUFFIXES: .o .s

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean: 
	/bin/rm -f *.o *.~