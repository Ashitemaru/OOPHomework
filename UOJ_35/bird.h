#pragma once

#include <string>
#include <iostream>
#include "animal.h"

class Bird: public Animal
{
public:
	using Animal::Animal;
	~Bird() {
		std::cout << "bird " << name << " has gone." << std::endl;
	}
	void speak() {
		std::cout << "bird " << name << " is singing." << std::endl;
	}
	void swim() {
		std::cout << "bird " << name << " can't swim." << std::endl;
	}
};