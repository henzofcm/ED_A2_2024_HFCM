CC=g++
.PHONY: all test clean

all: test clean

test: bubblesort selectsort insertionsort
		bubblesort > bubbleTime.txt
		selectsort > selectTime.txt
		insertionsort > insertionTime.txt

bubblesort: bubblesort.cpp
		$(CC) bubblesort.cpp -o bubblesort

selectsort: selectsort.cpp
		$(CC) selectsort.cpp -o selectsort

insertionsort: insertionsort.cpp
		$(CC) insertionsort.cpp -o insertionsort

clean:
		del bubblesort.exe selectsort.exe insertionsort.exe
