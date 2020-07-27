#include "minus.h"

void MinusNode::calc(){OperationNodeTwo::calc();}

void MinusNode::UpdateValue(){
    value_=input1->value()-input2->value();
    return;
}

MinusNode::~MinusNode(){};