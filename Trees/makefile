CC=g++
.PHONY: all clean

all: test
		./test
		make clean

test: tree.o test.cpp
		$(CC) tree.o test.cpp -o test

tree.o: tree.cpp tree.hpp
		$(CC) tree.cpp -c

clean:
		rm tree.o test
