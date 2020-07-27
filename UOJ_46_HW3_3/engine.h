#pragma once
#include <iostream>
#include <string>
using namespace std;

class Engine {
	string name;
public:
	Engine(string);
	string get_name();
};