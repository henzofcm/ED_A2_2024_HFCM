all: clean

test: bubblesort selectsort insertionsort
		bubblesort > bubbleTime.txt
		selectsort > selectTime.txt
		insertionsort > insertionTime.txt

bubblesort: linkedlists.o bubblesort.cpp
		g++ linkedlists.o bubblesort.cpp -o bubblesort

selectsort: linkedlists.o selectsort.cpp
		g++ linkedlists.o selectsort.cpp -o selectsort

insertionsort: linkedlists.o insertionsort.cpp
		g++ linkedlists.o insertionsort.cpp -o insertionsort

linkedlists.o: linkedlists.cpp linkedlists.h
		g++ linkedlists.cpp -c

clean:
		del bubblesort.exe selectsort.exe insertionsort.exe linkedlists.o
