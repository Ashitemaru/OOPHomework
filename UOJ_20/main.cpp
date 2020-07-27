#include <iostream>
#include "MyAnswer.h"
using namespace std;

#define Option_A auto testA = f1(b);
#define Option_B auto testB = f2(b);
#define Option_C auto testC = f3(b);
#define Option_D auto testD = f3(b);
#define Option_E auto& testE = f4(f);
#define Option_F auto testF = f5(b);

class A {
public:
	A(){
		cout << "A constructing..." << endl;
	}
	~A(){
		cout << "A destructing..." << endl;
	}
};

class B {
private:
	static A data1;
	A data2;
public:
	B(){
		cout << "B constructing..." << endl;
	}
	~B(){
		cout << "B destructing..." << endl;
	}
};

A B::data1;

A f1(A b) {
	cout << "------after call------" << endl;
	A f;
	cout << "------before return------" << endl;
	return f;
}

A f2(A b) {
	cout << "------after call------" << endl;
	A f = b;
	cout << "------before return------" << endl;
	return f;
}

A f3(A b) {
	cout << "------after call------" << endl;
	static A f;
	cout << "------before return------" << endl;
	return f;
}

A& f4(A* b) {
	cout << "------after call------" << endl;
	A *f = b;
	cout << "------before return------" << endl;
	return *f;
}

A* f5(A& b) {
	cout << "------after call------" << endl;
	A* f = &b;
	cout << "------before return------" << endl;
	return f;
}

void work()
{
	cout << "=======entering work=======" << endl;
	A b;
	B t;
	
	A f[2];
	f[0] = b;
	
	//(1)
	cout << "------before call------" << endl;
	Answer1
	cout << "------after return------" << endl << endl;
	
	//(2)
	cout << "------before call------" << endl;
	Answer2
	cout << "------after return------" << endl << endl;
	
	//(3)
	cout << "------before call------" << endl;
	Answer3
	cout << "------after return------" << endl << endl;
	
	//(4)
	cout << "------before call------" << endl;
	Answer4
	cout << "------after return------" << endl << endl;
	
	//(5)
	cout << "------before call------" << endl;
	Answer5
	cout << "------after return------" << endl << endl;
	
	//(6)
	cout << "------before call------" << endl;
	Answer6
	cout << "------after return------" << endl << endl;
	
	cout << "=======exiting work=======" << endl;
}

int main() {
	cout << "=======entering main=======" << endl;
	work();
	cout << "=======exiting main=======" << endl;
	return 0;
}
