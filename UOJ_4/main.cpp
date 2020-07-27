#include <iostream>
using namespace std;

#define Option_A A testA = f1(b);
#define Option_B A testB = f2(b);
#define Option_C A testC = f3(b);
#define Option_D A testD = f3(b);
#define Option_E A& testE = f4(b);
#define Option_F A testF = f5(a[0]);

#include "MyAnswer.h"

class A {
public:
	A(){
		cout << "A constructing..." << endl;
	}
	~A(){
		cout << "A destructing..." << endl;
	}
	A(const A& src){
		cout<<"A copying..."<<endl;
	}
	A(A&& src){
		cout<<"A moving..."<<endl;
	}
} d;

class B {
	static A data1;
	A data2;
public:
	B(){
		cout << "B constructing..." << endl;
	}
	~B(){
		cout << "B destructing..." << endl;
	}
} e;

A B::data1;

A f1(A a) {
	cout << "------after call------" << endl;
	A b;
	cout << "------before return------" << endl;
	return b;
}

A f2(A& a) {
	cout << "------after call------" << endl;
	A b;
	cout << "------before return------" << endl;
	return b;
}

A f3(A a) {
	cout << "------after call------" << endl;
	static A b;
	cout << "------before return------" << endl;
	return b;
}

A& f4(A& a) {
	cout << "------after call------" << endl;
	A &b = a;
	cout << "------before return------" << endl;
	return b;
}

A f5(A* a) {
	cout << "------after call------" << endl;
	A* b = a;
	cout << "------before return------" << endl;
	return *b;
}

void work()
{
	cout << "=======entering work=======" << endl;
	A b;
	B f;

	A* a[2];
	a[0] = &b;
	a[1] = new A();
	cout<<"+++++++++++++++++++++++++++"<<endl;
	//(1)
	cout << "------before call------" << endl;
	Answer1
	cout << "------after return------" << endl << endl;
	cout<<"+++++++++++++++++++++++++++"<<endl;
	//(2)
	cout << "------before call------" << endl;
	Answer2
	cout << "------after return------" << endl << endl;
	cout<<"+++++++++++++++++++++++++++"<<endl;
	//(3)
	cout << "------before call------" << endl;
	Answer3
	cout << "------after return------" << endl << endl;
	cout<<"+++++++++++++++++++++++++++"<<endl;
	//(4)
	cout << "------before call------" << endl;
	Answer4
	cout << "------after return------" << endl << endl;
	cout<<"+++++++++++++++++++++++++++"<<endl;
	//(5)
	cout << "------before call------" << endl;
	Answer5
	cout << "------after return------" << endl << endl;
	cout<<"+++++++++++++++++++++++++++"<<endl;
	//(6)
	cout << "------before call------" << endl;
	Answer6
	cout << "------after return------" << endl << endl;
	cout<<"+++++++++++++++++++++++++++"<<endl;
	delete a[1];
	cout << "=======exiting work=======" << endl;
}

int main() {
	cout << "=======entering main=======" << endl;
	work();
	cout << "=======exiting main=======" << endl;
	return 0;
}

