#include "multi.h"
#include "Value.h"
#include "Operator.h"

Multi::Multi(Value* _v1, Value* _v2): Operator(_v1, _v2) {};

int Multi::calc() {
    return getV1() * getV2();
}