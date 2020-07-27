#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

class LoadStrategy {
public:
    virtual float operate()=0;
};


class NumberLoadStrategy : public LoadStrategy {	
public:
    virtual float operate() override {
        std::string tmp;
        std::cin>>tmp;
        return std::stod(tmp);
    }
};

class WordLoadStrategy : public LoadStrategy {
public:
    virtual float operate() override {
        std::map<std::string,int> word_to_num={
            std::make_pair("zero",0),
            std::make_pair("one",1),
            std::make_pair("two",2),
            std::make_pair("three",3),
            std::make_pair("four",4),
            std::make_pair("five",5),
            std::make_pair("six",6),
            std::make_pair("seven",7),
            std::make_pair("eight",8),
            std::make_pair("nine",9)
        };
        std::vector<std::string> numbers;
        std::string tmp;
        while(tmp!="#"){
            std::cin>>tmp;
            numbers.push_back(tmp);
        }
        int n=numbers.size();
        float sum=0;
        for(int i=0;i<n-1;i++) sum+=std::pow(10,n-2-i)*word_to_num[numbers[i]];
        return sum;
    }
};
