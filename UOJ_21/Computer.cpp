#include "Computer.h"
#include <cstring>
#include <string>
#include <tuple>
#include <iostream>

Computer::Computer(char* _name,int _store,int _price):name(_name,_name+strlen(_name)),store(_store),price(_price){};

std::string Computer::getName(){return name;}

bool Computer::operator<(const Computer& b) const{
    std::tuple<int,int> _1=std::make_tuple(store,price);
    std::tuple<int,int> _2=std::make_tuple(b.store,b.price);
    return _1<_2;
}

std::ostream& operator<<(std::ostream& out,const Computer& src){
    std::cout<<src.name<<"-num-"<<src.store<<"-price-"<<src.price;
    return out;
}

Computer& Computer::operator--(){
    if(store>0) --store;
    return *this;
}

Computer& Computer::operator++(){
    ++store;
    return *this;
}

void Computer::setPrice(int np){
    price=np;
    return;
}