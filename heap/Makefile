CXX=g++
CXXFLAGS=-O0 -Wall -W -pedantic -ggdb3 -c

test: test.o heap.o
	$(CXX) -o test test.o heap.o

test.o: test.cpp heap.h
	$(CXX) $(CXXFLAGS) test.cpp

linked_list.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) heap.cpp

clean:
	rm -fr *\.o test
