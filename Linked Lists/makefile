CC=g++
.PHONY: all test clean

all: test clean

test: bubblesort selectsort insertionsort
		./bubblesort > bubbleTime.csv
		./selectsort > selectTime.csv
		./insertionsort > insertionTime.csv

bubblesort: bubblesort.cpp
		$(CC) bubblesort.cpp -o bubblesort

selectsort: selectsort.cpp
		$(CC) selectsort.cpp -o selectsort

insertionsort: insertionsort.cpp
		$(CC) insertionsort.cpp -o insertionsort

clean:
		rm bubblesort selectsort insertionsort
