#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {								
    OccupationStrategy* op1;
    PayStrategy* op2;
public:
    Calculator(OccupationStrategy* _op1, PayStrategy* _op2): op1(_op1), op2(_op2) {};

    double getSalary(double base, double bonus, double level) {
        return op1->getSalary(base, bonus, level);
    }

    double pay(std::string name, double money) {
        return op2->pay(name, money);
    }
};