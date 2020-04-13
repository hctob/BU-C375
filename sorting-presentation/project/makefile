all:	main
main:	sorts.o
	g++ -Wall -Wextra -pedantic -g main.o -o sort-driver

sorts.o:	main.cpp quicksort.cpp
	g++ -Wall -Wextra -pedantic -g -c main.cpp

qs:	qs.o
	g++ -Wall -Wextra -pedantic -g quicksort.o -o quicksort-driver

qs.o:	quicksort.cpp
	g++ -Wall -Wextra -pedantic -g -c quicksort.cpp

clean:
	rm -f *.o sort-driver
