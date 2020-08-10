#pragma once

#include "Operator.h"
#include "Value.h"

class Multi: public Operator {
public:
    Multi(Value*, Value*);
    virtual int calc() override;
};