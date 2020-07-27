#include <iostream>
#include "Shape.h"

using namespace std;

int main() {
    double width,height;
    cin>>width>>height;
    Shape* rectangle = new Rectangle(width,height);
    cout<<rectangle->getArea()<<endl;

    double radius;
    cin>>radius;
    Shape* circle = new Circle(radius);
    cout<<circle->getArea()<<endl;

    delete rectangle;
    delete circle;
    return 0;
}