#include "Node.h"
#include "Array.h"

Array::Array(int _len):arr(new Node[_len]),len(_len){};

Node& Array::operator[](int pos){return arr[pos];}

void Array::update(int pos,int val_pos){
    arr[pos]=arr[val_pos];
    return;
}

void Array::swap(int l,int r){
    Node tmp=std::move(arr[l]);
    arr[l]=std::move(arr[r]);
    arr[r]=std::move(tmp);
    return;
}

void Array::insert(int pos,int val){
    for(int i=len-1;i>=pos+1;i--) arr[i]=std::move(arr[i-1]);
    arr[pos]=val;
    return;
}

Array::~Array(){
    delete[] arr;
}