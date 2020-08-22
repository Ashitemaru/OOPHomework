#include "nodes.h"

Constant::Constant(int v): val(v) {};

void Constant::changeVal(int v) {
    val = v;
    return;
}

int Constant::calc() {
    return val;
}

Print::Print(Value* v): prev(v) {};

int Print::calc() {
    return prev->calc();
}

Modify::Modify(Value* t, int v): tar(t), val(v) {};

int Modify::calc() {
    return tar->calc();
}