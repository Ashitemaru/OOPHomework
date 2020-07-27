#pragma once

#include "operation.h"

class MinusNode: public OperationNodeTwo{
public:
    using OperationNodeTwo::OperationNodeTwo;
    virtual void calc() override;
    virtual void UpdateValue() override;
    virtual ~MinusNode();
};