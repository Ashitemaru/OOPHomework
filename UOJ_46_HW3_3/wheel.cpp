#include "wheel.h"

Wheel::Wheel(int num): number(num) {
	cout << "Building " << number << " wheels." << endl;
}

int Wheel::get_num() {
	return number;
}