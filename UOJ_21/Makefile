all: main

main: main.o Computer.o ComputerCollection.o
	g++ main.o Computer.o ComputerCollection.o -o main -O2 -std=c++11

main.o: main.cpp Computer.cpp ComputerCollection.cpp
	g++ -c main.cpp -o main.o -O2 -std=c++11

ComputerCollection.o: ComputerCollection.cpp Computer.cpp
	g++ -c ComputerCollection.cpp -o ComputerCollection.o -O2 -std=c++11

Computer.o: Computer.cpp
	g++ -c Computer.cpp -o Computer.o -O2 -std=c++11

clean: 
	rm -fR *.o main