#pragma once
#include <list>
#include <string>
#include <memory>
#include <iostream>

#include "CustomClass.h"

class Object;

class Content {
public:
	virtual void output(const std::ostream& out) {
		std::cout << "the operator is not supported for this type." << std::endl;
	}

	virtual void operator+=(Content&) = 0;
};

class IntContent: public Content {
private:
	int x;

public:
	IntContent(int _x): x(_x) {};

	virtual void output(const std::ostream& out) override {
		std::cout << x;
	}

	virtual void operator+=(Content& src) override {
		x += dynamic_cast<IntContent&>(src).x;
	}
};

class StringContent: public Content {
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {};

	virtual void output(const std::ostream& out) override {
		std::cout << x;
	}

	virtual void operator+=(Content& src) override {
		x += dynamic_cast<StringContent&>(src).x;
	}
};

class VectorContent: public Content {
private:
 	std::vector<Object> x;

public:
 	VectorContent(const std::vector<Object>& _x): x(_x) {}

	virtual void operator+=(Content& src) override {
		std::vector<Object> tmp = dynamic_cast<VectorContent&>(src).x;
		for (Object& i: tmp) x.push_back(i);
	}

	Object& operator[](int pos) {
		return x[pos];
	}
};

class CustomContent: public Content {
private:
	CustomClass x;

public:
	CustomContent(const CustomClass& _x): x(_x) {}

	virtual void operator+=(Content& src) override {};
};

class Object {
private:
	std::shared_ptr<Content> pt;

public:
	Object() {};

	Object(int x) {
		pt = std::shared_ptr<Content>(new IntContent(x)); // where to delete? maybe use std::shared_ptr?
	}

	Object(const std::string &x) {
		pt = std::shared_ptr<Content>(new StringContent(x));
	}

	Object(const std::vector<Object> &x) {
	 	pt = std::shared_ptr<Content>(new VectorContent(x));
	}

	Object(const CustomClass &x) {
		pt = std::shared_ptr<Content>(new CustomContent(x));
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}

	Object& operator+=(int y) {
		IntContent tmp(y);
		pt->operator+=(tmp);
		return *this;
	}

	Object& operator+=(const std::string &y) {
		StringContent tmp(y);
		pt->operator+=(tmp);
		return *this;
	}

	Object& operator[](int pos) {
		Content* ptr = pt.get();
		if (dynamic_cast<VectorContent*>(ptr) != nullptr) {
			return dynamic_cast<VectorContent*>(ptr)->operator[](pos);
		}
		Object tmp(1);
		return tmp;
	}
};
