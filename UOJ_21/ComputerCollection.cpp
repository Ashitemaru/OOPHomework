#include "ComputerCollection.h"
#include "Computer.h"
#include <iostream>
#include <algorithm>
#define MAX 100

std::istream& operator>>(std::istream& in,ComputerCollection& dst){
    char name[MAX]={'\0'};
    char store[MAX]={'\0'};
    char price[MAX]={'\0'};
    std::cin.ignore(MAX,'\n');
    std::cin.getline(name,MAX,'-');
    std::cin.getline(store,MAX,'-');
    std::cin>>price;
    dst.list.push_back(Computer(name,atoi(store),atoi(price)));
    return in;
}

std::ostream& operator<<(std::ostream& out,const ComputerCollection& src){
    for(int i=0;i<src.list.size();i++) out<<src.list[i]<<std::endl;
    return out;
}

Computer& ComputerCollection::operator[](std::string _name){
    for(int i=0;i<list.size();i++)
        if(_name==list[i].getName()) return list[i];
    return list[0];
}

bool my_cmp(const Computer& a,const Computer& b){
    return !a.operator<(b);
}

void ComputerCollection::sortByScore(){
    std::sort(list.begin(),list.end(),my_cmp);
    return;
}