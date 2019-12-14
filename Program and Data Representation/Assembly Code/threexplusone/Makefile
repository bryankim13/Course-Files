#Bryan Kim
#bjk3yf
#11/9/19
#Makefile

CXX = clang++ -m64
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OFILES = threexplusone.o threexinput.o timer.o

.SUFFIXES: .o .cpp
.SUFFIXES: .o .s

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

threexinput.o: threexinput.cpp timer.h
	$(CXX) -c threexinput.cpp
timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
clean: 
	/bin/rm -f *.o *.~