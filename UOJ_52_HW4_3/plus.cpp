#include "plus.h"

void PlusNode::calc(){OperationNodeTwo::calc();}

void PlusNode::UpdateValue(){
    value_=input1->value()+input2->value();
    return;
}

PlusNode::~PlusNode(){};