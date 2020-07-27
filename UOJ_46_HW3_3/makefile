all: main

main: main.o engine.o wheel.o vehicle.o motor.o car.o
	g++ main.o engine.o wheel.o vehicle.o motor.o car.o -o main

engine.o: engine.cpp engine.h
	g++ -c engine.cpp

wheel.o: wheel.cpp wheel.h
	g++ -c wheel.cpp

vehicle.o: vehicle.cpp vehicle.h engine.cpp engine.h wheel.cpp wheel.h
	g++ -c vehicle.cpp

car.o: car.cpp car.h vehicle.cpp vehicle.h engine.cpp engine.h wheel.cpp wheel.h
	g++ -c car.cpp

motor.o: motor.cpp motor.h vehicle.cpp vehicle.h engine.cpp engine.h wheel.cpp wheel.h
	g++ -c motor.cpp

clean:
	rm *.o main