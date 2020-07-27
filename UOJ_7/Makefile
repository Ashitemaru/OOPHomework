all: main

main: main.o Person.o Student.o Teacher.o Course.o
	g++ main.o Person.o Student.o Teacher.o Course.o -o main -O2 -std=c++11

Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o -O2 -std=c++11

Student.o: Student.cpp Student.h Person.h
	g++ -c Student.cpp -o Student.o -O2 -std=c++11

Teacher.o: Teacher.cpp Teacher.h Person.h
	g++ -c Teacher.cpp -o Teacher.o -O2 -std=c++11

Course.o: Course.cpp Course.h Student.h Teacher.h Person.h
	g++ -c Course.cpp -o Course.o -O2 -std=c++11

main.o: main.cpp Person.h Student.h Teacher.h Course.h
	g++ -c main.cpp -o main.o -O2 -std=c++11

clean:
	rm *.o main