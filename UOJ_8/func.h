#pragma once

#include "Test.h"

Test f1(Test a) {
    a.print("a");
    return a;
}

Test& f2(Test& b) {
    b.print("b");
    return b;
}

void f3(Test& a, Test& b) {
    Test tmp = move(a);
	a = move(b);
	b = move(tmp);
}