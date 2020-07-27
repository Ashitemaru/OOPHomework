all: main
main: functions.h main.o sum.o product.o
	g++ main.o sum.o product.o -o main
sum.o: functions.h sum.cpp
	g++ -c sum.cpp
product.o: functions.h product.o
	g++ -c product.cpp
main.o: functions.h main.cpp
	g++ -c main.cpp
clean:
	rm *.o main