#include "Shape.h"

Rectangle::Rectangle(int width,int height):w(width),h(height){};

double Rectangle::getArea(){return w*h;}

Circle::Circle(int radius):r(radius){};

double Circle::getArea(){return 3.14*r*r;}