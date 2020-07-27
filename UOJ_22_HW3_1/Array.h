#pragma once
#include "Node.h"
class Array{
    int len;
    Node* arr;
public:
    Array(int);
    Node& operator[](int);
    void update(int,int);
    void swap(int,int);
    void insert(int,int);
    ~Array();
};