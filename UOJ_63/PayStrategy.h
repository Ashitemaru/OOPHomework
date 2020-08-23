#pragma once
#include <string>

class PayStrategy {
public:								
	virtual double pay(std::string name, double money) = 0;
};


class NormalStrategy : public PayStrategy {	
public:
	virtual double pay(std::string name, double money) override {
		return money;
	}
};

class SwiftStrategy : public PayStrategy {	
public:
	virtual double pay(std::string name, double money) override {
		if (money <= 10000) return money - 10;
		else if (money > 10000 && money <= 20000) return (1 - 1e-3) * money;
		else if (money > 20000) return money - 20;
		else return -1;
	}
};

class BitcoinStrategy : public PayStrategy {	
public:
	virtual double pay(std::string name, double money) override {
		return money - (8 + name.size()) * 0.01;
	}
};
