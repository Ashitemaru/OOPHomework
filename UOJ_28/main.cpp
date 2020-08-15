#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#include "shape.h"
#include "pointer.h"

int getAngles(Shape &x) {
	if (x.type() == "Rectangle") {
		return dynamic_cast<Rectangle &>(x).angles();
	} else if (x.type() == "Square") {
		return dynamic_cast<Square &>(x).angles();
	} else {
		return -1;
	}
}

int Shape::count = 0;

int main() {
	double *rp = new double[2] {4., 5.};
	double *sp = new double(3.);
	double *cp = new double(2.);

	auto *rect = new Rectangle(rp);
	auto *square = new Square(sp);
	auto *circle = new Circle(cp);

	cout << "Angles of *rect: " << getAngles(*rect) << endl;
	cout << "Angles of *square: " << getAngles(*square) << endl;
	cout << "Angles of *circle: " << getAngles(*circle) << endl;

	const int n_shapes = 3;
	Shape *shapes[n_shapes] = {rect, square, circle};
	for (int i = n_shapes - 1; i >= 0; --i)
		cout << shapes[i] << endl;
	for (int i = 0; i < 3; ++i)
		delete shapes[i];

	if (!AllocManager::check_released(rp))
		cout << "memory leak: *rp was not released" << endl;
	if (!AllocManager::check_released(sp))
		cout << "memory leak: *sp was not released" << endl;
	if (!AllocManager::check_released(cp))
		cout << "memory leak: *cp was not released" << endl;

	return 0;
}
