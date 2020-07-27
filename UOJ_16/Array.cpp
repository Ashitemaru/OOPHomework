#include "Array.h"
#include "Node.h"

Array::Array(int len):list(new Node*[len]),len(len){
    for(int i=0;i<len;i++) list[i]=new Node();
};

Array::Array(const Array& src):list(new Node*[src.len]),len(src.len){
    for(int i=0;i<len;i++) list[i]=new Node(std::move(*src.list[i]));
}

Array::Array(Array&& src):list(new Node*[src.len]),len(src.len){
    for(int i=0;i<len;i++) list[i]=new Node(std::move(*src.list[i]));
}

Array::~Array(){
    for(int i=0;i<len;i++) delete list[i];
    delete[] list;
}

Node& Array::operator[](int loc){
    return *list[loc];
}

Array& Array::operator=(const Array& src){
    for(int i=0;i<len;i++) *list[i]=std::move(*src.list[i]);
    return *this;
}

Array& Array::operator=(Array&& src){
    for(int i=0;i<len;i++) *list[i]=std::move(*src.list[i]);
    return *this;
}