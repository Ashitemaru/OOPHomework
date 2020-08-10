#pragma once

#include "Operator.h"
#include "Value.h"

class Minus: public Operator {
public:
    Minus(Value*, Value*);
    virtual int calc() override;
};