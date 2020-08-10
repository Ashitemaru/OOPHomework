#include "Operator.h"
Operator::Operator(Value *r1, Value *r2)
{
    v1 = r1;
    v2 = r2;
}
int Operator::getV1()
{
    return v1->calc();
}
int Operator::getV2()
{
    return v2->calc();
}
