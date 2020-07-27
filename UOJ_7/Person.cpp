#include "Person.h"
#include <iostream>
using namespace std;

string Person::getName() const{
    return name;
}

string Person::getInfo() const{
    return name+" "+info;
}

Person::Person(const std::string& _name, const std::string& _info):name(_name),info(_info) {
    cout << "constructing Person " << name << endl;
}

Person::~Person() {
    cout << "destructing Person " << name << endl;
}