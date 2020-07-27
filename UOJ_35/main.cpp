#include <iostream>
#include <string>

#include "animal.h"
#include "bird.h"
#include "fish.h"

using namespace std;

int main()
{
	string name1, name2;
	cin >> name1 >> name2;

	Animal *myBird = new Bird(name1), *myFish = new Fish(name2);

	myBird->action();
	myFish->action();

	delete myBird;
	delete myFish;

	return 0;
}