all: clean

test: bubblesort selectsort insertionsort
		bubblesort > bubbleTime.txt
		selectsort > selectTime.txt
		insertionsort > insertionTime.txt

bubblesort: bubblesort.cpp
		g++ bubblesort.cpp -o bubblesort

selectsort: selectsort.cpp
		g++ selectsort.cpp -o selectsort

insertionsort: insertionsort.cpp
		g++ insertionsort.cpp -o insertionsort

clean:
		del bubblesort.exe selectsort.exe insertionsort.exe
