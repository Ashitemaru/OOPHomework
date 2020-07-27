#pragma once

#include <string>
#include <iostream>
#include "animal.h"

class Fish: public Animal
{
public:
	using Animal::Animal;
	~Fish() {
		std::cout << "fish " << name << " has gone." << std::endl;
	}
	void speak() {
		std::cout << "fish " << name << " can't speak." << std::endl;
	}
	void swim() {
		std::cout << "fish " << name << " is swimming." << std::endl;
	}
};