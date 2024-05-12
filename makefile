all: clean

test: bubblesort selectsort
		./bubblesort
		./selectsort

bubblesort: linkedlists.o bubblesort.cpp
		g++ linkedlists.o bubblesort.cpp -o bubblesort

selectsort: linkedlists.o selectsort.cpp
		g++ linkedlists.o selectsort.cpp -o selectsort

linkedlists.o: linkedlists.cpp linkedlists.h
		g++ linkedlists.cpp -c

clean:
		rm -f linkedlists.o
