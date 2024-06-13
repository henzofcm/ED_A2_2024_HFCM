CC=g++
.PHONY: all clean

all: test
		test.exe
		clean

test: tree.o test.cpp
		$(CC) tree.o test.cpp -o test

tree.o: tree.cpp tree.hpp
		$(CC) tree.cpp -c

clean:
		del tree.o test.exe
