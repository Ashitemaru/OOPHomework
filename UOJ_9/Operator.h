#ifndef OPERATOR_H
#define OPERATOR_H
#include "Value.h"
class Operator : public Value
{
    Value *v1, *v2;
public:
    Operator(Value *r1, Value *r2);
    virtual int calc() = 0;
    int getV1();
    int getV2();
};

#endif
