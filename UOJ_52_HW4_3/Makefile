main: main.o graph.o node.o operation.o mymap.o plus.o minus.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o mymap.o plus.o minus.o
main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h plus.cpp plus.h minus.cpp minus.h
	g++ -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h plus.cpp plus.h minus.cpp minus.h
	g++ -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h plus.cpp plus.h minus.cpp minus.h
	g++ -c -std=c++11 -o operation.o operation.cpp 
mymap.o: mymap.cpp mymap.h plus.cpp plus.h minus.cpp minus.h
	g++ -c -std=c++11 -o mymap.o mymap.cpp 
plus.o: plus.cpp plus.h
	g++ -c -std=c++11 -o plus.o plus.cpp
minus.o: minus.cpp minus.h
	g++ -c -std=c++11 -o minus.o minus.cpp
clean:
	rm main *.o
