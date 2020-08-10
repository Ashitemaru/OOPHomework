#include "minus.h"
#include "Value.h"
#include "Operator.h"

Minus::Minus(Value* _v1, Value* _v2): Operator(_v1, _v2) {};

int Minus::calc() {
    return getV1() - getV2();
}