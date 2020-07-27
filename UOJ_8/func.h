#pragma once

#include "Test.h"

Test f1(Test p){
    p.print("a");
    return std::move(p);
}

Test& f2(Test& p){
    p.print("b");
    return p;
}

void f3(Test& a,Test& b){
    Test c=std::move(a);
    return;
}