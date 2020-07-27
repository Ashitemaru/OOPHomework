#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"

class Calculator {								
    LoadStrategy* Loading;
    PayStrategy* Paying;
public:
    Calculator(LoadStrategy* op1,PayStrategy* op2):Loading(op1),Paying(op2){};
    
    float load(){return Loading->operate();}
    float pay(float price){return Paying->operate(price);}
};