#pragma once

#include "Value.h"

class Constant: public Value {
    int val;
public:
    Constant(int);
    virtual int calc() override;
    void changeVal(int);
    virtual ~Constant() {};
};

class Print: public Value {
    Value* prev;
public:
    Print(Value*);
    virtual int calc() override;
    virtual ~Print() {};
};

class Modify: public Value {
    Value* tar;
    int val;
public:
    Modify(Value*, int);
    virtual int calc() override;
    virtual ~Modify() {};
};