#pragma once
class Shape{
public:
	virtual double getArea()=0;
};

class Rectangle:public Shape{
	int w,h;
public:
	Rectangle(int,int);
	virtual double getArea();
};

class Circle:public Shape{
	int r;
public:
	Circle(int);
	virtual double getArea();
};