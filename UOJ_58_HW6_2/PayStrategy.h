#pragma once

class PayStrategy {
public:
    virtual float operate(float)=0;
};


class NormalStrategy : public PayStrategy {	
public:
    virtual float operate(float price) override {return price;}
};

class RebateStrategy : public PayStrategy {	
public:
    virtual float operate(float price) override {return 0.38*price;}
};

class ReturnStrategy : public PayStrategy {	
public:
    virtual float operate(float price) override {return price-10*(price>=25);}
};
