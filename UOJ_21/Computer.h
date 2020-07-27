#pragma once

#include <string>

class Computer{
    std::string name;
    int store;
    int price;
public:
    Computer(char*,int,int);
    std::string getName();
    bool operator<(const Computer&) const;
    friend std::ostream& operator<<(std::ostream&,const Computer&);
    Computer& operator--();
    Computer& operator++();
    void setPrice(int);
};