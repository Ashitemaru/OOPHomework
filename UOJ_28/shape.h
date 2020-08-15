#include <string>

const double PI = 3.14;

class Shape {
protected:
	double *size;
	string id;
	string _type;
public:
	static int count;
	Shape(double *size, std::string type) : size(size), _type(type) {
		id = type + " " + to_string(count);
		count ++;
	}
	virtual double get_area() = 0;
	virtual string type() = 0;
	friend ostream &operator <<(ostream &out, Shape *w) {
		return out << w->id << ": " << w->get_area();
	}
	virtual ~Shape() {};
};

class Rectangle : public Shape {
public:
	Rectangle(double *size, bool type = true)
		: Shape(size, type ? "Rectangle" : "Square") {}
	virtual double get_area() { return size[0]*size[1]; }
	virtual string type() {
		return "Rectangle";
	}
	int angles() {
		return 4;
	}
	virtual ~Rectangle() {
		std::cout << type() + " " + _type << std::endl;
		if (type() == "Rectangle") {
			delete[] size;
		}
	}
};

class Square : public Rectangle {
public:
	Square(double *size)
		: Rectangle(size, false) {}
	virtual double get_area() { return size[0]*size[0]; }
	virtual string type() {
		return "Square";
	}
	virtual ~Square() {
		delete size;
	}
};

class Circle : public Shape {
public:
	Circle(double *size)
		: Shape(size, "Circle") {}
	virtual double get_area() { return PI*size[0]*size[0]; }
	virtual string type() {
		return "Circle";
	}
	virtual ~Circle() {
		delete size;
	}
};
