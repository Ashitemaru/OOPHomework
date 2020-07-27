#pragma once

#include "Node.h"

class Array{
    Node** list;
    int len;
public:
    Array(int);
    Array(const Array&);
    Array(Array&&);
    ~Array();
    Node& operator[](int);
    Array& operator=(const Array&);
    Array& operator=(Array&&);
};