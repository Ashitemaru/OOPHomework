#include "plus.h"
#include "Value.h"
#include "Operator.h"

Plus::Plus(Value* _v1, Value* _v2): Operator(_v1, _v2) {};

int Plus::calc() {
    return getV1() + getV2();
}