all: main

main: main.o sum.o product.o
	g++ sum.o product.o main.o -o main

sum.o: sum.cpp
	g++ -c sum.cpp

product.o: product.cpp
	g++ -c product.cpp

main.o: main.cpp
	g++ -c main.cpp $(FLAG)

clean:
	rm *.o main