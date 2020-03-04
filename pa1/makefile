all:	main
p1:	p1.o
	g++ -Wall -Wextra -pedantic -g bottom-up.o -o program1

p1.o:	bottom-up.cpp
	g++ -Wall -Wextra -pedantic -g -c bottom-up.cpp

p2:	p2.o
	g++ -Wall -Wextra -pedantic -g recursive.o -o program2

p2.o:	recursive.cpp
	g++ -Wall -Wextra -pedantic -g -c recursive.cpp

p3:	p3.o
	g++ -Wall -Wextra -pedantic -g top-down.o -o program3

p3.o:	top-down.cpp
	g++ -Wall -Wextra -pedantic -g -c top-down.cpp

clean:
	rm -f *.o program1 program2 program3
