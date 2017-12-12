CXX=g++
CXXFLAGS=-O0 -Wall -W -pedantic -ggdb3 -c

test: test.o list.o
	$(CXX) -o test test.o list.o

test.o: test.cpp list.h
	$(CXX) $(CXXFLAGS) test.cpp

linked_list.o: list.cpp list.h
	$(CXX) $(CXXFLAGS) list.cpp

clean:
	rm -fr *\.o test
