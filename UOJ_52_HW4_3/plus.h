#pragma once

#include "operation.h"

class PlusNode: public OperationNodeTwo{
public:
    using OperationNodeTwo::OperationNodeTwo;
    virtual void calc() override;
    virtual void UpdateValue() override;
    virtual ~PlusNode();
};