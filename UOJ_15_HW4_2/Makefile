all: main

main: main.o Shape.o
	g++ main.o Shape.o -o main -O2 -std=c++11

Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp -o Shape.o -O2 -std=c++11

main.o: main.cpp Shape.h
	g++ -c main.cpp -o main.o -O2 -std=c++11

clean:
	rm *.o main