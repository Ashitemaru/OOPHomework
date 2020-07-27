#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int Example::obj_num=0;

Example::Example(int data) {
	// (3)
	obj_num++;
	num=obj_num;
	_data=data;
	cout<<"Example #"<<num<<" is created"<<endl;
}

void Example::getData() {
	// (4)
	cout<<"The data of Example #"<<num<<" is "<<_data<<endl;
}

Example::~Example() {
	// (5)
	cout<<"Example #"<<num<<" is destroyed"<<endl;
}