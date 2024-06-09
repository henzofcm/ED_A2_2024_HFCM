CC=g++
.PHONY: all clean

all: main clean
		main

main: tree.o main.cpp
		$(CC) tree.o main.cpp -o main

tree.o: tree.cpp tree.hpp
		$(CC) tree.cpp -c

clean:
		del tree.o main.exe
