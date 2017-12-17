CC=gcc
CFLAGS=-O0 -Wall -W -pedantic -ansi -std=c99 -ggdb3 -c

test: test.o bst.o
	$(CC) -o test test.o bst.o

test.o: test.c bst.h
	$(CC) $(CFLAGS) test.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) bst.c

clean:
	rm -fr *\.o test
